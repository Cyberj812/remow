# ReMow Core - KiCad project

KiCad 8 project for the **ReMow Core** controller board (Tier 1).

## Files
- `remow-core.kicad_pro` - project file.
- `remow-core.kicad_sch` - block-level schematic scaffold: power input/rectifier/buffer, DC-DC rails, ESP32-S3 MCU, drive + steering H-bridge drivers, blade-kill relay, e-stop loop, tilt/lift, RC receiver, and the J8 expansion header. Nets are shown as labeled buses (`VBAT_12V`, `+5V`, `+3V3`, `DRIVE_PWM`, `STEER_PWM`, `BLADE_KILL`, `ESTOP_LOOP`, etc.).
- `remow-core.kicad_pcb` - empty placeholder; layout begins in Phase 2 (see [../../docs/roadmap.md](../../docs/roadmap.md)).

## Scope / status
This is an early **scaffold**, not a fabrication-ready design. It captures the board's functional blocks and signal/power buses so component symbols and a real layout can be added incrementally. See [../../docs/electrical.md](../../docs/electrical.md) for the connector map, pinouts, and power budget that this schematic implements.

## Opening
Open `remow-core.kicad_pro` in KiCad 8 (or newer). The schematic opens in Eeschema; the PCB is intentionally empty.
