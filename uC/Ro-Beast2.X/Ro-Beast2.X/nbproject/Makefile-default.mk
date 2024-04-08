#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Ro-Beast2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Ro-Beast2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=main.c timer.c global_variables.c system.c state_select.c uart.c pin_manager.c clock.c interrupt_manager.c traps.c qei.c inputs.c pwm.c tmr1.c adc.c driver.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/main.o ${OBJECTDIR}/timer.o ${OBJECTDIR}/global_variables.o ${OBJECTDIR}/system.o ${OBJECTDIR}/state_select.o ${OBJECTDIR}/uart.o ${OBJECTDIR}/pin_manager.o ${OBJECTDIR}/clock.o ${OBJECTDIR}/interrupt_manager.o ${OBJECTDIR}/traps.o ${OBJECTDIR}/qei.o ${OBJECTDIR}/inputs.o ${OBJECTDIR}/pwm.o ${OBJECTDIR}/tmr1.o ${OBJECTDIR}/adc.o ${OBJECTDIR}/driver.o
POSSIBLE_DEPFILES=${OBJECTDIR}/main.o.d ${OBJECTDIR}/timer.o.d ${OBJECTDIR}/global_variables.o.d ${OBJECTDIR}/system.o.d ${OBJECTDIR}/state_select.o.d ${OBJECTDIR}/uart.o.d ${OBJECTDIR}/pin_manager.o.d ${OBJECTDIR}/clock.o.d ${OBJECTDIR}/interrupt_manager.o.d ${OBJECTDIR}/traps.o.d ${OBJECTDIR}/qei.o.d ${OBJECTDIR}/inputs.o.d ${OBJECTDIR}/pwm.o.d ${OBJECTDIR}/tmr1.o.d ${OBJECTDIR}/adc.o.d ${OBJECTDIR}/driver.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/main.o ${OBJECTDIR}/timer.o ${OBJECTDIR}/global_variables.o ${OBJECTDIR}/system.o ${OBJECTDIR}/state_select.o ${OBJECTDIR}/uart.o ${OBJECTDIR}/pin_manager.o ${OBJECTDIR}/clock.o ${OBJECTDIR}/interrupt_manager.o ${OBJECTDIR}/traps.o ${OBJECTDIR}/qei.o ${OBJECTDIR}/inputs.o ${OBJECTDIR}/pwm.o ${OBJECTDIR}/tmr1.o ${OBJECTDIR}/adc.o ${OBJECTDIR}/driver.o

