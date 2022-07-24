# Steps to configure Odrive with D5065 motor
 odrv0.erase_configuration()
 odrv0.axis0.motor.config.current_lim = 40

odrv0.axis0.controller.config.vel_limit = 69

 odrv0.axis0.motor.config.calibration_current = 15
 odrv0.config.enable_brake_resistor = True
 odrv0.config.brake_resistance = 0.7
 odrv0.axis0.motor.config.pole_pairs = 7

odrv0.axis0.motor.config.torque_constant = (8.27/270)

odrv0.axis0.motor.config.motor_type = MOTOR_TYPE_HIGH_CURRENT

odrv0.axis0.encoder.config.cpr = 8192

 odrv0.axis0.encoder.config.use_index = True
 odrv0.save_configuration()
**Oh no odrv0 disappeared**

**Reconnected to ODrive 2076328E4D4B as odrv0**
 odrv0.axis0.controller.config.pos_gain = 15
odrv0.axis0.controller.config.vel_gain = 0.14
 odrv0.axis0.controller.config.vel_integrator_gain = ( 0.5 * 10 *  0.14 )
odrv0.axis0.requested_state = AXIS_STATE_FULL_CALIBRATION_SEQUENCE 

 odrv0.axis0.requested_state = AXIS_STATE_CLOSED_LOOP_CONTROL 

odrv0.axis0.controller.config.control_mode = CONTROL_MODE_VELOCITY_CONTROL

odrv0.axis0.controller.config.vel_ramp_rate = 0.5
 odrv0.axis0.controller.config.input_mode = INPUT_MODE_VEL_RAMP

## Test the motor on different velocity 

odrv0.axis0.controller.input_vel = 0.5

 odrv0.axis0.controller.input_vel = 0.2

 odrv0.axis0.controller.input_vel = 0
 odrv0.axis0.encoder.config.pre_calibrated = True

 odrv0.axis0.encoder.config.use_index = True
odrv0.axis0.controller.config.control_mode = CONTROL_MODE_POSITION_CONTROL

 odrv0.axis0.controller.config.input_mode = INPUT_MODE_PASSTHROUGH

odrv0.axis0.requested_state = AXIS_STATE_CLOSED_LOOP_CONTROL

**` we may need to change pos_gain and vel_gain to control the vibration of the motor`**

 odrv0.axis0.controller.config.pos_gain = 200
odrv0.axis0.controller.config.vel_integrator_gain = (0.5 * 10 *0.32)*10


 odrv0.axis0.controller.start_anticogging_calibration()

 odrv0.axis0.controller.config.anticogging.calib_anticogging
OUT[123]:True

## until it shows false anticogging is going on

**`Note: while anticogging calibration is running we may need to change pos_gain and vel_gain`**

 odrv0.axis0.controller.config.anticogging.pre_calibrated = True

odrv0.axis0.controller.config.pos_gain = 15`
odrv0.axis0.controller.config.vel_integrator_gain =( 0.5 * 10 *  0.14 )
 odrv0.save_configuration()
 **Reconnected to ODrive 2076328E4D4B as odrv0**
 odrv0.axis0.requested_state = AXIS_STATE_ENCODER_INDEX_SEARCH
 odrv0.axis0.requested_state = AXIS_STATE_CLOSED_LOOP_CONTROL

 odrv0.axis0.controller.config.control_mode = CONTROL_MODE_VELOCITY_CONTROL
 odrv0.axis0.controller.input_vel = 0.2
 odrv0.axis0.controller.input_vel = 0



# Encoder configuration



In [91]:  odrv0.axis0.requested_state = AXIS_STATE_ENCODER_INDEX_SEARCH

In [92]: odrv0.axis0.requested_state = 3

In [93]: odrv0.axis0.requested_state = 8

In [94]: odrv0.axis0.controller.input_pos = 1000

In [95]: odrv0.axis0.controller.input_pos = 0



