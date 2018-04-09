#ifndef CONFIGURATION_ADV_H
#define CONFIGURATION_ADV_H
#define CONFIGURATION_ADV_H_VERSION 010100

#if DISABLED(PIDTEMPBED)
  #define BED_CHECK_INTERVAL 5000 // ms between checks in bang-bang control
  #if ENABLED(BED_LIMIT_SWITCHING)
    #define BED_HYSTERESIS 2 // Only disable heating if T>target+BED_HYSTERESIS and enable heating if T>target-BED_HYSTERESIS
  #endif
#endif

#if ENABLED(THERMAL_PROTECTION_HOTENDS)
  #define THERMAL_PROTECTION_PERIOD 40        // Seconds
  #define THERMAL_PROTECTION_HYSTERESIS 4     // Degrees Celsius
  #define WATCH_TEMP_PERIOD 20                // Seconds
  #define WATCH_TEMP_INCREASE 2               // Degrees Celsius
#endif

#if ENABLED(THERMAL_PROTECTION_BED)
  #define THERMAL_PROTECTION_BED_PERIOD 20    // Seconds
  #define THERMAL_PROTECTION_BED_HYSTERESIS 2 // Degrees Celsius
  #define WATCH_BED_TEMP_PERIOD 60                // Seconds
  #define WATCH_BED_TEMP_INCREASE 2               // Degrees Celsius
#endif

#if ENABLED(PIDTEMP)
  //#define PID_EXTRUSION_SCALING
  #if ENABLED(PID_EXTRUSION_SCALING)
    #define DEFAULT_Kc (100) //heating power=Kc*(e_speed)
    #define LPQ_MAX_LEN 50
  #endif
#endif

#define AUTOTEMP
#if ENABLED(AUTOTEMP)
  #define AUTOTEMP_OLDWEIGHT 0.98
#endif

//#define SHOW_TEMP_ADC_VALUES

//#define MAX_CONSECUTIVE_LOW_TEMPERATURE_ERROR_ALLOWED 0

//#define MILLISECONDS_PREHEAT_TIME 0

// @section extruder

//#define EXTRUDER_RUNOUT_PREVENT
#if ENABLED(EXTRUDER_RUNOUT_PREVENT)
  #define EXTRUDER_RUNOUT_MINTEMP 190
  #define EXTRUDER_RUNOUT_SECONDS 30
  #define EXTRUDER_RUNOUT_SPEED 1500  // mm/m
  #define EXTRUDER_RUNOUT_EXTRUDE 5   // mm
#endif

#define TEMP_SENSOR_AD595_OFFSET 0.0
#define TEMP_SENSOR_AD595_GAIN   1.0

//#define USE_CONTROLLER_FAN
#if ENABLED(USE_CONTROLLER_FAN)
  //#define CONTROLLER_FAN_PIN FAN1_PIN  // Set a custom pin for the controller fan
  #define CONTROLLERFAN_SECS 60          // Duration in seconds for the fan to run after all motors are disabled
  #define CONTROLLERFAN_SPEED 255        // 255 == full speed
#endif

//#define FAN_KICKSTART_TIME 100

//#define FAN_MIN_PWM 50

// @section extruder

#define E0_AUTO_FAN_PIN -1
#define E1_AUTO_FAN_PIN -1
#define E2_AUTO_FAN_PIN -1
#define E3_AUTO_FAN_PIN -1
#define E4_AUTO_FAN_PIN -1
#define EXTRUDER_AUTO_FAN_TEMPERATURE 50
#define EXTRUDER_AUTO_FAN_SPEED   255  // == full speed

#define FANMUX0_PIN -1
#define FANMUX1_PIN -1
#define FANMUX2_PIN -1

//#define CASE_LIGHT_ENABLE
#if ENABLED(CASE_LIGHT_ENABLE)
  //#define CASE_LIGHT_PIN 4                  // Override the default pin if needed
  #define INVERT_CASE_LIGHT false             // Set true if Case Light is ON when pin is LOW
  #define CASE_LIGHT_DEFAULT_ON true          // Set default power-up state on
  #define CASE_LIGHT_DEFAULT_BRIGHTNESS 105   // Set default power-up brightness (0-255, requires PWM pin)
  //#define MENU_ITEM_CASE_LIGHT              // Add a Case Light option to the LCD main menu
