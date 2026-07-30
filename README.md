# ReMow

**Convert your existing self-propelled lawn mower into a remote-controlled and autonomous robot mower.**

ReMow is a modular, bolt-on kit that reuses your mower's deck, wheels, and self-propel drive. Instead of buying a $2,000+ robot mower, you add a controller module, a power source (an existing battery tap on electric mowers, or a small engine-driven alternator on gas mowers), a steering actuator, and control of the existing self-propel drive. Start with basic remote control and upgrade to mapped autonomous routes and camera-based object detection over time.

ReMow targets **both battery-electric self-propelled mowers (the flagship, easiest path) and gas self-propelled mowers**. See [which mowers are ideal](docs/mower-compatibility.md) and the [universal Fit Kit](docs/install-kit.md).

> [!WARNING]
> **ReMow controls a machine with an exposed, high-speed rotating steel blade.** This project is an early-stage design concept for experienced makers. An unattended or malfunctioning powered mower can cause severe injury or death to people and animals, and significant property damage. Every tier is designed around layered safety cutoffs (hardware e-stop, blade-engagement kill, tilt/lift kill, RC-loss failsafe, geofence). Do not operate near people or pets. You are solely responsible for building, testing, and operating any device based on these plans. See the [disclaimer](#disclaimer).

## Why ReMow

- **Reuse what you own.** Keep the mower's deck, wheels, drive, and (on electric mowers) its battery.
- **Tiered and upgradeable.** One common controller board; buy add-on modules as you go.
- **Open.** Documentation, schematics (KiCad), and firmware scaffold all in one repo.

## Product tiers

| Tier | Name | Capability | Indicative price* |
|------|------|-----------|-------------------|
| 1 | **ReMow Core** | Engine-driven power + RC "drive it yourself" robot, full safety stack | ~$150-200 |
| 2 | **ReMow Nav** (add-on) | GPS/RTK + IMU + odometry, mappable routes, phone/web app | ~$150 |
| 3 | **ReMow Vision** (add-on) | Raspberry Pi + camera + ToF/ultrasonic object detection & avoidance | ~$200+ |

\*Indicative BOM cost ranges, not retail pricing. See [docs/product-tiers.md](docs/product-tiers.md).

The **upgrade path** is built into the hardware: the ReMow Core board exposes a power + UART/I2C/CAN expansion connector so Nav and Vision plug in without replacing the Core.

## Documentation

- [Product tiers & upgrade path](docs/product-tiers.md)
- [Mower compatibility: ideal models & scoring rubric](docs/mower-compatibility.md)
- [Universal Fit Kit: easy install](docs/install-kit.md)
- [System architecture](docs/architecture.md)
- [Mechanical: handle removal, mounting, steering](docs/mechanical.md)
- [Electrical: power (battery tap / alternator), wiring, pinouts, budget](docs/electrical.md)
- [Software: firmware, RC protocol, navigation, vision](docs/software.md)
- [Bill of materials (per tier)](docs/bom.md)
- [Roadmap](docs/roadmap.md)

## Hardware design files

- KiCad project for the ReMow Core controller board: [hardware/kicad/](hardware/kicad/)

## Firmware

- ESP32 firmware scaffold and build notes: [firmware/](firmware/)

## Repository layout

```
remow/
├── README.md
├── LICENSE
├── docs/            # Full layout plan (tiers, compatibility, Fit Kit, architecture, mechanical, electrical, software, BOM, roadmap)
├── hardware/kicad/  # ReMow Core controller schematic (KiCad)
├── firmware/        # ESP32 firmware scaffold (PlatformIO)
└── images/          # Diagrams and renders
```

## Status

Early design concept. Nothing here has been built or safety-validated. Contributions and review welcome.

## Disclaimer

This repository contains conceptual design documentation and reference files only. It is provided "as is", without warranty of any kind. Building a powered, self-driving machine with an exposed cutting blade is inherently dangerous and may be subject to local laws and regulations. The authors and contributors accept no liability for any injury, death, or damage resulting from the use of, or reliance on, any material in this repository. Consult qualified professionals before building.

## License

[MIT](LICENSE)
