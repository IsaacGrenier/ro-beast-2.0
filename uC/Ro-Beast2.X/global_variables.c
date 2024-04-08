/*
 * File:   global_variables.c
 * Author: Ro-Beast Battle Busters
 */

#include "global_variables.h"
#include <stddef.h>
#include <stdint.h>

// Timer
int loop_time = 10;
int timer_count = 0;

// UART
int uart_index = 0;
char rx_msg = 0x00;


// Speed Calculation
const float master_clock = 7937793.7;
const float azimuth_step_res = 0.032; // deg/step
const unsigned int azimuth_driver_mode = 2; //2 for half step mode
const float elevation_step_res = 0.006; // mm/step

// PWM
unsigned int sccp_pwm_counts = 0;
unsigned int sccp_pwm_counts_multiple = 0;
unsigned int sccp_stop_criteria;
unsigned int sccp_stop_criteria_multiple = 0;
unsigned int end_register_period;

// QEI
unsigned short curr_pos_cnt = 0; //current position count
unsigned short prev_pos_cnt = 0; //previous position count (0xFFFF if going in the opposite direction)

float encoder_position = 0;
float encoder_speed = 0;
float encoder_freq;

const float encoder_res = 0.032; //deg/sec
const float encoder_gain = 0.032/0.1; // encoder_res/(timer period)
unsigned short encoder_starting_value;
unsigned short encoder_ending_value;

// ADC
// These variables will keep the rotational stepper motor driver ADC values
unsigned short r_dataAN0;
float r_voltageAN0;
float r_currentAN0;
// These variables will keep the elevation stepper motor driver ADC values
unsigned short e_dataAN1;
float e_voltageAN1;
float e_currentAN1;
//constants for ADC
const float vref = 3.3;
const float sense_r = 0.02;
const unsigned short sense_gain = 100;

// Parameters
char curr_height_char[5], curr_azimuth_char[5];
char curr_height_interval_char[4], curr_azimuth_interval_char[5];
char curr_height_speed_char[3], curr_azimuth_speed_char[2];
char curr_tilt_char[2];
char curr_height_current_char[5], curr_azimuth_current_char[5];

float current_height, current_azimuth;
float current_height_interval, current_azimuth_interval;
float current_height_speed, current_azimuth_speed;
float current_tilt;
float current_height_current, current_azimuth_current;

char desired_height_char[5], desired_azimuth_char[5];
char desired_height_interval_char[4], desired_azimuth_interval_char[5];
char desired_height_speed_char[3], desired_azimuth_speed_char[2];

float desired_height, desired_azimuth;
float desired_height_interval, desired_azimuth_interval;
float desired_height_speed, desired_azimuth_speed;
float desired_freq;

int elev_1 = 0, elev_2 = 0, azimuth_home = 0;

// VNA
int vna_measurement_trigger;
int vna_measurement_trigger_off;

// State
robeast_state_struct robeast_state = robeast_standby;

