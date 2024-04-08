/*
 * File:   interrupt_manager.h
 * Author: Ro-Beast Battle Busters (with assistance from the MCC)
 */

#ifndef _INTERRUPT_MANAGER_H
#define _INTERRUPT_MANAGER_H

void INTERRUPT_Initialize(void);

inline static void INTERRUPT_GlobalEnable(void)
{
    __builtin_enable_interrupts();
}

inline static void INTERRUPT_GlobalDisable(void)
{
    __builtin_disable_interrupts();
}

inline static uint16_t INTERRUPT_VectorNumberGet(void)
{
    return _VECNUM; 
}

#endif /* _INTERRUPT_MANAGER_H */