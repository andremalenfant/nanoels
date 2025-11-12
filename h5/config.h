/* Change values in this section to suit your hardware. */

#define NEXTION_BAUDRATE 115200
//#define NEXTION_BAUDRATE 250000
//#define NEXTION_BAUDRATE 921600

#define ENCODER_SINGLE 1
#define ENCODER_HALF 2
#define ENCODER_FULL 4

// Define your hardware parameters here.
const int ENCODER_PPR = 600; // 1200 step spindle optical rotary encoder. Fractional values not supported.
const int ENCODER_BACKLASH = 0; // Numer of impulses encoder can issue without movement of the spindle
const int ENCODER_TYPE = ENCODER_SINGLE; // 1 - Single (A channel falling edge count only),
                            // 2 - halfQuad (A channel falling and rising edges count)
                            // 4 - fullQuad (falling and rising edges count on both channels)
const int ENCODER_SPINDLE_RATIO = 4;

const long MOTOR_SCREW_RATIO_Z = 3;

// Main lead screw (Z) parameters.
const long SCREW_Z_DU = 20000 / MOTOR_SCREW_RATIO_Z; // 2mm --4mm SFU1204 ball screw in deci-microns (10^-7 of a meter)
const long MOTOR_STEPS_Z = 800;
const long SPEED_START_Z = MOTOR_STEPS_Z; // Initial speed of a motor, steps / second.
const long ACCELERATION_Z = 20 * MOTOR_STEPS_Z; // Acceleration of a motor, steps / second ^ 2.
const long SPEED_MANUAL_MOVE_Z = 6 * MOTOR_STEPS_Z; // Maximum speed of a motor during manual move, steps / second.
const bool INVERT_Z = false; // change (true/false) if the carriage moves e.g. "left" when you press "right".
const bool INVERT_Z_ENABLE = false; // change (true/false) if the Z axis enable pin is inverted
const bool NEEDS_REST_Z = false; // Set to false for closed-loop drivers, true for open-loop.
const long MAX_TRAVEL_MM_Z = 300; // Lathe bed doesn't allow to travel more than this in one go, 30cm / ~1 foot
const long BACKLASH_DU_Z = 5600; //14500; // 0mm backlash in deci-microns (10^-7 of a meter)
const char NAME_Z = 'Z'; // Text shown on screen before axis position value, GCode axis name

// Cross-slide lead screw (X) parameters.
const long SCREW_X_DU = 10000; // 4mm SFU1204 ball screw in deci-microns (10^-7 of a meter)
const long MOTOR_STEPS_X = 800;
const long SPEED_START_X = MOTOR_STEPS_X; // Initial speed of a motor, steps / second.
const long ACCELERATION_X = 20 * MOTOR_STEPS_X; // Acceleration of a motor, steps / second ^ 2.
const long SPEED_MANUAL_MOVE_X = 6 * MOTOR_STEPS_X; // Maximum speed of a motor during manual move, steps / second.
const bool INVERT_X = true; // change (true/false) if the carriage moves e.g. "left" when you press "right".
const bool INVERT_X_ENABLE = false; // change (true/false) if the X axis enable pin is inverted
const bool NEEDS_REST_X = false; // Set to false for all kinds of drivers or X will be unlocked when not moving.
const long MAX_TRAVEL_MM_X = 100; // Cross slide doesn't allow to travel more than this in one go, 10cm
const long BACKLASH_DU_X = 0; // 0.15mm backlash in deci-microns (10^-7 of a meter)
const char NAME_X = 'X'; // Text shown on screen before axis position value, GCode axis name

// Manual stepping with left/right/up/down buttons. Only used when step isn't default continuous (1mm or 0.1").
const long STEP_TIME_MS = 500; // Time in milliseconds it should take to make 1 manual step.
const long DELAY_BETWEEN_STEPS_MS = 80; // Time in milliseconds to wait between steps.

// Connect to WiFi and expose web UI to control and receive GCode.
const bool WIFI_ENABLED = true;
const char* SSID = "Wanda2G";
const char* PASSWORD = "jetpet22";
const long INCOMING_BUFFER_SIZE = 100000;
const long OUTGOING_BUFFER_SIZE = 100000;
const char* WIFI_HOSTNAME = "nanoELS";
const char* WIFI_COUNTRY = "CA";
const long WIFI_SCHANNEL = 1;
const long WIFI_NCHANNEL = 165;

/* Changing anything below shouldn't be needed for basic use. */

// Configuration for axis connected to Y. This is uncommon. Dividing head (C) motor parameters.
// Throughout the configuration below we assume 1mm = 1degree of rotation, so 1du = 0.0001degree.
const bool ACTIVE_Y = false; // Whether the axis is connected
const bool ROTARY_Y = true; // Whether the axis is rotary or linear
const long MOTOR_STEPS_Y = 300; // Number of motor steps for 1 rotation of the the worm gear screw (full step with 20:30 reduction)
const long SCREW_Y_DU = 20000; // Degrees multiplied by 10000 that the spindle travels per 1 turn of the worm gear. 2 degrees.
const long SPEED_START_Y = 1600; // Initial speed of a motor, steps / second.
const long ACCELERATION_Y = 16000; // Acceleration of a motor, steps / second ^ 2.
const long SPEED_MANUAL_MOVE_Y = 3200; // Maximum speed of a motor during manual move, steps / second.
const bool INVERT_Y = false; // change (true/false) if the carriage moves e.g. "left" when you press "right".
const bool INVERT_Y_ENABLE = false; // change (true/false) if the Y axis enable pin is inverted
const bool NEEDS_REST_Y = false; // Set to false for closed-loop drivers. Open-loop: true if you need holding torque, false otherwise.
const long MAX_TRAVEL_MM_Y = 360; // Probably doesn't make sense to ask the dividin head to travel multiple turns.
const long BACKLASH_DU_Y = 0; // Assuming no backlash on the worm gear
const char NAME_Y = 'Y'; // Text shown on screen before axis position value, GCode axis name

// Manual handwheels. Ignore if you don't have them installed.
const float PULSE_PER_REVOLUTION = 600; // PPR of handwheels.

const int ENCODER_STEPS_INT = ENCODER_PPR * ENCODER_TYPE * ENCODER_SPINDLE_RATIO; // Number of encoder impulses PCNT counts per revolution of the spindle
const int ENCODER_FILTER = 1; // Encoder pulses shorter than this will be ignored. Clock cycles, 1 - 1023.
const int PCNT_LIM = 31000; // Limit used in hardware pulse counter logic.
const int PCNT_CLEAR = 30000; // Limit where we reset hardware pulse counter value to avoid overflow. Less than PCNT_LIM.
const long DUPR_MAX = 254000; // No more than 1 inch pitch
const int32_t STARTS_MAX = 124; // No more than 124-start thread
const long PASSES_MAX = 999; // No more turn or face passes than this
const long SAFE_DISTANCE_DU = 5000; // Step back 0.5mm from the material when moving between cuts in automated modes
const long SAVE_DELAY_US = 5000000; // Wait 5s after last save and last change of saveable data before saving again
const long DIRECTION_SETUP_DELAY_US = 5; // Stepper driver needs some time to adjust to direction change
const long STEPPED_ENABLE_DELAY_MS = 100; // Delay after stepper is enabled and before issuing steps

const float X_SCALE_RESOLUTION = 0.005;