# Mower Compatibility

Which self-propelled mowers is ReMow ideal for? This guide defines a **scoring rubric** and applies it to real, current models to produce a ranked shortlist. The short version: **battery-electric self-propelled mowers are the flagship target** (easiest and safest to convert), with cable/lever gas mowers that have an independent blade brake as a strong second track.

> Figures below are indicative and drawn from manufacturer/retailer specs at time of writing; verify the exact model/trim before buying, since drive and blade systems vary within a product line.

## The two platforms

ReMow candidates fall into two very different conversion worlds.

### Battery-electric self-propelled (flagship target)
Examples: EGO 56V `LM2135SP`, Ryobi 40V HP `RY401170`, Greenworks 60V/80V.

- **Onboard power already exists** - a large lithium pack (e.g. EGO 56V ~420 Wh, Ryobi 40V, Greenworks 60/80V). No alternator needed; ReMow taps existing power.
- **Drive is already electronic** - brushless drive motor + controller with variable "walking pace" tech (EGO Touch Drive, Ryobi Smart Trek, Greenworks SmartCut). Propulsion can be commanded electronically instead of pulling a cable.
- **Blade cutoff is instant and independent** - the electric blade motor can be de-energized in milliseconds without affecting drive. This is the single biggest safety advantage.
- **No gas, no exhaust heat, less vibration** - friendlier environment for electronics.

### Gas self-propelled (second track, original alternator concept)
Examples: Toro Recycler Personal Pace, Honda HRX (Select Drive / Cruise Control), Troy-Bilt XP InStep, Cub Cadet SC900, Toro TimeMaster 30".

Two features decide how convertible a gas mower is:

- **Blade engagement:**
  - **Blade Brake Clutch (BBC) / Roto-Stop** (Toro Blade Stop System, Honda HRX Roto-Stop) stops the blade **while the engine keeps running** - ideal for a robot that needs to pause cutting without restarting.
  - **Flywheel-brake bail** (cheaper mowers) couples blade and engine - releasing the bail kills the engine. Stopping the blade means restarting the mower. Poor fit for autonomy.
- **Drive control:** cable/lever systems (Toro Personal Pace reactive handle, Honda Select Drive dial, Troy-Bilt InStep) and Honda's hydrostatic **Cruise Control lever** are all actuatable with a cable interposer (see [install-kit.md](install-kit.md)). Gas mowers additionally need the **alternator power module** (see [electrical.md](electrical.md)).

## Compatibility scoring rubric

Score each axis 1-5 (5 = best for conversion), multiply by the weight, and sum. Max weighted score = 100.

| Axis | Weight | 5 (ideal) | 3 (workable) | 1 (poor) |
|------|:------:|-----------|--------------|----------|
| Blade-cutoff independence | 5 | Electric blade motor (instant e-cut) | BBC / Roto-Stop (blade stops, engine runs) | Flywheel-brake bail (blade+engine coupled) |
| Drive controllability | 4 | Electronic drive controller tap | Single cable/lever (Personal Pace, Select Drive) | Stiff/hydrostatic lever or complex linkage |
| Onboard power for electronics | 4 | Large battery pack present | Small 12V/charging present | None (must add full alternator) |
| Steering feasibility | 3 | Light, free front wheels, good wheelbase | Moderate weight, some linkage work | Heavy / wide / hard-to-steer axle |
| Mounting & space | 2 | Standard ~1 in round-tube handle, foldable, deck room | Nonstandard tube, tight space | No clean mount points |
| Weight & deck size | 2 | Light, 20-21 in deck | Mid weight, 22 in deck | Heavy, 23-30 in deck |
| Ubiquity / parts & resale | 1 | Very common, easy parts | Common | Rare / discontinued |

Interpretation: **>=80 excellent** (flagship), **65-79 good**, **50-64 workable with effort**, **<50 not recommended**.

## Ranked model matrix

Scores are ReMow conversion-suitability estimates using the rubric above (not product quality ratings).

| Rank | Model | Platform | Drive | Blade cutoff | Weight | Est. score | Verdict |
|:----:|-------|----------|-------|--------------|:------:|:----------:|---------|
| 1 | EGO POWER+ `LM2135SP` (56V) | Battery | Touch Drive (electronic, variable) | Electric e-cut | ~62 lb | ~92 | Flagship |
| 2 | Ryobi 40V HP `RY401170` (RWD) | Battery | Smart Trek (electronic, variable) | Electric e-cut | ~65 lb | ~90 | Flagship |
| 3 | Greenworks 80V 21" self-propelled | Battery | SmartCut (electronic, load-sensing) | Electric e-cut | ~60 lb | ~89 | Flagship |
| 4 | Ryobi 40V HP `RY401180` AWD | Battery | AWD electronic | Electric e-cut | ~70 lb | ~84 | Excellent (AWD aids traction, adds complexity) |
| 5 | Toro Recycler w/ Blade Stop System + Personal Pace | Gas | Personal Pace (reactive cable) | BBC (blade stops, engine runs) | ~77-95 lb | ~74 | Best gas pick |
| 6 | Honda `HRX217VKA` | Gas | Select Drive (variable, dial + cable) | Roto-Stop (blade stops, engine runs) | ~87 lb | ~72 | Best gas pick (heavier) |
| 7 | Honda `HRX217HYA` | Gas | Hydrostatic Cruise Control (lever) | Roto-Stop | ~97-100 lb | ~66 | Good; heavy, hydrostatic lever |
| 8 | Troy-Bilt XP `TB-WC23` | Gas | InStep RWD (variable cable) | Flywheel-brake bail (typical) | ~90 lb+ | ~55 | Workable; 23 in deck, no independent blade brake |
| 9 | Cub Cadet `SC900` | Gas | MySpeed (variable cable) | Flywheel-brake bail (typical) | heavy | ~54 | Workable; 23 in deck |
| 10 | Toro TimeMaster 30" Personal Pace | Gas | Personal Pace (cable) | BBC on some trims | very heavy | ~48 | Not recommended (30 in, heavy, big turning radius) |

## Ideal picks

- **Battery flagship:** EGO `LM2135SP`, Ryobi 40V HP `RY401170`, or Greenworks 80V. Choose based on which battery ecosystem you already own. These give electronic drive + instant blade e-cut + onboard power - the safest, cheapest ReMow build.
- **Gas best-in-class:** a Toro Recycler with the **Blade Stop System** and Personal Pace, or a Honda `HRX217VKA` with **Roto-Stop**. The independent blade brake is the feature that makes a gas mower robot-friendly.

## Avoid

- **Cheap FWD, single-speed, flywheel-brake mowers.** Front-wheel drive loses traction as the bag fills or on slopes, single-speed drive gives no fine speed control, and the coupled blade/engine means the mower cannot pause cutting without stalling. These score below 50 and are not recommended.
- **Very large decks (28-30 in) and heavy mowers.** Turning radius, weight, and steering loads make autonomy and safety harder.

## What "ideal" means for the kit

The rubric directly drives the **ReMow Fit Kit** configurator: your mower's platform, blade type, and drive type select which power module, blade-safety profile, and cable/drive adapters ship. See [install-kit.md](install-kit.md).
