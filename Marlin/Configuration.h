#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#define CONFIGURATION_H_VERSION 010100


#define STRING_CONFIG_H_AUTHOR "(none, default config)" // Who made the changes.
#define SHOW_BOOTSCREEN
#define STRING_SPLASH_LINE1 SHORT_BUILD_VERSION // will be shown during bootup in line 1
#define STRING_SPLASH_LINE2 WEBSITE_URL         // will be shown during bootup in line 2

#define SERIAL_PORT 0

#define BAUDRATE 115200

#ifndef MOTHERBOARD
  #define MOTHERBOARD BOARD_RAMPS_14_EEBF
#endif

#define EXTRUDERS 2

#define HOTEND_OFFSET_X {0.0, 20.00} // (in mm) for each extruder, offset of the hotend on the X axis
#define HOTEND_OFFSET_Y {0.0, 0.00}  // (in mm) for each extruder, offset of the hotend on the Y axis

#define POWER_SUPPLY 0
#if POWER_SUPPLY > 0
  // Enable this option to leave the PSU off at startup.
  // Power to steppers and heaters will need to be turned on with M80.
  //#define PS_DEFAULT_OFF
#endif

#define TEMP_SENSOR_0 5
#define TEMP_SENSOR_1 5
#define TEMP_SENSOR_2 0
#define TEMP_SENSOR_3 0
#define TEMP_SENSOR_4 0
#define TEMP_SENSOR_BED 1

// Dummy thermistor constant temperature readings, for use with 998 and 999
#define DUMMY_THERMISTOR_998_VALUE 25
#define DUMMY_THERMISTOR_999_VALUE 100

//#define TEMP_SENSOR_1_AS_REDUNDANT
#define MAX_REDUNDANT_TEMP_SENSOR_DIFF 10

// Extruder temperature must be close to target for this long before M109 returns success
#define TEMP_RESIDENCY_TIME 10  
#define TEMP_HYSTERESIS 3       
#define TEMP_WINDOW     1       

// Bed temperature must be close to target for this long before M190 returns success
#define TEMP_BED_RESIDENCY_TIME 10  
#define TEMP_BED_HYSTERESIS 3       
#define TEMP_BED_WINDOW     1       

#define HEATER_0_MINTEMP -1
#define HEATER_1_MINTEMP -1
#define HEATER_2_MINTEMP 5
#define HEATER_3_MINTEMP 5
#define HEATER_4_MINTEMP 5
#define BED_MINTEMP -1

#define HEATER_0_MAXTEMP 350
#define HEATER_1_MAXTEMP 350
#define HEATER_2_MAXTEMP 275
#define HEATER_3_MAXTEMP 275
#define HEATER_4_MAXTEMP 275
#define BED_MAXTEMP 150

#define PIDTEMP
#define BANG_MAX 255 // limits current to nozzle while in bang-bang mode; 255=full current
#define PID_MAX BANG_MAX // limits current to nozzle while PID is active (see PID_FUNCTIONAL_RANGE below); 255=full current
#if ENABLED(PIDTEMP)
  #define PID_FUNCTIONAL_RANGE 10 
  #define K1 0.95 
  // Ultimaker
  #define  DEFAULT_Kp 22.2
  #define  DEFAULT_Ki 1.08
  #define  DEFAULT_Kd 114
#endif // PIDTEMP


//#define PIDTEMPBED

//#define BED_LIMIT_SWITCHING
#define MAX_BED_POWER 255 // limits duty cycle to bed; 255=full current

#if ENABLED(PIDTEMPBED)
  //#define PID_BED_DEBUG // Sends debug data to the serial port.
  //120V 250W silicone heater into 4mm borosilicate (MendelMax 1.5+)
  //from FOPDT model - kp=.39 Tp=405 Tdead=66, Tc set to 79.2, aggressive factor of .15 (vs .1, 1, 10)
  #define  DEFAULT_bedKp 10.00
  #define  DEFAULT_bedKi .023
  #define  DEFAULT_bedKd 305.4
  // FIND YOUR OWN: "M303 E-1 C8 S90" to run autotune on the bed at 90 degreesC for 8 cycles.