#endif

//#define ENDSTOPS_ALWAYS_ON_DEFAULT

//#define Z_LATE_ENABLE // Enable Z the last moment. Needed if your Z driver overheats.

//#define X_DUAL_STEPPER_DRIVERS
#if ENABLED(X_DUAL_STEPPER_DRIVERS)
  // Set true if the two X motors need to rotate in opposite directions
  #define INVERT_X2_VS_X_DIR true
#endif

//#define Y_DUAL_STEPPER_DRIVERS
#if ENABLED(Y_DUAL_STEPPER_DRIVERS)
  // Set true if the two Y motors need to rotate in opposite directions
  #define INVERT_Y2_VS_Y_DIR true
#endif

//#define Z_DUAL_STEPPER_DRIVERS


// Enable this for dual x-carriage printers.
// A dual x-carriage design has the advantage that the inactive extruder can be parked which
// prevents hot-end ooze contaminating the print. It also reduces the weight of each x-carriage
// allowing faster printing speeds. Connect your X2 stepper to the first unused E plug.
//#define DUAL_X_CARRIAGE

// Activate a solenoid on the active extruder with M380. Disable all with M381.
// Define SOL0_PIN, SOL1_PIN, etc., for each extruder that has a solenoid.
//#define EXT_SOLENOID

// @section homing

//homing hits the endstop, then retracts by this distance, before it tries to slowly bump again:
#define X_HOME_BUMP_MM 5
#define Y_HOME_BUMP_MM 5
#define Z_HOME_BUMP_MM 2
#define HOMING_BUMP_DIVISOR {2, 2, 4}  // Re-Bump Speed Divisor (Divides the Homing Feedrate)
//#define QUICK_HOME  //if this is defined, if both x and y are to be homed, a diagonal move will be performed initially.

// When G28 is called, this option will make Y home before X
//#define HOME_Y_BEFORE_X

#define AXIS_RELATIVE_MODES {false, false, false, false}

// Allow duplication mode with a basic dual-nozzle extruder
//#define DUAL_NOZZLE_DUPLICATION_MODE

// By default pololu step drivers require an active high signal. However, some high power drivers require an active low signal as step.
#define INVERT_X_STEP_PIN false
#define INVERT_Y_STEP_PIN false
#define INVERT_Z_STEP_PIN false
#define INVERT_E_STEP_PIN false

// Default stepper release if idle. Set to 0 to deactivate.
// Steppers will shut down DEFAULT_STEPPER_DEACTIVE_TIME seconds after the last move when DISABLE_INACTIVE_? is true.
// Time can be set by M18 and M84.
#define DEFAULT_STEPPER_DEACTIVE_TIME 120
#define DISABLE_INACTIVE_X true
#define DISABLE_INACTIVE_Y true
#define DISABLE_INACTIVE_Z true  // set to false if the nozzle will fall down on your printed part when print has finished.
#define DISABLE_INACTIVE_E true

#define DEFAULT_MINIMUMFEEDRATE       0.0     // minimum feedrate
#define DEFAULT_MINTRAVELFEEDRATE     0.0

//#define HOME_AFTER_DEACTIVATE  // Require rehoming after steppers are deactivated

// @section lcd

#if ENABLED(ULTIPANEL)
  #define MANUAL_FEEDRATE {50*60, 50*60, 4*60, 60} // Feedrates for manual moves along X, Y, Z, E from panel
  #define ULTIPANEL_FEEDMULTIPLY  // Comment to disable setting feedrate multiplier via encoder
#endif

// @section extras

// minimum time in microseconds that a movement needs to take if the buffer is emptied.
#define DEFAULT_MINSEGMENTTIME        20000

// If defined the movements slow down when the look ahead buffer is only half full
#define SLOWDOWN

