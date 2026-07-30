# ReMow Firmware

PlatformIO project scaffold for the **ReMow Core** ESP32-S3 firmware.

> [!WARNING]
> This is a **non-functional scaffold**. It compiles and mirrors the architecture in [../docs/software.md](../docs/software.md), but it does not implement real motor control or safety behavior. Do not flash it to a mower-connected board expecting it to be safe.

## Layout
- `platformio.ini` - build config targeting `esp32-s3-devkitc-1` (Arduino framework).
- `src/main.cpp` - placeholder mirroring the safety supervisor, command arbiter, and task structure.

## Build
```bash
pip install platformio      # if needed
pio run                     # build
pio run -t upload           # flash (once real hardware/firmware exists)
pio device monitor          # serial monitor @115200
```

## Planned components (per tier)
- **Core (ESP32-S3):** safety task, motion control, RC link (ELRS/ESP-NOW), expansion bus, telemetry.
- **Nav module:** EKF localization + coverage planner (separate component/service).
- **Vision module (Raspberry Pi):** perception service emitting stop/veto events over UART.

See [../docs/software.md](../docs/software.md) for the full software design and [../docs/roadmap.md](../docs/roadmap.md) for the implementation phases.