#endif // PIDTEMPBED

//#define PREVENT_COLD_EXTRUSION
//#define EXTRUDE_MINTEMP 170

//#define PREVENT_LENGTHY_EXTRUDE
//#define EXTRUDE_MAXLENGTH 200

#define THERMAL_PROTECTION_HOTENDS // Enable thermal protection for all extruders
#define THERMAL_PROTECTION_BED     // Enable thermal protection for the heated bed


#define COREXY

//#define USE_XMIN_PLUG
//#define USE_YMIN_PLUG
//#define USE_ZMIN_PLUG
#define USE_XMAX_PLUG
#define USE_YMAX_PLUG
#define USE_ZMAX_PLUG


//#define ENDSTOPPULLUPS 
#if DISABLED(ENDSTOPPULLUPS)
  #define ENDSTOPPULLUP_XMAX
  #define ENDSTOPPULLUP_YMAX
  #define ENDSTOPPULLUP_ZMAX
  #define ENDSTOPPULLUP_XMIN
  #define ENDSTOPPULLUP_YMIN
  #define ENDSTOPPULLUP_ZMIN
  //#define ENDSTOPPULLUP_ZMIN_PROBE
#endif

// Mechanical endstop with COM to ground and NC to Signal uses "false" here (most common setup).
#define X_MIN_ENDSTOP_INVERTING true // set to true to invert the logic of the endstop.
#define Y_MIN_ENDSTOP_INVERTING true // set to true to invert the logic of the endstop.
#define Z_MIN_ENDSTOP_INVERTING true // set to true to invert the logic of the endstop.
#define X_MAX_ENDSTOP_INVERTING true // set to true to invert the logic of the endstop.
#define Y_MAX_ENDSTOP_INVERTING true // set to true to invert the logic of the endstop.
#define Z_MAX_ENDSTOP_INVERTING true // set to true to invert the logic of the endstop.
#define Z_MIN_PROBE_ENDSTOP_INVERTING false // set to true to invert the logic of the probe.

// Enable this feature if all enabled endstop pins are interrupt-capable.
// This will remove the need to poll the interrupt pins, saving many CPU cycles.
//#define ENDSTOP_INTERRUPTS_FEATURE

//#define DISTINCT_E_FACTORS

//Default Axis Steps Per Unit (steps/mm)  X, Y, Z, E0 [, E1[, E2[, E3[, E4]]]]
#define DEFAULT_AXIS_STEPS_PER_UNIT   { 100, 100, 400, 418.81 }

//Default Max Feed Rate (mm/s)			X, Y, Z, E0 [, E1[, E2[, E3[, E4]]]]
#define DEFAULT_MAX_FEEDRATE          { 200, 200, 6, 25 }

//Default Max Acceleration (change/s) change = mm/s   X, Y, Z, E0 [, E1[, E2[, E3[, E4]]]]
#define DEFAULT_MAX_ACCELERATION      { 500, 500, 13, 10000 }

#define DEFAULT_ACCELERATION          3000    // X, Y, Z and E acceleration for printing moves
#define DEFAULT_RETRACT_ACCELERATION  3000    // E acceleration for retracts
#define DEFAULT_TRAVEL_ACCELERATION   500    // X, Y, Z acceleration for travel (non printing) moves

#define DEFAULT_XJERK                 7 //15.0
#define DEFAULT_YJERK                 7 //15.0
#define DEFAULT_ZJERK                  0.4
#define DEFAULT_EJERK                  5.0

#define Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN


//#define Z_MIN_PROBE_ENDSTOP

//#define PROBE_MANUALLY

//#define FIX_MOUNTED_PROBE

#define X_PROBE_OFFSET_FROM_EXTRUDER 10  // X offset: -left  +right  [of the nozzle]
#define Y_PROBE_OFFSET_FROM_EXTRUDER 10  // Y offset: -front +behind [the nozzle]
#define Z_PROBE_OFFSET_FROM_EXTRUDER 0   // Z offset: -below +above  [the nozzle]

#define XY_PROBE_SPEED 8000