// Frequency limit
// See nophead's blog for more info
// Not working O
//#define XY_FREQUENCY_LIMIT  15

#define MINIMUM_PLANNER_SPEED 0.05 // (mm/sec)

// Microstep setting (Only functional when stepper driver microstep pins are connected to MCU.
#define MICROSTEP_MODES {16,16,16,16,16} // [1,2,4,8,16]

//#define PWM_MOTOR_CURRENT { 1300, 1300, 1250 }          // Values in milliamps
//#define DIGIPOT_MOTOR_CURRENT { 135,135,135,135,135 }   // Values 0-255 (RAMBO 135 = ~0.75A, 185 = ~1A)
//#define DAC_MOTOR_CURRENT_DEFAULT { 70, 80, 90, 80 }    // Default drive percent - X, Y, Z, E axis

// Uncomment to enable an I2C based DIGIPOT like on the Azteeg X3 Pro
//#define DIGIPOT_I2C
//#define DIGIPOT_MCP4018          // Requires library from https://github.com/stawel/SlowSoftI2CMaster
#define DIGIPOT_I2C_NUM_CHANNELS 8 // 5DPRINT: 4     AZTEEG_X3_PRO: 8
// Actual motor currents in Amps, need as many here as DIGIPOT_I2C_NUM_CHANNELS
#define DIGIPOT_I2C_MOTOR_CURRENTS { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 }  //  AZTEEG_X3_PRO

#define ENCODER_RATE_MULTIPLIER         // If defined, certain menu edit operations automatically multiply the steps when the encoder is moved quickly
#define ENCODER_10X_STEPS_PER_SEC 75    // If the encoder steps per sec exceeds this value, multiply steps moved x10 to quickly advance the value
#define ENCODER_100X_STEPS_PER_SEC 160  // If the encoder steps per sec exceeds this value, multiply steps moved x100 to really quickly advance the value

//#define CHDK 4        //Pin for triggering CHDK to take a picture see how to use it here http://captain-slow.dk/2014/03/09/3d-printing-timelapses/
#define CHDK_DELAY 50 //How long in ms the pin should stay HIGH before going LOW again

// Include a page of printer information in the LCD Main Menu
//#define LCD_INFO_MENU

// Scroll a longer status message into view
//#define STATUS_MESSAGE_SCROLLING

// On the Info Screen, display XY with one decimal place when possible
//#define LCD_DECIMAL_SMALL_XY

// The timeout (in ms) to return to the status screen from sub-menus
//#define LCD_TIMEOUT_TO_STATUS 15000

#define USE_WATCHDOG
#if ENABLED(USE_WATCHDOG)
  // If you have a watchdog reboot in an ArduinoMega2560 then the device will hang forever, as a watchdog reset will leave the watchdog on.
  // The "WATCHDOG_RESET_MANUAL" goes around this by not using the hardware reset.
  //  However, THIS FEATURE IS UNSAFE!, as it will only work if interrupts are disabled. And the code could hang in an interrupt routine with interrupts disabled.
  //#define WATCHDOG_RESET_MANUAL
#endif

//#define BABYSTEPPING

//#define LIN_ADVANCE
//
// G2/G3 Arc Support
//
#define ARC_SUPPORT               // Disable this feature to save ~3226 bytes
#if ENABLED(ARC_SUPPORT)
  #define MM_PER_ARC_SEGMENT  1   // Length of each arc segment
  #define N_ARC_CORRECTION   25   // Number of intertpolated segments between corrections
  //#define ARC_P_CIRCLES         // Enable the 'P' parameter to specify complete circles
  //#define CNC_WORKSPACE_PLANES  // Allow G2/G3 to operate in XY, ZX, or YZ planes
#endif

// Support for G5 with XYZE destination and IJPQ offsets. Requires ~2666 bytes.
//#define BEZIER_CURVE_SUPPORT

//#define G38_PROBE_TARGET


// Moves (or segments) with fewer steps than this will be joined with the next move
#define MIN_STEPS_PER_SEGMENT 6

