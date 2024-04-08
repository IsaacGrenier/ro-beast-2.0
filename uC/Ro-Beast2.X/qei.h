/*
 * File:   qei.h
 * Author: Ro-Beast Battle Busters
 */

#ifndef QEI_H
#define	QEI_H

#ifdef	__cplusplus
extern "C" {
#endif 

void QEI_Initialize(void);
void QEI_CounterClear(void);
void QEI_CounterSet(float range);
void QEI_Feedback(void);
void vreg_5V_enable(void);
void vreg_5V_disable(void);
void VNA_AMeasurementTriggerCalculation(float sweep_value);


#ifdef	__cplusplus
}
#endif

#endif	// QEI_H