#define Z_PROBE_SPEED_FAST HOMING_FEEDRATE_Z

#define Z_PROBE_SPEED_SLOW (Z_PROBE_SPEED_FAST / 2)

#define Z_CLEARANCE_DEPLOY_PROBE   10 // Z Clearance for Deploy/Stow
#define Z_CLEARANCE_BETWEEN_PROBES  5 // Z Clearance between probe points

#define Z_PROBE_OFFSET_RANGE_MIN -20
#define Z_PROBE_OFFSET_RANGE_MAX 20


// For Inverting Stepper Enable Pins (Active Low) use 0, Non Inverting (Active High) use 1
//:{ 0:'Low', 1:'High' }
#define X_ENABLE_ON 0
#define Y_ENABLE_ON 0
#define Z_ENABLE_ON 0
#define E_ENABLE_ON 0 // For all extruders

#define DISABLE_X false
#define DISABLE_Y false
#define DISABLE_Z false

#define DISABLE_E false 
#define DISABLE_INACTIVE_EXTRUDER true 

#define INVERT_X_DIR true
#define INVERT_Y_DIR true
#define INVERT_Z_DIR false

// For direct drive extruder v9 set to true, for geared extruder set to false.
#define INVERT_E0_DIR true
#define INVERT_E1_DIR true
#define INVERT_E2_DIR false
#define INVERT_E3_DIR false
#define INVERT_E4_DIR false

//#define Z_HOMING_HEIGHT 4  

// Direction of endstops when homing; 1=MAX, -1=MIN
// :[-1,1]
#define X_HOME_DIR 1
#define Y_HOME_DIR 1
#define Z_HOME_DIR 1

// The size of the print bed
#define X_BED_SIZE 250
#define Y_BED_SIZE 200

// Travel limits (mm) after homing, corresponding to endstop positions.
#define X_MIN_POS 0
#define Y_MIN_POS 0
#define Z_MIN_POS 0
#define X_MAX_POS X_BED_SIZE
#define Y_MAX_POS Y_BED_SIZE
#define Z_MAX_POS 201.5

#define MIN_SOFTWARE_ENDSTOPS
#define MAX_SOFTWARE_ENDSTOPS

//#define AUTO_BED_LEVELING_BILINEAR
//#define DEBUG_LEVELING_FEATURE

// Homing speeds (mm/m)
#define HOMING_FEEDRATE_XY (40*60)
#define HOMING_FEEDRATE_Z  (6*60) //

#define EEPROM_CHITCHAT   // Give feedback on EEPROM commands. Disable to save PROGMEM.

#define HOST_KEEPALIVE_FEATURE        // Disable this if your host doesn't like keepalive messages
#define DEFAULT_KEEPALIVE_INTERVAL 2  // Number of seconds between "busy" messages. Set with M113.
#define BUSY_WHILE_HEATING            // Some hosts require "busy" messages even during heating

#define PREHEAT_1_TEMP_HOTEND 180
#define PREHEAT_1_TEMP_BED     70
#define PREHEAT_1_FAN_SPEED     0 // Value from 0 to 255

#define PREHEAT_2_TEMP_HOTEND 240
#define PREHEAT_2_TEMP_BED    110
#define PREHEAT_2_FAN_SPEED     0 // Value from 0 to 255

#define PRINTJOB_TIMER_AUTOSTART


#define LCD_LANGUAGE en

#define DISPLAY_CHARSET_HD44780 JAPANESE

#define SOFT_PWM_SCALE 0
#define HANDOVER_SUCCESS

#define SERVO_DELAY { 300 }

#define DEFAULT_NOMINAL_FILAMENT_DIA 3.00   // (mm) Diameter of the filament generally used (3.0 or 1.75mm), also used in the slicer. Used to validate sensor reading.

// BED LED CONTROL 
#define LED_CONTROL				// Enable For Controlling Bed and Extruder LED
#define LED_TEMP_DIFF 3

//Requires PRINTJOB_TIMER_AUTOSTART Enabled 
#define AUDIO_OUTPUT			// Enable for Buzzer Sound

#endif // CONFIGURATION_H