// The minimum pulse width (in µs) for stepping a stepper.
// Set this if you find stepping unreliable, or if using a very fast CPU.
#define MINIMUM_STEPPER_PULSE 0 // (µs) The smallest stepper pulse allowed

#if ENABLED(SDSUPPORT)
  #define BLOCK_BUFFER_SIZE 16 // SD,LCD,Buttons take more memory, block buffer needs to be smaller
#else
  #define BLOCK_BUFFER_SIZE 16 // maximize block buffer
#endif

// The ASCII buffer for serial input
#define MAX_CMD_SIZE 96
#define BUFSIZE 4

// :[0, 2, 4, 8, 16, 32, 64, 128, 256]
#define TX_BUFFER_SIZE 0

//#define RX_BUFFER_SIZE 1024

#if RX_BUFFER_SIZE >= 1024
  // Enable to have the controller send XON/XOFF control characters to
  // the host to signal the RX buffer is becoming full.
  //#define SERIAL_XON_XOFF
#endif


//#define EMERGENCY_PARSER

//#define NO_TIMEOUTS 1000 // Milliseconds

// Some clients will have this feature soon. This could make the NO_TIMEOUTS unnecessary.
//#define ADVANCED_OK

//#define FWRETRACT  // ONLY PARTIALLY TESTED


//#define ADVANCED_PAUSE_FEATURE

// @section TMC2130

/**
 * Enable this for SilentStepStick Trinamic TMC2130 SPI-configurable stepper drivers.
 *
 * You'll also need the TMC2130Stepper Arduino library
 * (https://github.com/teemuatlut/TMC2130Stepper).
 *
 * To use TMC2130 stepper drivers in SPI mode connect your SPI2130 pins to
 * the hardware SPI interface on your board and define the required CS pins
 * in your `pins_MYBOARD.h` file. (e.g., RAMPS 1.4 uses AUX3 pins `X_CS_PIN 53`, `Y_CS_PIN 49`, etc.).
 */
#define HAVE_TMC2130

#if ENABLED(HAVE_TMC2130)

  // CHOOSE YOUR MOTORS HERE, THIS IS MANDATORY
  #define X_IS_TMC2130
  //#define X2_IS_TMC2130
  #define Y_IS_TMC2130
  //#define Y2_IS_TMC2130
  #define Z_IS_TMC2130
  //#define Z2_IS_TMC2130
  #define E0_IS_TMC2130
  #define E1_IS_TMC2130
  //#define E2_IS_TMC2130
  //#define E3_IS_TMC2130
  //#define E4_IS_TMC2130

  /**
   * Stepper driver settings
   */

  #define R_SENSE           0.1  // R_sense resistor for SilentStepStick2130   0.11
  #define HOLD_MULTIPLIER    0.5  // Scales down the holding current from run current  0.2, 0.6, 1(to skip)
  #define INTERPOLATE          1  // Interpolate X/Y/Z_MICROSTEPS to 256  

  #define X_CURRENT         1200 // rms current in mA. Multiply by 1.41 for peak current.  1000, 800
  #define X_MICROSTEPS        16  // 0..256  

  #define Y_CURRENT         1200  //1000, 800
  #define Y_MICROSTEPS        16

  #define Z_CURRENT         2000  //1000, 800
  #define Z_MICROSTEPS        16

  //#define X2_CURRENT      1000
  //#define X2_MICROSTEPS     16

  //#define Y2_CURRENT      1000
  //#define Y2_MICROSTEPS     16

  //#define Z2_CURRENT      1000
  //#define Z2_MICROSTEPS     16

  #define E0_CURRENT      1200  //1000, 800 mA
  #define E0_MICROSTEPS     16

  #define E1_CURRENT      1200  //1000, 800
  #define E1_MICROSTEPS     16

  //#define E2_CURRENT      1000
  //#define E2_MICROSTEPS     16

  //#define E3_CURRENT      1000
  //#define E3_MICROSTEPS     16

  //#define E4_CURRENT      1000
  //#define E4_MICROSTEPS     16

  /**
   * Use Trinamic's ultra quiet stepping mode.
   * When disabled, Marlin will use spreadCycle stepping mode.
   */
  #define STEALTHCHOP //19feb

  /**
   * Let Marlin automatically control stepper current.
   * This is still an experimental feature.
   * Increase current every 5s by CURRENT_STEP until stepper temperature prewarn gets triggered,
   * then decrease current by CURRENT_STEP until temperature prewarn is cleared.
   * Adjusting starts from X/Y/Z/E_CURRENT but will not increase over AUTO_ADJUST_MAX
   * Relevant g-codes:
   * M906 - Set or get motor current in milliamps using axis codes X, Y, Z, E. Report values if no axis codes given.
   * M906 S1 - Start adjusting current
   * M906 S0 - Stop adjusting current
   * M911 - Report stepper driver overtemperature pre-warn condition.
   * M912 - Clear stepper driver overtemperature pre-warn condition flag.
   */
  #define AUTOMATIC_CURRENT_CONTROL

  #if ENABLED(AUTOMATIC_CURRENT_CONTROL)
    #define CURRENT_STEP          50  // [mA]
    #define AUTO_ADJUST_MAX     2500 // [mA], 1300mA_rms = 1840mA_peak
    #define REPORT_CURRENT_CHANGE
  #endif

