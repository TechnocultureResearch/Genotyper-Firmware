 # ODrive configuration Parameters
odrv0.erase_configuration()

odrv0.config.enable_brake_resistor = True
odrv0.config.brake_resistance = 0.7
odrv0.config.dc_bus_under_voltage_trip_level = 8
odrv0.config.dc_bus_over_voltage_trip_level = 25.5
odrv0.config.dc_max_positive_current = 20
odrv0.config.dc_max_negative_current // check first
odrv0.config.dc_max_regen_current = 0



odrv0.save_configuration()



 odrv0.axis0.motor.config.pole_pairs = 7
 odrv0.axis0.motor.config.calibration_current = 15
 odrv0.axis0.motor.config.motor_type = 0	// high current
 odrv0.axis0.motor.config.resistance_calib_max_voltage = 2 // check
 odrv0.axis0.motor.config.torque_constant = (8.27/270)
 odrv0.axis0.motor.config.current_lim = 40
 odrv0.axis0.motor.config.calibration_current = 5
 odrv0.axis0.motor.config.requested_current_range =20 //check



odrv0.save_configuration()



 odrv0.axis0.encoder.config.mode = 0 // incremental
odrv0.axis0.encoder.config.cpr = 8192
odrv0.axis0.encoder.config.bandwidth = 3000 //check first
odrv0.axis0.config.calibration_lockin.current = 5 // check first
odrv0.axis0.config.calibration_lockin.ramp_time = 0.4 
odrv0.axis0.config.calibration_lockin.ramp_distance = 3.1415927410125732 
odrv0.axis0.config.calibration_lockin.accel = 20 
odrv0.axis0.config.calibration_lockin.vel = 40



odrv0.save_configuration()




 odrv0.axis0.controller.config.control_mode = 3  //CONTROL_MODE_POSITION_CONTROL

 odrv0.axis0.controller.config.vel_limit = 69

 odrv0.axis0.controller.config.pos_gain = 13
 odrv0.axis0.controller.config.vel_gain = 0.12
 odrv0.axis0.controller.config.vel_integrator_gain = 0


 odrv0.axis0.controller.config.input_mode = 5 // trap traj

odrv0.axis0.trap_traj.config.vel_limit = 50
odrv0.axis0.trap_traj.config.accel_limit = 30
odrv0.axis0.trap_traj.config.decel_limit = 30



odrv0.save_configuration()



odrv0.axis0.motor.is_calibrated  // check

odrv0.axis0.requested_state = 4 // AXIS_STATE_MOTOR_CALIBRATION
odrv0.axis0.motor.config.pre_calibrated = True
odrv0.axis0.requested_state = 7 // encoder offset calibration

odrv0.axis0.requested_state = 8 // closed loop control

odrv0.axis0.config.startup_encoder_offset_calibration

odrv0.axis0.encoder.config.use_index = True

odrv0.axis0.config.startup_encoder_index_search = True

odrv0.axis0.config.startup_closed_loop_control = True



odrv0.save_configuration()



odrv0.axis0.requested_state = 6 // encoder index search

odrv0.axis0.requested_state = 8 // closed loop control

odrv0.axis0.controller.input_pos = 10 // turns

odrv0.axis0.requested_state = 1 // AXIS_STATE_IDLE

quit // to quit the odrivetool





###[Reference link](https://www.youtube.com/watch?v=K4QkISL9Rqo)





