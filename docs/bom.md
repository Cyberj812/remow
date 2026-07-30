# Bill of Materials

Indicative bill of materials per tier. Prices are rough hobbyist/small-batch estimates in USD and will vary by supplier, quantity, and mower model. Quantities and exact parts are placeholders to be refined during prototyping.

## Tier 1 - ReMow Core (RC)

| # | Item | Qty | Notes | Est. $ |
|---|------|----:|-------|-------:|
| 1 | ESP32-S3 module (WROOM/WROVER) | 1 | Main MCU | 8 |
| 2 | ReMow Core PCB + passives | 1 | Custom board (see KiCad) | 20 |
| 3 | Dual H-bridge motor driver | 1 | Drive + steering actuators | 10 |
| 4 | Linear actuator or metal-gear servo (drive engage) | 1 | Spring-return | 25 |
| 5 | Linear actuator or high-torque servo (steering) | 1 | With position feedback | 30 |
| 6 | Steering linkage / tie-rod / knuckle kit | 1 | Fabricated per model | 25 |
| 7 | Alternator / PMA (150-250 W class) + bracket + belt | 1 | Engine-driven | 45 |
| 8 | Bridge rectifier + TVS + bulk caps | 1 | Load-dump protection | 8 |
| 9 | LiFePO4 4S buffer battery + BMS | 1 | ~12.8V | 40 |
| 10 | DC-DC buck regulators (5V, 3.3V) | 2 | Rails | 8 |
| 11 | Blade-kill relay (automotive) | 1 | Fail-safe wiring | 5 |
| 12 | Hardware e-stop button (NC) | 1 | Safety loop | 8 |
| 13 | Tilt/lift switch + accelerometer | 1 | Safety | 6 |
| 14 | RC receiver (ELRS) or 2nd ESP32 (ESP-NOW) | 1 | Control link | 20 |
| 15 | Handheld remote (ESP32 TX or ELRS transmitter) | 1 | Operator control | 35 |
| 16 | IP-rated enclosure + vibration mounts + glands | 1 | Weatherproofing | 20 |
| 17 | Subframe stock, fasteners, connectors, wiring | 1 | Fabrication | 30 |
| | **Tier 1 subtotal** | | | **~343** |

> The README's "~$150-200" reflects a stripped baseline (reusing salvaged actuators/alternator, minimal enclosure). The table above is a fuller new-parts estimate; actual cost lands between depending on sourcing.

## Tier 2 - ReMow Nav (add-on)

| # | Item | Qty | Notes | Est. $ |
|---|------|----:|-------|-------:|
| 1 | GNSS receiver (RTK-capable) + antenna | 1 | e.g. u-blox ZED-F9P class | 90 |
| 2 | 9-DoF IMU | 1 | Sensor fusion | 12 |
| 3 | Wheel encoders + mounts | 2 | Odometry | 20 |
| 4 | Nav module PCB + MCU | 1 | Or shared with Vision Pi | 25 |
| 5 | Antenna mast + enclosure | 1 | | 15 |
| | **Tier 2 subtotal** | | | **~162** |

> A non-RTK GNSS lowers cost significantly (~$20 module) at the expense of accuracy; RTK (or NTRIP corrections) is recommended for tidy coverage.

## Tier 3 - ReMow Vision (add-on)

| # | Item | Qty | Notes | Est. $ |
|---|------|----:|-------|-------:|
| 1 | Raspberry Pi (Pi 5 or Pi Zero 2 W) | 1 | Perception compute | 50 |
| 2 | Camera module | 1 | Wide FOV | 20 |
| 3 | ToF sensor(s) | 1-2 | Range | 20 |
| 4 | Ultrasonic sensors | 2-4 | Close-range backup | 12 |
| 5 | Vision enclosure + camera pod + mounts | 1 | Weatherized | 20 |
| 6 | Wiring / UART harness to Core | 1 | J8 expansion | 8 |
| | **Tier 3 subtotal** | | | **~130** |

## Optional / advanced

| Item | Notes | Est. $ |
|------|-------|-------:|
| Option C: dual BLDC wheel motors + drivers + wheels | Skid-steer conversion (replaces single-axle drive) | 250+ |
| RTK base station | For own correction source | 200+ |
| Larger alternator / battery | Required for Option C loads | 100+ |

## Notes

- All estimates exclude tools, shipping, and the mower itself.
- Reusing salvaged parts (car alternator, surplus actuators, spare Pi) can cut cost substantially.
- Safety-critical parts (e-stop, relay, BMS) should be bought new from reputable suppliers - do not skimp.
