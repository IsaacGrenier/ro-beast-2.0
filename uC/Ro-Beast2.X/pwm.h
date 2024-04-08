/*
 * File:   pwm.h
 * Author: Ro-Beast Battle Busters
 */

#ifndef PWM_H
#define	PWM_H

#include <xc.h> // include processor files - each processor file is guarded.  

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

void PWM1_Initialize(void);
void PWM1_Reset(float desired_speed, char speed_type);
void PWM_Enable(void);
void PWM_Disable(void);
void PWM1_Ramp(void);
void SCCP_Initialize(void);
void SCCP_Enable(void);
void SCCP_Disable(void);
void SCCP_EStopCriteria(float desired_height, float current_height);
void SCCP_AStopCriteria(float desired_azimuth);
void VNA_Enable(void);
void VNA_Reset(void);
void VNA_EMeasurementTriggerCalculation(float sweep_value);

    
#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* PWM_H */

