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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Ejemplo9_DSP.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Ejemplo9_DSP.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=ADC_dspic.c Configuracion.c I2C_dspic.c Timer_dsPIC.c main.c lowpassexample.s

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/ADC_dspic.o ${OBJECTDIR}/Configuracion.o ${OBJECTDIR}/I2C_dspic.o ${OBJECTDIR}/Timer_dsPIC.o ${OBJECTDIR}/main.o ${OBJECTDIR}/lowpassexample.o
POSSIBLE_DEPFILES=${OBJECTDIR}/ADC_dspic.o.d ${OBJECTDIR}/Configuracion.o.d ${OBJECTDIR}/I2C_dspic.o.d ${OBJECTDIR}/Timer_dsPIC.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/lowpassexample.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/ADC_dspic.o ${OBJECTDIR}/Configuracion.o ${OBJECTDIR}/I2C_dspic.o ${OBJECTDIR}/Timer_dsPIC.o ${OBJECTDIR}/main.o ${OBJECTDIR}/lowpassexample.o

# Source Files
SOURCEFILES=ADC_dspic.c Configuracion.c I2C_dspic.c Timer_dsPIC.c main.c lowpassexample.s



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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Ejemplo9_DSP.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33FJ32MC202
MP_LINKER_FILE_OPTION=,--script=p33FJ32MC202.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/ADC_dspic.o: ADC_dspic.c  .generated_files/8a9145dcf06d2f40bab67a0f2b5ff0ce24811748.flag .generated_files/b7541f3291fe7b63cd41edb6d34186dc81c6e08b.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ADC_dspic.o.d 
	@${RM} ${OBJECTDIR}/ADC_dspic.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ADC_dspic.c  -o ${OBJECTDIR}/ADC_dspic.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/ADC_dspic.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Configuracion.o: Configuracion.c  .generated_files/25c5d83a3597a874d3b2b4d2ef5fa9cbc7d4b014.flag .generated_files/b7541f3291fe7b63cd41edb6d34186dc81c6e08b.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Configuracion.o.d 
	@${RM} ${OBJECTDIR}/Configuracion.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Configuracion.c  -o ${OBJECTDIR}/Configuracion.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Configuracion.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/I2C_dspic.o: I2C_dspic.c  .generated_files/6746675cb245ac22e6223219bfa3bb4cdfd2068e.flag .generated_files/b7541f3291fe7b63cd41edb6d34186dc81c6e08b.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/I2C_dspic.o.d 
	@${RM} ${OBJECTDIR}/I2C_dspic.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  I2C_dspic.c  -o ${OBJECTDIR}/I2C_dspic.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/I2C_dspic.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Timer_dsPIC.o: Timer_dsPIC.c  .generated_files/92bd60eb2390523b1d7773888f63232ee821313.flag .generated_files/b7541f3291fe7b63cd41edb6d34186dc81c6e08b.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Timer_dsPIC.o.d 
	@${RM} ${OBJECTDIR}/Timer_dsPIC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Timer_dsPIC.c  -o ${OBJECTDIR}/Timer_dsPIC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Timer_dsPIC.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/41c0e84f05bd2f61fe405611ec5169736291acee.flag .generated_files/b7541f3291fe7b63cd41edb6d34186dc81c6e08b.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/ADC_dspic.o: ADC_dspic.c  .generated_files/29913a5b4cfe92f2085401949d436a41c8a5a575.flag .generated_files/b7541f3291fe7b63cd41edb6d34186dc81c6e08b.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ADC_dspic.o.d 
	@${RM} ${OBJECTDIR}/ADC_dspic.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ADC_dspic.c  -o ${OBJECTDIR}/ADC_dspic.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/ADC_dspic.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Configuracion.o: Configuracion.c  .generated_files/db6854f2b6b25160d81301c88971ed4a5cd5c506.flag .generated_files/b7541f3291fe7b63cd41edb6d34186dc81c6e08b.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Configuracion.o.d 
	@${RM} ${OBJECTDIR}/Configuracion.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Configuracion.c  -o ${OBJECTDIR}/Configuracion.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Configuracion.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/I2C_dspic.o: I2C_dspic.c  .generated_files/3713a3bdc66a219371c668dc33c20c4f9070b287.flag .generated_files/b7541f3291fe7b63cd41edb6d34186dc81c6e08b.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/I2C_dspic.o.d 
	@${RM} ${OBJECTDIR}/I2C_dspic.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  I2C_dspic.c  -o ${OBJECTDIR}/I2C_dspic.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/I2C_dspic.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Timer_dsPIC.o: Timer_dsPIC.c  .generated_files/8ef0d78d1030499ef983245059948e5c4eb4d61e.flag .generated_files/b7541f3291fe7b63cd41edb6d34186dc81c6e08b.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Timer_dsPIC.o.d 
	@${RM} ${OBJECTDIR}/Timer_dsPIC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Timer_dsPIC.c  -o ${OBJECTDIR}/Timer_dsPIC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Timer_dsPIC.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/87259ec24260413dd02699ddfdd7cc3c0a1a8e54.flag .generated_files/b7541f3291fe7b63cd41edb6d34186dc81c6e08b.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/lowpassexample.o: lowpassexample.s  .generated_files/2b895301fc02f126312b5f407ea2e77ff3e3851a.flag .generated_files/b7541f3291fe7b63cd41edb6d34186dc81c6e08b.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/lowpassexample.o.d 
	@${RM} ${OBJECTDIR}/lowpassexample.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  lowpassexample.s  -o ${OBJECTDIR}/lowpassexample.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG   -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/lowpassexample.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/lowpassexample.o: lowpassexample.s  .generated_files/b367838bb14fc6bbdf3c97424027402a93384403.flag .generated_files/b7541f3291fe7b63cd41edb6d34186dc81c6e08b.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/lowpassexample.o.d 
	@${RM} ${OBJECTDIR}/lowpassexample.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  lowpassexample.s  -o ${OBJECTDIR}/lowpassexample.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/lowpassexample.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Ejemplo9_DSP.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Ejemplo9_DSP.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG   -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)      -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml,--library,dsp$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Ejemplo9_DSP.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Ejemplo9_DSP.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml,--library,dsp$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/Ejemplo9_DSP.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