#define HYBRID_THRESHOLD  //19feb

#define X_HYBRID_THRESHOLD     60  // [mm/s]
#define X2_HYBRID_THRESHOLD    80
#define Y_HYBRID_THRESHOLD     60
#define Y2_HYBRID_THRESHOLD    80
#define Z_HYBRID_THRESHOLD       5
#define Z2_HYBRID_THRESHOLD      5
#define E0_HYBRID_THRESHOLD     22
#define E1_HYBRID_THRESHOLD     22 
#define E2_HYBRID_THRESHOLD     45
#define E3_HYBRID_THRESHOLD     45
#define E4_HYBRID_THRESHOLD     45

  /**
   * Use stallGuard2 to sense an obstacle and trigger an endstop.
   * You need to place a wire from the driver's DIAG1 pin to the X/Y endstop pin.
   * If used along with STEALTHCHOP, the movement will be louder when homing. This is normal.
   *
   * X/Y_HOMING_SENSITIVITY is used for tuning the trigger sensitivity.
   * Higher values make the system LESS sensitive.
   * Lower value make the system MORE sensitive.
   * Too low values can lead to false positives, while too high values will collide the axis without triggering.
   * It is advised to set X/Y_HOME_BUMP_MM to 0.
   * M914 X/Y to live tune the setting
   */
  //#define SENSORLESS_HOMING

  #if ENABLED(SENSORLESS_HOMING)
    #define X_HOMING_SENSITIVITY  19
    #define Y_HOMING_SENSITIVITY  19
  #endif

  /**
   * You can set your own advanced settings by filling in predefined functions.
   * A list of available functions can be found on the library github page
   * https://github.com/teemuatlut/TMC2130Stepper
   *
   * Example:
   * #define TMC2130_ADV() { \
   *   stepperX.diag0_temp_prewarn(1); \
   *   stepperX.interpolate(0); \
   * }
   */
  #define  TMC2130_ADV() {  }

#endif // HAVE_TMC2130

//#define HAVE_L6470DRIVER

//#define EXPERIMENTAL_I2CBUS
#define I2C_SLAVE_ADDRESS  0 // Set a value from 8 to 127 to act as a slave

//#define SPINDLE_LASER_ENABLE

//#define PINS_DEBUGGING

#define AUTO_REPORT_TEMPERATURES

#define EXTENDED_CAPABILITIES_REPORT

//#define VOLUMETRIC_DEFAULT_ON

//#define NO_WORKSPACE_OFFSETS

#define PROPORTIONAL_FONT_RATIO 1.0

#define FASTER_GCODE_PARSER

//#define CUSTOM_USER_MENUS

//#define ACTION_ON_KILL "poweroff"

//#define I2C_POSITION_ENCODERS

//#define MAX7219_DEBUG

#endif // CONFIGURATION_ADV_H