# Source Files
SOURCEFILES=main.c timer.c global_variables.c system.c state_select.c uart.c pin_manager.c clock.c interrupt_manager.c traps.c qei.c inputs.c pwm.c tmr1.c adc.c driver.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/Ro-Beast2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33CK64MP505
MP_LINKER_FILE_OPTION=,--script=p33CK64MP505.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/ee49d041dca82c661374f09d97f21ec208bdcdbb .generated_files/flags/default/8bf8bc0182799842b3129ea7dc64f5e361f25132
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/timer.o: timer.c  .generated_files/flags/default/1bcf3be344e57c47589f9dc5ca92bffabec3265b .generated_files/flags/default/8bf8bc0182799842b3129ea7dc64f5e361f25132
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/timer.o.d 
	@${RM} ${OBJECTDIR}/timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  timer.c  -o ${OBJECTDIR}/timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/timer.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/global_variables.o: global_variables.c  .generated_files/flags/default/363e1d132e1305a170d208635a0010b23645101e .generated_files/flags/default/8bf8bc0182799842b3129ea7dc64f5e361f25132
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/global_variables.o.d 
	@${RM} ${OBJECTDIR}/global_variables.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  global_variables.c  -o ${OBJECTDIR}/global_variables.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/global_variables.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/system.o: system.c  .generated_files/flags/default/f0de45206a0552389749501fa0db4c9b19863844 .generated_files/flags/default/8bf8bc0182799842b3129ea7dc64f5e361f25132
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/system.o.d 
	@${RM} ${OBJECTDIR}/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system.c  -o ${OBJECTDIR}/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/system.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/state_select.o: state_select.c  .generated_files/flags/default/1471f9110bee0dc512be0e8e3d4848a2533006c5 .generated_files/flags/default/8bf8bc0182799842b3129ea7dc64f5e361f25132
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/state_select.o.d 
	@${RM} ${OBJECTDIR}/state_select.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  state_select.c  -o ${OBJECTDIR}/state_select.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/state_select.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/uart.o: uart.c  .generated_files/flags/default/8a3b9f4163963588e5cf1ead036493026dbaef00 .generated_files/flags/default/8bf8bc0182799842b3129ea7dc64f5e361f25132
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/uart.o.d 
	@${RM} ${OBJECTDIR}/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  uart.c  -o ${OBJECTDIR}/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/uart.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/pin_manager.o: pin_manager.c  .generated_files/flags/default/5d0140ea84ddfe227fc61384086c8a6068b1098a .generated_files/flags/default/8bf8bc0182799842b3129ea7dc64f5e361f25132
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/pin_manager.o.d 
	@${RM} ${OBJECTDIR}/pin_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  pin_manager.c  -o ${OBJECTDIR}/pin_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/pin_manager.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/clock.o: clock.c  .generated_files/flags/default/f284428f2101361f65b00e1d1970c81e1ff0278b .generated_files/flags/default/8bf8bc0182799842b3129ea7dc64f5e361f25132
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/clock.o.d 
	@${RM} ${OBJECTDIR}/clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  clock.c  -o ${OBJECTDIR}/clock.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/clock.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/interrupt_manager.o: interrupt_manager.c  .generated_files/flags/default/d4b8d139cdbf9761ac17ad423fcc7f25d67b822c .generated_files/flags/default/8bf8bc0182799842b3129ea7dc64f5e361f25132
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/interrupt_manager.o.d 
	@${RM} ${OBJECTDIR}/interrupt_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  interrupt_manager.c  -o ${OBJECTDIR}/interrupt_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/interrupt_manager.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/traps.o: traps.c  .generated_files/flags/default/a9abd7848f2f0d816db69e90e944855ebc04a40 .generated_files/flags/default/8bf8bc0182799842b3129ea7dc64f5e361f25132
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/traps.o.d 
	@${RM} ${OBJECTDIR}/traps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  traps.c  -o ${OBJECTDIR}/traps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/traps.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/qei.o: qei.c  .generated_files/flags/default/f257f3dd6b7ddc94d066a611403952b9865d7750 .generated_files/flags/default/8bf8bc0182799842b3129ea7dc64f5e361f25132
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/qei.o.d 
	@${RM} ${OBJECTDIR}/qei.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  qei.c  -o ${OBJECTDIR}/qei.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/qei.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/inputs.o: inputs.c  .generated_files/flags/default/7878b54ab02dd4282ab93d57cfcc948deb7a4da2 .generated_files/flags/default/8bf8bc0182799842b3129ea7dc64f5e361f25132
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/inputs.o.d 
	@${RM} ${OBJECTDIR}/inputs.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  inputs.c  -o ${OBJECTDIR}/inputs.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/inputs.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/pwm.o: pwm.c  .generated_files/flags/default/ef45790decb381917501c2c9734acabf139b9e0e .generated_files/flags/default/8bf8bc0182799842b3129ea7dc64f5e361f25132
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/pwm.o.d 
	@${RM} ${OBJECTDIR}/pwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  pwm.c  -o ${OBJECTDIR}/pwm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/pwm.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/tmr1.o: tmr1.c  .generated_files/flags/default/293878a7e828b8fb8044bdebcb064eaef29bfa8 .generated_files/flags/default/8bf8bc0182799842b3129ea7dc64f5e361f25132
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/tmr1.o.d 
	@${RM} ${OBJECTDIR}/tmr1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  tmr1.c  -o ${OBJECTDIR}/tmr1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/tmr1.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/adc.o: adc.c  .generated_files/flags/default/a34e0527f6bfeec9c184e7c0be8c055d6273fdc5 .generated_files/flags/default/8bf8bc0182799842b3129ea7dc64f5e361f25132
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/adc.o.d 
	@${RM} ${OBJECTDIR}/adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  adc.c  -o ${OBJECTDIR}/adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/adc.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/driver.o: driver.c  .generated_files/flags/default/65aff2f9aaa79521476cf8fab5a4cc812ec4568c .generated_files/flags/default/8bf8bc0182799842b3129ea7dc64f5e361f25132
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/driver.o.d 
	@${RM} ${OBJECTDIR}/driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  driver.c  -o ${OBJECTDIR}/driver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/driver.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/1cb3196d7fe293d578b37071b371855e3a4afc88 .generated_files/flags/default/8bf8bc0182799842b3129ea7dc64f5e361f25132
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/timer.o: timer.c  .generated_files/flags/default/615888b1ebaa319c18a58f66f81dca088b08c9d8 .generated_files/flags/default/8bf8bc0182799842b3129ea7dc64f5e361f25132
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/timer.o.d 
	@${RM} ${OBJECTDIR}/timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  timer.c  -o ${OBJECTDIR}/timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/timer.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/global_variables.o: global_variables.c  .generated_files/flags/default/c1306e7989a7709ec1d9a99d9283651fdc62042f .generated_files/flags/default/8bf8bc0182799842b3129ea7dc64f5e361f25132
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/global_variables.o.d 
	@${RM} ${OBJECTDIR}/global_variables.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  global_variables.c  -o ${OBJECTDIR}/global_variables.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/global_variables.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/system.o: system.c  .generated_files/flags/default/c93a36195f92c95e82c1b64356be5ebd3e05e6e5 .generated_files/flags/default/8bf8bc0182799842b3129ea7dc64f5e361f25132
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/system.o.d 
	@${RM} ${OBJECTDIR}/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system.c  -o ${OBJECTDIR}/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/system.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/state_select.o: state_select.c  .generated_files/flags/default/45e35a69d739eff24fcb7c01cb9e228201412077 .generated_files/flags/default/8bf8bc0182799842b3129ea7dc64f5e361f25132
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/state_select.o.d 
	@${RM} ${OBJECTDIR}/state_select.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  state_select.c  -o ${OBJECTDIR}/state_select.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/state_select.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/uart.o: uart.c  .generated_files/flags/default/d38c6bb43bf876a2dad1ae6658022020e47660cd .generated_files/flags/default/8bf8bc0182799842b3129ea7dc64f5e361f25132
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/uart.o.d 
	@${RM} ${OBJECTDIR}/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  uart.c  -o ${OBJECTDIR}/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/uart.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/pin_manager.o: pin_manager.c  .generated_files/flags/default/5edd59e208aae327eedf754d1e7d10c68a6d8d10 .generated_files/flags/default/8bf8bc0182799842b3129ea7dc64f5e361f25132
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/pin_manager.o.d 
	@${RM} ${OBJECTDIR}/pin_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  pin_manager.c  -o ${OBJECTDIR}/pin_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/pin_manager.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/clock.o: clock.c  .generated_files/flags/default/e7af18700593f3a84d30d854d20fe72b7eb5d23d .generated_files/flags/default/8bf8bc0182799842b3129ea7dc64f5e361f25132
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/clock.o.d 
	@${RM} ${OBJECTDIR}/clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  clock.c  -o ${OBJECTDIR}/clock.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/clock.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/interrupt_manager.o: interrupt_manager.c  .generated_files/flags/default/4bb9ebc5bf805b40f280856e30f43015f3fc9e87 .generated_files/flags/default/8bf8bc0182799842b3129ea7dc64f5e361f25132
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/interrupt_manager.o.d 
	@${RM} ${OBJECTDIR}/interrupt_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  interrupt_manager.c  -o ${OBJECTDIR}/interrupt_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/interrupt_manager.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/traps.o: traps.c  .generated_files/flags/default/b0ec7ab663e9c8de3f866096600d24afc20edeb1 .generated_files/flags/default/8bf8bc0182799842b3129ea7dc64f5e361f25132
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/traps.o.d 
	@${RM} ${OBJECTDIR}/traps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  traps.c  -o ${OBJECTDIR}/traps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/traps.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/qei.o: qei.c  .generated_files/flags/default/17a7e0a3fe9dfe89f997c81f7ac850d30da8e4e0 .generated_files/flags/default/8bf8bc0182799842b3129ea7dc64f5e361f25132
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/qei.o.d 
	@${RM} ${OBJECTDIR}/qei.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  qei.c  -o ${OBJECTDIR}/qei.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/qei.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/inputs.o: inputs.c  .generated_files/flags/default/e5f42807684b31bb0fd043ef57c664c924ccbf21 .generated_files/flags/default/8bf8bc0182799842b3129ea7dc64f5e361f25132
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/inputs.o.d 
	@${RM} ${OBJECTDIR}/inputs.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  inputs.c  -o ${OBJECTDIR}/inputs.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/inputs.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/pwm.o: pwm.c  .generated_files/flags/default/48e5916c2edc0bdae87c9e1cc7e96bf03f0aa4a3 .generated_files/flags/default/8bf8bc0182799842b3129ea7dc64f5e361f25132
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/pwm.o.d 
	@${RM} ${OBJECTDIR}/pwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  pwm.c  -o ${OBJECTDIR}/pwm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/pwm.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/tmr1.o: tmr1.c  .generated_files/flags/default/5794b5c2c4af6e22b03aa52329e64f22888f998e .generated_files/flags/default/8bf8bc0182799842b3129ea7dc64f5e361f25132
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/tmr1.o.d 
	@${RM} ${OBJECTDIR}/tmr1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  tmr1.c  -o ${OBJECTDIR}/tmr1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/tmr1.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/adc.o: adc.c  .generated_files/flags/default/31e672d559094df944cf82daf75c2ab9fabedeee .generated_files/flags/default/8bf8bc0182799842b3129ea7dc64f5e361f25132
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/adc.o.d 
	@${RM} ${OBJECTDIR}/adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  adc.c  -o ${OBJECTDIR}/adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/adc.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/driver.o: driver.c  .generated_files/flags/default/5e22c3f63adc67dbecac3afc11a8872c88be6f2c .generated_files/flags/default/8bf8bc0182799842b3129ea7dc64f5e361f25132
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/driver.o.d 
	@${RM} ${OBJECTDIR}/driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  driver.c  -o ${OBJECTDIR}/driver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/driver.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/Ro-Beast2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/Ro-Beast2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG   -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -mreserve=data@0x1000:0x101B -mreserve=data@0x101C:0x101D -mreserve=data@0x101E:0x101F -mreserve=data@0x1020:0x1021 -mreserve=data@0x1022:0x1023 -mreserve=data@0x1024:0x1027 -mreserve=data@0x1028:0x104F   -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
${DISTDIR}/Ro-Beast2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/Ro-Beast2.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex ${DISTDIR}/Ro-Beast2.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
