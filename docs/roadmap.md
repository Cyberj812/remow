# Roadmap

A phased plan from concept to a safe, upgradeable product. Each phase gates on the previous one - especially the safety milestones.

```mermaid
flowchart LR
  P0["P0 Concept & docs"] --> P1["P1 Bench safety rig"]
  P1 --> P2["P2 Core RC prototype"]
  P2 --> P3["P3 Tier 1 field trials"]
  P3 --> P4["P4 Nav autonomy"]
  P4 --> P5["P5 Vision safety"]
  P5 --> P6["P6 Productization"]
```

## Phase 0 - Concept & documentation (this repo)
- System architecture, tier definitions, mechanical/electrical/software plans, BOM.
- KiCad Core schematic scaffold.
- **Exit:** design reviewed; risks understood.

## Phase 1 - Bench safety rig
- Build the safety supervisor: e-stop loop, tilt/lift, RC-loss watchdog, blade-kill relay.
- Validate every fault case (button, unplug, tilt, RC loss, power loss) cuts blade + drive.
- Wheels-off, blade-removed test stand.
- **Exit:** all fault cases reliably force a safe state on the bench.

## Phase 2 - Core RC prototype (Tier 1)
- Fabricate the Core PCB; install ESP32-S3 firmware (safety + motion tasks).
- Mount alternator/PMA + buffer battery; verify power budget under load.
- Install drive-engagement actuator + steering (Option A) on a donor mower.
- Handheld remote link (ELRS or ESP-NOW) with failsafe.
- **Exit:** drive it by remote with blade removed, then with blade in a controlled area.

## Phase 3 - Tier 1 field trials
- Real mowing by remote control in a fenced test yard.
- Tune speed modulation, steering response, thermal/vibration robustness, IP sealing.
- Refine BOM and per-model adapter kit.
- **Exit:** reliable, repeatable remote mowing; documented setup for one mower model.

## Phase 4 - Nav autonomy (Tier 2)
- Add GNSS/RTK + IMU + wheel odometry; implement EKF pose.
- App: draw area, no-go zones, geofence; coverage planner.
- Autonomous mowing within boundary with geofence enforcement and return-to-start.
- **Exit:** hands-off coverage of a mapped area with geofence stop verified.

## Phase 5 - Vision safety (Tier 3)
- Raspberry Pi + camera + ToF/ultrasonic; object/person/pet detection.
- Wire perception events as high-priority vetoes to the Core; validate safety stop.
- **Exit:** person/pet in path reliably triggers stop + blade disengage in testing.

## Phase 6 - Productization
- Per-model adapter kits and install guides.
- Manufacturable PCB revisions, enclosures, wiring harnesses.
- Documentation, safety labeling, and compliance review.
- Bundle pricing (Core / Nav / Vision / Autonomy bundle).

## Cross-cutting workstreams
- **Safety validation** at every phase - never regress the fault-stop guarantees.
- **Compatibility matrix** - track supported mower models and required adapters.
- **Firmware CI** - build/test the ESP32 image and module protocol.
