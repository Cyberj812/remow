// ReMow Core firmware - SCAFFOLD ONLY.
//
// This is a non-functional placeholder that mirrors the task/safety
// architecture in docs/software.md. It intentionally does not drive any
// hardware. Do NOT flash this to a mower-connected board expecting motion or
// safety behavior - the safety supervisor and drivers are stubs.
//
// Priority order (highest wins, can veto):
//   1. Hardware safety cutoff (not software)
//   2. Vision safety stop
//   3. RC-loss failsafe
//   4. Manual remote commands
//   5. Nav autonomy waypoints

#include <Arduino.h>

#ifndef RC_LINK_LOSS_TIMEOUT_MS
#define RC_LINK_LOSS_TIMEOUT_MS 500
#endif

enum class Mode { SafeStop, Manual, Auto };

struct MotionCmd {
  float drive = 0.0f;  // -1..1 (engagement/speed request)
  float steer = 0.0f;  // -1..1
  bool  blade = false; // blade engage request
};

static volatile bool     g_estopLoopClosed = false; // NC loop: true when safe
static volatile bool     g_tiltOk          = false;
static volatile uint32_t g_lastRcMs        = 0;
static volatile bool     g_visionStop      = false;
static Mode              g_mode            = Mode::SafeStop;

// --- Safety supervisor -------------------------------------------------------
// In real hardware this path is also implemented in dedicated logic that can
// cut the blade-kill relay and drive-enable independently of this firmware.
static bool safeToRun() {
  const bool rcAlive = (millis() - g_lastRcMs) < RC_LINK_LOSS_TIMEOUT_MS;
  return g_estopLoopClosed && g_tiltOk && rcAlive && !g_visionStop;
}

static void forceSafeStop() {
  // TODO: de-energize blade-kill relay, drop drive enable, center/relax steering.
}

// --- Command arbitration -----------------------------------------------------
static MotionCmd arbitrate(const MotionCmd& remote, const MotionCmd& nav) {
  if (!safeToRun()) return MotionCmd{}; // all zero + blade off
  // Manual overrides Nav; Vision/RC/e-stop already handled by safeToRun().
  return (g_mode == Mode::Auto) ? nav : remote;
}

// --- Task stubs (would be FreeRTOS tasks in the real firmware) ---------------
static void safetyTask()   { /* poll e-stop, tilt, RC watchdog, faults */ }
static void controlTask()  { /* closed-loop steer + drive PWM */ }
static void rcLinkTask()   { /* decode ELRS/ESP-NOW; update g_lastRcMs */ }
static void expansionTask(){ /* UART/I2C/CAN to Nav/Vision; detect module ID */ }
static void telemetryTask(){ /* publish battery/faults/mode over Wi-Fi/BLE */ }

void setup() {
  Serial.begin(115200);
  Serial.println("ReMow Core scaffold - not functional. See docs/software.md.");
  // TODO: init GPIO, drivers, safety inputs, RC link, expansion bus.
}

void loop() {
  safetyTask();
  rcLinkTask();
  expansionTask();

  if (!safeToRun()) {
    forceSafeStop();
  } else {
    MotionCmd remote{}, nav{};
    MotionCmd cmd = arbitrate(remote, nav);
    (void)cmd;
    controlTask();
  }

  telemetryTask();
  delay(10);
}
