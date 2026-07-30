# System Architecture

ReMow is organized into four subsystems: **power**, **control**, **actuation**, and **perception/navigation**. The ReMow Core board ties them together and enforces safety independently of the higher-level autonomy.

## High-level block diagram

```mermaid
flowchart TD
  subgraph mower [Existing Mower]
    Engine[Gas Engine]
    Deck[Blade Deck]
    Drive[Self-propel Transmission]
    FrontWheels[Front Wheels]
  end

  subgraph power [Power Subsystem]
    Alt[Alternator/Dynamo]
    Rect[Rectifier + Regulator]
    Batt[LiFePO4 Buffer Battery]
    Rails[5V / 3.3V / 12V Rails]
  end

  subgraph core [ReMow Core]
    ESP[ESP32-S3 MCU]
    Safety[Safety Supervisor]
    DriveDrv[Drive Actuator Driver]
    SteerDrv[Steering Actuator Driver]
    BladeKill[Blade-Kill Relay]
  end

  Remote[Handheld RC Remote]

  subgraph addons [Add-on Modules]
    Nav[Nav: GNSS + IMU + Odometry]
    Vision[Vision: Raspberry Pi + Camera + ToF]
  end

  Engine -->|belt| Alt
  Engine --- Deck
  Engine --- Drive
  Alt --> Rect --> Batt --> Rails
  Rails --> ESP
  Rails --> DriveDrv
  Rails --> SteerDrv
  Rails --> Nav
  Rails --> Vision

  Remote -.RF link.-> ESP
  ESP --> DriveDrv --> Drive
  ESP --> SteerDrv --> FrontWheels
  ESP --> Safety
  Safety --> BladeKill --> Engine
  ESP <-->|UART/I2C/CAN| Nav
  ESP <-->|UART| Vision
```

## Power flow

```mermaid
flowchart LR
  Engine[Engine crank / blade shaft] -->|belt or shaft coupling| Alt[Alternator 12-14V AC/DC]
  Alt --> Bridge[Bridge rectifier + smoothing]
  Bridge --> Charger[LiFePO4 charge controller]
  Charger --> Batt[LiFePO4 buffer 4S ~12.8V]
  Batt --> Buck12[12V rail]
  Batt --> Buck5[5V buck]
  Batt --> Buck33[3.3V buck]
  Buck12 --> Actuators[Actuators / relays]
  Buck5 --> Pi[Vision Pi / sensors]
  Buck33 --> MCU[ESP32 + logic]
```

The buffer battery decouples electrical load from engine RPM so actuators and logic get stable power even at idle or during transient blade loading. See [electrical.md](electrical.md) for the power budget.

## Control loop and safety hierarchy

Safety is enforced by a **supervisor** path that can cut the blade and stop drive **independently** of the ESP32 application logic and any autonomy module. Higher tiers can only *request* motion; they can never override a safety cutoff.

```mermaid
flowchart TD
  subgraph highlevel [High-level intent]
    RemoteIn[Remote commands]
    NavIn[Nav autonomy]
    VisionIn[Vision avoidance]
  end

  Arb[Command Arbiter on ESP32]
  RemoteIn --> Arb
  NavIn --> Arb
  VisionIn -->|veto / stop| Arb

  Arb --> MotionCtl[Motion controller]
  MotionCtl --> DriveOut[Drive actuator]
  MotionCtl --> SteerOut[Steering actuator]

  subgraph safety [Independent Safety Supervisor]
    Estop[Hardware E-stop]
    Tilt[Tilt / lift sensor]
    RCLoss[RC-loss watchdog]
    LowBatt[Low-battery / fault]
  end

  Estop --> Cut{Cutoff}
  Tilt --> Cut
  RCLoss --> Cut
  LowBatt --> Cut
  Cut -->|force safe| DriveOut
  Cut -->|kill| BladeRelay[Blade-engagement relay]
```

**Priority order (highest first):** hardware e-stop -> tilt/lift kill -> RC-loss failsafe -> Vision safety stop -> Nav autonomy -> remote commands.

## Data flow between modules

```mermaid
sequenceDiagram
  participant R as Remote / App
  participant E as ESP32 Core
  participant N as Nav module
  participant V as Vision (Pi)
  R->>E: drive/steer/blade commands (RF)
  N->>E: pose estimate + waypoint (UART/CAN)
  V->>E: obstacle/person events (UART)
  E->>E: arbitrate + apply safety
  E->>N: state, odometry ticks
  E->>V: state, enable/disable
  E-->>R: telemetry (battery, faults, position)
```

## Module responsibilities

- **ESP32-S3 Core:** real-time motor/steering control, RC link, command arbitration, safety supervision, telemetry. Deterministic, always-on.
- **Nav module:** sensor fusion (GNSS + IMU + wheel odometry) -> pose; path planning and coverage; geofence. Sends waypoints, never touches actuators directly.
- **Vision module (Pi):** perception only. Emits obstacle/person events that the Core treats as high-priority vetoes. Never commands motion directly.
