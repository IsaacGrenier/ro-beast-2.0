/*
 * File:   traps.c
 * Author: Ro-Beast Battle Busters (with assistance from the MCC)
 */

#include <xc.h>
#include "traps.h"

#define ERROR_HANDLER __attribute__((interrupt, no_auto_psv, keep, section("error_handler")))
#define FAILSAFE_STACK_GUARDSIZE 8

/**
 * a private place to store the error code if we run into a severe error
 */
static uint16_t TRAPS_error_code = -1;

/**
 * Halts 
 * 
 * @param code error code
 */
void __attribute__((weak)) TRAPS_halt_on_error(uint16_t code)
{
    TRAPS_error_code = code;
#ifdef __DEBUG    
    __builtin_software_breakpoint();
    /* If we are in debug mode, cause a software breakpoint in the debugger */
#endif
    while(1);
    
}

/**
 * Sets the stack pointer to a backup area of memory, in case we run into
 * a stack error (in which case we can't really trust the stack pointer)
 */
inline static void use_failsafe_stack(void)
{
    static uint8_t failsafe_stack[32];
    asm volatile (
        "   mov    %[pstack], W15\n"
        :
        : [pstack]"r"(failsafe_stack)
    );
/* Controls where the stack pointer limit is, relative to the end of the
 * failsafe stack
 */    
    SPLIM = (uint16_t)(((uint8_t *)failsafe_stack) + sizeof(failsafe_stack) 
            - FAILSAFE_STACK_GUARDSIZE);
}


/** Oscillator Fail Trap vector**/
void ERROR_HANDLER _OscillatorFail(void)
{
    INTCON1bits.OSCFAIL = 0;  //Clear the trap flag
    TRAPS_halt_on_error(TRAPS_OSC_FAIL);
}
/** Stack Error Trap Vector**/
void ERROR_HANDLER _StackError(void)
{
    /* We use a failsafe stack: the presence of a stack-pointer error
     * means that we cannot trust the stack to operate correctly unless
     * we set the stack pointer to a safe place.
     */
    use_failsafe_stack(); 
    INTCON1bits.STKERR = 0;  //Clear the trap flag
    TRAPS_halt_on_error(TRAPS_STACK_ERR);
}
/** Address error Trap vector**/
void ERROR_HANDLER _AddressError(void)
{
    INTCON1bits.ADDRERR = 0;  //Clear the trap flag
    TRAPS_halt_on_error(TRAPS_ADDRESS_ERR);
}
/** Math Error Trap vector**/
void ERROR_HANDLER _MathError(void)
{
    INTCON1bits.MATHERR = 0;  //Clear the trap flag
    TRAPS_halt_on_error(TRAPS_MATH_ERR);
}
/** Generic Hard Trap vector**/
void ERROR_HANDLER _HardTrapError(void)
{
    INTCON4bits.SGHT = 0;  //Clear the trap flag
    TRAPS_halt_on_error(TRAPS_HARD_ERR);
}
/** Generic Soft Trap vector**/
void ERROR_HANDLER _SoftTrapError(void)
{
    if(INTCON3bits.NAE)
    {
      INTCON3bits.NAE = 0;  //Clear the trap flag
      TRAPS_halt_on_error(TRAPS_NVM_ERR);
    }

#ifdef _DMT
    if(INTCON3bits.DMT)
    {
      INTCON3bits.DMT = 0;  //Clear the trap flag
      TRAPS_halt_on_error(TRAPS_DMT_ERR);
    }

#endif
#ifdef _DAE
    if(INTCON3bits.DAE)
    {
      INTCON3bits.DAE = 0;  //Clear the trap flag
      TRAPS_halt_on_error(TRAPS_DAE_ERR);
    }

#endif
    if(INTCON3bits.DOOVR)
    {
      INTCON3bits.DOOVR = 0;  //Clear the trap flag
      TRAPS_halt_on_error(TRAPS_DOOVR_ERR);
    }

    if(INTCON3bits.APLL)
    {
      INTCON3bits.APLL = 0;  //Clear the trap flag
      TRAPS_halt_on_error(TRAPS_APLL_ERR);
    }

    while(1);
}
