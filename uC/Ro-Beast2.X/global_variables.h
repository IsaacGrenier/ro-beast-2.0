/*
 * File:   global_variables.h
 * Author: Ro-Beast Battle Busters
 */

#ifndef GLOBAL_VARIABLES_H
#define	GLOBAL_VARIABLES_H

#ifdef	__cplusplus
extern "C" {
#endif 

// Timer
extern int loop_time;
extern int timer_count;

// UART
extern int uart_index;
extern char rx_msg;

// Speed Calculation
extern const float master_clock;
extern const float azimuth_step_res;
extern const unsigned int azimuth_driver_mode;
extern const float elevation_step_res;

// PWM
extern unsigned int sccp_pwm_counts;
extern unsigned int sccp_pwm_counts_multiple;
extern unsigned int sccp_stop_criteria;
extern unsigned int sccp_stop_criteria_multiple;
extern unsigned int end_register_period;

// QEI
extern unsigned short curr_pos_cnt;
extern unsigned short prev_pos_cnt;

extern float encoder_position;
extern float encoder_speed;
extern float encoder_freq;

extern const float encoder_res;
extern const float encoder_gain;
extern unsigned short encoder_sampling_time;
extern unsigned short encoder_starting_value;
extern unsigned short encoder_ending_value;

// VNA
extern int vna_measurement_trigger;
extern int vna_measurement_trigger_off;

// ADC
// These variables will keep the rotational stepper motor driver ADC values
extern unsigned short r_dataAN0;
extern float r_voltageAN0;
extern float r_currentAN0;
// These variables will keep the elevation stepper motor driver ADC values
extern unsigned short e_dataAN1;
extern float e_voltageAN1;
extern float e_currentAN1;
//constants for ADC
extern const float vref;
extern const float sense_r;
extern const unsigned short sense_gain;

// Parameters
extern char curr_height_char[5], curr_azimuth_char[5];
extern char curr_height_interval_char[4], curr_azimuth_interval_char[5];
extern char curr_height_speed_char[3], curr_azimuth_speed_char[2];
extern char curr_tilt_char[2];
extern char curr_height_current_char[5], curr_azimuth_current_char[5];

extern float current_height, current_azimuth;
extern float current_height_interval, current_azimuth_interval;
extern float current_height_speed, current_azimuth_speed;
extern float current_tilt;
extern float current_height_current, current_azimuth_current;

extern char desired_height_char[5], desired_azimuth_char[5];
extern char desired_height_interval_char[4], desired_azimuth_interval_char[5];
extern char desired_height_speed_char[3], desired_azimuth_speed_char[2];

extern float desired_height, desired_azimuth;
extern float desired_height_interval, desired_azimuth_interval;
extern float desired_height_speed, desired_azimuth_speed;
extern float desired_freq;

extern int elev_1, elev_2, azimuth_home;

// State
typedef enum
{
    robeast_init,     
    robeast_position,     
    robeast_height_sweep,
    robeast_azimuth_sweep,
    robeast_pause,      
    robeast_cancel,     
    robeast_fault,
    robeast_standby
}robeast_state_struct;

extern robeast_state_struct robeast_state;

#ifdef	__cplusplus
}
#endif

#endif	// GLOBAL_VARIABLES_H