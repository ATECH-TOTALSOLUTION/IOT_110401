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
ifeq "$(wildcard nbproject/Makefile-local-sam_c21n_xpro.mk)" "nbproject/Makefile-local-sam_c21n_xpro.mk"
include nbproject/Makefile-local-sam_c21n_xpro.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=sam_c21n_xpro
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/sam_c21n_xpro.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/sam_c21n_xpro.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../src/appiot.c ../src/moden.c ../src/canapp.c ../src/appuart.c ../src/appemueeprom.c ../src/apptimer.c ../src/app_uart_debug.c ../src/config/sam_c21n_xpro/driver/at24/src/drv_at24.c ../src/config/sam_c21n_xpro/driver/usart/src/drv_usart.c ../src/config/sam_c21n_xpro/library/emulated_eeprom/emulated_eeprom.c ../src/config/sam_c21n_xpro/peripheral/adc/plib_adc0.c ../src/config/sam_c21n_xpro/peripheral/can/plib_can0.c ../src/config/sam_c21n_xpro/peripheral/clock/plib_clock.c ../src/config/sam_c21n_xpro/peripheral/eic/plib_eic.c ../src/config/sam_c21n_xpro/peripheral/evsys/plib_evsys.c ../src/config/sam_c21n_xpro/peripheral/nvic/plib_nvic.c ../src/config/sam_c21n_xpro/peripheral/nvmctrl/plib_nvmctrl.c ../src/config/sam_c21n_xpro/peripheral/port/plib_port.c ../src/config/sam_c21n_xpro/peripheral/sercom/i2c_master/plib_sercom2_i2c_master.c ../src/config/sam_c21n_xpro/peripheral/sercom/usart/plib_sercom1_usart.c ../src/config/sam_c21n_xpro/peripheral/sercom/usart/plib_sercom0_usart.c ../src/config/sam_c21n_xpro/peripheral/systick/plib_systick.c ../src/config/sam_c21n_xpro/peripheral/wdt/plib_wdt.c ../src/config/sam_c21n_xpro/stdio/xc32_monitor.c ../src/config/sam_c21n_xpro/system/int/src/sys_int.c ../src/config/sam_c21n_xpro/initialization.c ../src/config/sam_c21n_xpro/interrupts.c ../src/config/sam_c21n_xpro/exceptions.c ../src/config/sam_c21n_xpro/startup_xc32.c ../src/config/sam_c21n_xpro/libc_syscalls.c ../src/config/sam_c21n_xpro/tasks.c ../src/main.c ../src/app.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1360937237/appiot.o ${OBJECTDIR}/_ext/1360937237/moden.o ${OBJECTDIR}/_ext/1360937237/canapp.o ${OBJECTDIR}/_ext/1360937237/appuart.o ${OBJECTDIR}/_ext/1360937237/appemueeprom.o ${OBJECTDIR}/_ext/1360937237/apptimer.o ${OBJECTDIR}/_ext/1360937237/app_uart_debug.o ${OBJECTDIR}/_ext/1936826263/drv_at24.o ${OBJECTDIR}/_ext/1274584173/drv_usart.o ${OBJECTDIR}/_ext/1019481632/emulated_eeprom.o ${OBJECTDIR}/_ext/1617700295/plib_adc0.o ${OBJECTDIR}/_ext/1617702135/plib_can0.o ${OBJECTDIR}/_ext/166077579/plib_clock.o ${OBJECTDIR}/_ext/1617704294/plib_eic.o ${OBJECTDIR}/_ext/163928093/plib_evsys.o ${OBJECTDIR}/_ext/1390493541/plib_nvic.o ${OBJECTDIR}/_ext/770299191/plib_nvmctrl.o ${OBJECTDIR}/_ext/1390440390/plib_port.o ${OBJECTDIR}/_ext/1451668420/plib_sercom2_i2c_master.o ${OBJECTDIR}/_ext/1993392304/plib_sercom1_usart.o ${OBJECTDIR}/_ext/1993392304/plib_sercom0_usart.o ${OBJECTDIR}/_ext/1004774289/plib_systick.o ${OBJECTDIR}/_ext/1617721454/plib_wdt.o ${OBJECTDIR}/_ext/730014449/xc32_monitor.o ${OBJECTDIR}/_ext/855761890/sys_int.o ${OBJECTDIR}/_ext/1758384875/initialization.o ${OBJECTDIR}/_ext/1758384875/interrupts.o ${OBJECTDIR}/_ext/1758384875/exceptions.o ${OBJECTDIR}/_ext/1758384875/startup_xc32.o ${OBJECTDIR}/_ext/1758384875/libc_syscalls.o ${OBJECTDIR}/_ext/1758384875/tasks.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1360937237/app.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1360937237/appiot.o.d ${OBJECTDIR}/_ext/1360937237/moden.o.d ${OBJECTDIR}/_ext/1360937237/canapp.o.d ${OBJECTDIR}/_ext/1360937237/appuart.o.d ${OBJECTDIR}/_ext/1360937237/appemueeprom.o.d ${OBJECTDIR}/_ext/1360937237/apptimer.o.d ${OBJECTDIR}/_ext/1360937237/app_uart_debug.o.d ${OBJECTDIR}/_ext/1936826263/drv_at24.o.d ${OBJECTDIR}/_ext/1274584173/drv_usart.o.d ${OBJECTDIR}/_ext/1019481632/emulated_eeprom.o.d ${OBJECTDIR}/_ext/1617700295/plib_adc0.o.d ${OBJECTDIR}/_ext/1617702135/plib_can0.o.d ${OBJECTDIR}/_ext/166077579/plib_clock.o.d ${OBJECTDIR}/_ext/1617704294/plib_eic.o.d ${OBJECTDIR}/_ext/163928093/plib_evsys.o.d ${OBJECTDIR}/_ext/1390493541/plib_nvic.o.d ${OBJECTDIR}/_ext/770299191/plib_nvmctrl.o.d ${OBJECTDIR}/_ext/1390440390/plib_port.o.d ${OBJECTDIR}/_ext/1451668420/plib_sercom2_i2c_master.o.d ${OBJECTDIR}/_ext/1993392304/plib_sercom1_usart.o.d ${OBJECTDIR}/_ext/1993392304/plib_sercom0_usart.o.d ${OBJECTDIR}/_ext/1004774289/plib_systick.o.d ${OBJECTDIR}/_ext/1617721454/plib_wdt.o.d ${OBJECTDIR}/_ext/730014449/xc32_monitor.o.d ${OBJECTDIR}/_ext/855761890/sys_int.o.d ${OBJECTDIR}/_ext/1758384875/initialization.o.d ${OBJECTDIR}/_ext/1758384875/interrupts.o.d ${OBJECTDIR}/_ext/1758384875/exceptions.o.d ${OBJECTDIR}/_ext/1758384875/startup_xc32.o.d ${OBJECTDIR}/_ext/1758384875/libc_syscalls.o.d ${OBJECTDIR}/_ext/1758384875/tasks.o.d ${OBJECTDIR}/_ext/1360937237/main.o.d ${OBJECTDIR}/_ext/1360937237/app.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1360937237/appiot.o ${OBJECTDIR}/_ext/1360937237/moden.o ${OBJECTDIR}/_ext/1360937237/canapp.o ${OBJECTDIR}/_ext/1360937237/appuart.o ${OBJECTDIR}/_ext/1360937237/appemueeprom.o ${OBJECTDIR}/_ext/1360937237/apptimer.o ${OBJECTDIR}/_ext/1360937237/app_uart_debug.o ${OBJECTDIR}/_ext/1936826263/drv_at24.o ${OBJECTDIR}/_ext/1274584173/drv_usart.o ${OBJECTDIR}/_ext/1019481632/emulated_eeprom.o ${OBJECTDIR}/_ext/1617700295/plib_adc0.o ${OBJECTDIR}/_ext/1617702135/plib_can0.o ${OBJECTDIR}/_ext/166077579/plib_clock.o ${OBJECTDIR}/_ext/1617704294/plib_eic.o ${OBJECTDIR}/_ext/163928093/plib_evsys.o ${OBJECTDIR}/_ext/1390493541/plib_nvic.o ${OBJECTDIR}/_ext/770299191/plib_nvmctrl.o ${OBJECTDIR}/_ext/1390440390/plib_port.o ${OBJECTDIR}/_ext/1451668420/plib_sercom2_i2c_master.o ${OBJECTDIR}/_ext/1993392304/plib_sercom1_usart.o ${OBJECTDIR}/_ext/1993392304/plib_sercom0_usart.o ${OBJECTDIR}/_ext/1004774289/plib_systick.o ${OBJECTDIR}/_ext/1617721454/plib_wdt.o ${OBJECTDIR}/_ext/730014449/xc32_monitor.o ${OBJECTDIR}/_ext/855761890/sys_int.o ${OBJECTDIR}/_ext/1758384875/initialization.o ${OBJECTDIR}/_ext/1758384875/interrupts.o ${OBJECTDIR}/_ext/1758384875/exceptions.o ${OBJECTDIR}/_ext/1758384875/startup_xc32.o ${OBJECTDIR}/_ext/1758384875/libc_syscalls.o ${OBJECTDIR}/_ext/1758384875/tasks.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1360937237/app.o

# Source Files
SOURCEFILES=../src/appiot.c ../src/moden.c ../src/canapp.c ../src/appuart.c ../src/appemueeprom.c ../src/apptimer.c ../src/app_uart_debug.c ../src/config/sam_c21n_xpro/driver/at24/src/drv_at24.c ../src/config/sam_c21n_xpro/driver/usart/src/drv_usart.c ../src/config/sam_c21n_xpro/library/emulated_eeprom/emulated_eeprom.c ../src/config/sam_c21n_xpro/peripheral/adc/plib_adc0.c ../src/config/sam_c21n_xpro/peripheral/can/plib_can0.c ../src/config/sam_c21n_xpro/peripheral/clock/plib_clock.c ../src/config/sam_c21n_xpro/peripheral/eic/plib_eic.c ../src/config/sam_c21n_xpro/peripheral/evsys/plib_evsys.c ../src/config/sam_c21n_xpro/peripheral/nvic/plib_nvic.c ../src/config/sam_c21n_xpro/peripheral/nvmctrl/plib_nvmctrl.c ../src/config/sam_c21n_xpro/peripheral/port/plib_port.c ../src/config/sam_c21n_xpro/peripheral/sercom/i2c_master/plib_sercom2_i2c_master.c ../src/config/sam_c21n_xpro/peripheral/sercom/usart/plib_sercom1_usart.c ../src/config/sam_c21n_xpro/peripheral/sercom/usart/plib_sercom0_usart.c ../src/config/sam_c21n_xpro/peripheral/systick/plib_systick.c ../src/config/sam_c21n_xpro/peripheral/wdt/plib_wdt.c ../src/config/sam_c21n_xpro/stdio/xc32_monitor.c ../src/config/sam_c21n_xpro/system/int/src/sys_int.c ../src/config/sam_c21n_xpro/initialization.c ../src/config/sam_c21n_xpro/interrupts.c ../src/config/sam_c21n_xpro/exceptions.c ../src/config/sam_c21n_xpro/startup_xc32.c ../src/config/sam_c21n_xpro/libc_syscalls.c ../src/config/sam_c21n_xpro/tasks.c ../src/main.c ../src/app.c

# Pack Options 
PACK_COMMON_OPTIONS=-I "${CMSIS_DIR}/CMSIS/Core/Include"



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
	${MAKE}  -f nbproject/Makefile-sam_c21n_xpro.mk ${DISTDIR}/sam_c21n_xpro.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=ATSAMC21E18A
MP_LINKER_FILE_OPTION=,--script="..\src\config\sam_c21n_xpro\ATSAMC21E18A.ld"
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1360937237/appiot.o: ../src/appiot.c  .generated_files/flags/sam_c21n_xpro/cca69f5bf530d86a0393bf404944945a3d9eea8a .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/appiot.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/appiot.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/appiot.o.d" -o ${OBJECTDIR}/_ext/1360937237/appiot.o ../src/appiot.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/moden.o: ../src/moden.c  .generated_files/flags/sam_c21n_xpro/ef58dfc05af12c6a15e9461cc926df1d552456e .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/moden.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/moden.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/moden.o.d" -o ${OBJECTDIR}/_ext/1360937237/moden.o ../src/moden.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/canapp.o: ../src/canapp.c  .generated_files/flags/sam_c21n_xpro/3ba58eba47313b9b8a5e7a9a7fad13614f650baa .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/canapp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/canapp.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/canapp.o.d" -o ${OBJECTDIR}/_ext/1360937237/canapp.o ../src/canapp.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/appuart.o: ../src/appuart.c  .generated_files/flags/sam_c21n_xpro/29d06fa9fd428c3f976c5d70d4fc517915a04b72 .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/appuart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/appuart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/appuart.o.d" -o ${OBJECTDIR}/_ext/1360937237/appuart.o ../src/appuart.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/appemueeprom.o: ../src/appemueeprom.c  .generated_files/flags/sam_c21n_xpro/11b5d25a8ab090a35a6748dd10f4419f38bf3346 .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/appemueeprom.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/appemueeprom.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/appemueeprom.o.d" -o ${OBJECTDIR}/_ext/1360937237/appemueeprom.o ../src/appemueeprom.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/apptimer.o: ../src/apptimer.c  .generated_files/flags/sam_c21n_xpro/534270134f171ff59b161b2799f72745ada50dd4 .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/apptimer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/apptimer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/apptimer.o.d" -o ${OBJECTDIR}/_ext/1360937237/apptimer.o ../src/apptimer.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/app_uart_debug.o: ../src/app_uart_debug.c  .generated_files/flags/sam_c21n_xpro/3ad7ebfbc0375f72a2c2263933f00c0182ac7b47 .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app_uart_debug.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app_uart_debug.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/app_uart_debug.o.d" -o ${OBJECTDIR}/_ext/1360937237/app_uart_debug.o ../src/app_uart_debug.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1936826263/drv_at24.o: ../src/config/sam_c21n_xpro/driver/at24/src/drv_at24.c  .generated_files/flags/sam_c21n_xpro/e532986353499bd318dcb2af7e7ec94121ee2b14 .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1936826263" 
	@${RM} ${OBJECTDIR}/_ext/1936826263/drv_at24.o.d 
	@${RM} ${OBJECTDIR}/_ext/1936826263/drv_at24.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1936826263/drv_at24.o.d" -o ${OBJECTDIR}/_ext/1936826263/drv_at24.o ../src/config/sam_c21n_xpro/driver/at24/src/drv_at24.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1274584173/drv_usart.o: ../src/config/sam_c21n_xpro/driver/usart/src/drv_usart.c  .generated_files/flags/sam_c21n_xpro/e85a19ca1a250c2a54c43a6738ae0ec2fa0626a4 .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1274584173" 
	@${RM} ${OBJECTDIR}/_ext/1274584173/drv_usart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1274584173/drv_usart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1274584173/drv_usart.o.d" -o ${OBJECTDIR}/_ext/1274584173/drv_usart.o ../src/config/sam_c21n_xpro/driver/usart/src/drv_usart.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1019481632/emulated_eeprom.o: ../src/config/sam_c21n_xpro/library/emulated_eeprom/emulated_eeprom.c  .generated_files/flags/sam_c21n_xpro/a278907e325f58855245915a31e2575249ae2828 .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1019481632" 
	@${RM} ${OBJECTDIR}/_ext/1019481632/emulated_eeprom.o.d 
	@${RM} ${OBJECTDIR}/_ext/1019481632/emulated_eeprom.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1019481632/emulated_eeprom.o.d" -o ${OBJECTDIR}/_ext/1019481632/emulated_eeprom.o ../src/config/sam_c21n_xpro/library/emulated_eeprom/emulated_eeprom.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1617700295/plib_adc0.o: ../src/config/sam_c21n_xpro/peripheral/adc/plib_adc0.c  .generated_files/flags/sam_c21n_xpro/56af5363bfc1103d999a64a10d0861c942dcf801 .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1617700295" 
	@${RM} ${OBJECTDIR}/_ext/1617700295/plib_adc0.o.d 
	@${RM} ${OBJECTDIR}/_ext/1617700295/plib_adc0.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1617700295/plib_adc0.o.d" -o ${OBJECTDIR}/_ext/1617700295/plib_adc0.o ../src/config/sam_c21n_xpro/peripheral/adc/plib_adc0.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1617702135/plib_can0.o: ../src/config/sam_c21n_xpro/peripheral/can/plib_can0.c  .generated_files/flags/sam_c21n_xpro/e9516b0c14d4dfe76708b2b50b84110bea3a2377 .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1617702135" 
	@${RM} ${OBJECTDIR}/_ext/1617702135/plib_can0.o.d 
	@${RM} ${OBJECTDIR}/_ext/1617702135/plib_can0.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1617702135/plib_can0.o.d" -o ${OBJECTDIR}/_ext/1617702135/plib_can0.o ../src/config/sam_c21n_xpro/peripheral/can/plib_can0.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/166077579/plib_clock.o: ../src/config/sam_c21n_xpro/peripheral/clock/plib_clock.c  .generated_files/flags/sam_c21n_xpro/be5a401f545f527cc058986734b7a23d5d7db423 .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/166077579" 
	@${RM} ${OBJECTDIR}/_ext/166077579/plib_clock.o.d 
	@${RM} ${OBJECTDIR}/_ext/166077579/plib_clock.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/166077579/plib_clock.o.d" -o ${OBJECTDIR}/_ext/166077579/plib_clock.o ../src/config/sam_c21n_xpro/peripheral/clock/plib_clock.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1617704294/plib_eic.o: ../src/config/sam_c21n_xpro/peripheral/eic/plib_eic.c  .generated_files/flags/sam_c21n_xpro/979853d85e3eede3c607a071f990c1a678ee90f .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1617704294" 
	@${RM} ${OBJECTDIR}/_ext/1617704294/plib_eic.o.d 
	@${RM} ${OBJECTDIR}/_ext/1617704294/plib_eic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1617704294/plib_eic.o.d" -o ${OBJECTDIR}/_ext/1617704294/plib_eic.o ../src/config/sam_c21n_xpro/peripheral/eic/plib_eic.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/163928093/plib_evsys.o: ../src/config/sam_c21n_xpro/peripheral/evsys/plib_evsys.c  .generated_files/flags/sam_c21n_xpro/3bfae578e74e0b1165fcb230484fc63294c2327c .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/163928093" 
	@${RM} ${OBJECTDIR}/_ext/163928093/plib_evsys.o.d 
	@${RM} ${OBJECTDIR}/_ext/163928093/plib_evsys.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/163928093/plib_evsys.o.d" -o ${OBJECTDIR}/_ext/163928093/plib_evsys.o ../src/config/sam_c21n_xpro/peripheral/evsys/plib_evsys.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1390493541/plib_nvic.o: ../src/config/sam_c21n_xpro/peripheral/nvic/plib_nvic.c  .generated_files/flags/sam_c21n_xpro/4d49d21a65525fb85796a391287ebf5bf55abf1d .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1390493541" 
	@${RM} ${OBJECTDIR}/_ext/1390493541/plib_nvic.o.d 
	@${RM} ${OBJECTDIR}/_ext/1390493541/plib_nvic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1390493541/plib_nvic.o.d" -o ${OBJECTDIR}/_ext/1390493541/plib_nvic.o ../src/config/sam_c21n_xpro/peripheral/nvic/plib_nvic.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/770299191/plib_nvmctrl.o: ../src/config/sam_c21n_xpro/peripheral/nvmctrl/plib_nvmctrl.c  .generated_files/flags/sam_c21n_xpro/d83b200b084decf60be9b4a71830f3b21e23e8ad .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/770299191" 
	@${RM} ${OBJECTDIR}/_ext/770299191/plib_nvmctrl.o.d 
	@${RM} ${OBJECTDIR}/_ext/770299191/plib_nvmctrl.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/770299191/plib_nvmctrl.o.d" -o ${OBJECTDIR}/_ext/770299191/plib_nvmctrl.o ../src/config/sam_c21n_xpro/peripheral/nvmctrl/plib_nvmctrl.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1390440390/plib_port.o: ../src/config/sam_c21n_xpro/peripheral/port/plib_port.c  .generated_files/flags/sam_c21n_xpro/79237891d63ed19b2ecc1e79a39b3d6bd6a43b15 .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1390440390" 
	@${RM} ${OBJECTDIR}/_ext/1390440390/plib_port.o.d 
	@${RM} ${OBJECTDIR}/_ext/1390440390/plib_port.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1390440390/plib_port.o.d" -o ${OBJECTDIR}/_ext/1390440390/plib_port.o ../src/config/sam_c21n_xpro/peripheral/port/plib_port.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1451668420/plib_sercom2_i2c_master.o: ../src/config/sam_c21n_xpro/peripheral/sercom/i2c_master/plib_sercom2_i2c_master.c  .generated_files/flags/sam_c21n_xpro/3b9fd6857c42eac3d00cc7700e44af2e6ed6a1e4 .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1451668420" 
	@${RM} ${OBJECTDIR}/_ext/1451668420/plib_sercom2_i2c_master.o.d 
	@${RM} ${OBJECTDIR}/_ext/1451668420/plib_sercom2_i2c_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1451668420/plib_sercom2_i2c_master.o.d" -o ${OBJECTDIR}/_ext/1451668420/plib_sercom2_i2c_master.o ../src/config/sam_c21n_xpro/peripheral/sercom/i2c_master/plib_sercom2_i2c_master.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1993392304/plib_sercom1_usart.o: ../src/config/sam_c21n_xpro/peripheral/sercom/usart/plib_sercom1_usart.c  .generated_files/flags/sam_c21n_xpro/acc33231d03930000271089d58467e7198160417 .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1993392304" 
	@${RM} ${OBJECTDIR}/_ext/1993392304/plib_sercom1_usart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1993392304/plib_sercom1_usart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1993392304/plib_sercom1_usart.o.d" -o ${OBJECTDIR}/_ext/1993392304/plib_sercom1_usart.o ../src/config/sam_c21n_xpro/peripheral/sercom/usart/plib_sercom1_usart.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1993392304/plib_sercom0_usart.o: ../src/config/sam_c21n_xpro/peripheral/sercom/usart/plib_sercom0_usart.c  .generated_files/flags/sam_c21n_xpro/19ac32a28550ecc46dbaf8f1ea0f991d54433fef .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1993392304" 
	@${RM} ${OBJECTDIR}/_ext/1993392304/plib_sercom0_usart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1993392304/plib_sercom0_usart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1993392304/plib_sercom0_usart.o.d" -o ${OBJECTDIR}/_ext/1993392304/plib_sercom0_usart.o ../src/config/sam_c21n_xpro/peripheral/sercom/usart/plib_sercom0_usart.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1004774289/plib_systick.o: ../src/config/sam_c21n_xpro/peripheral/systick/plib_systick.c  .generated_files/flags/sam_c21n_xpro/184d4628ddbfda777e2cb730bebf28039bd8d52e .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1004774289" 
	@${RM} ${OBJECTDIR}/_ext/1004774289/plib_systick.o.d 
	@${RM} ${OBJECTDIR}/_ext/1004774289/plib_systick.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1004774289/plib_systick.o.d" -o ${OBJECTDIR}/_ext/1004774289/plib_systick.o ../src/config/sam_c21n_xpro/peripheral/systick/plib_systick.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1617721454/plib_wdt.o: ../src/config/sam_c21n_xpro/peripheral/wdt/plib_wdt.c  .generated_files/flags/sam_c21n_xpro/debf60b028af24d858c58d317ce2427c05230598 .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1617721454" 
	@${RM} ${OBJECTDIR}/_ext/1617721454/plib_wdt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1617721454/plib_wdt.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1617721454/plib_wdt.o.d" -o ${OBJECTDIR}/_ext/1617721454/plib_wdt.o ../src/config/sam_c21n_xpro/peripheral/wdt/plib_wdt.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/730014449/xc32_monitor.o: ../src/config/sam_c21n_xpro/stdio/xc32_monitor.c  .generated_files/flags/sam_c21n_xpro/d646d776e6cc69c1eb18ab57a13e17d029b553ea .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/730014449" 
	@${RM} ${OBJECTDIR}/_ext/730014449/xc32_monitor.o.d 
	@${RM} ${OBJECTDIR}/_ext/730014449/xc32_monitor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/730014449/xc32_monitor.o.d" -o ${OBJECTDIR}/_ext/730014449/xc32_monitor.o ../src/config/sam_c21n_xpro/stdio/xc32_monitor.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/855761890/sys_int.o: ../src/config/sam_c21n_xpro/system/int/src/sys_int.c  .generated_files/flags/sam_c21n_xpro/789c749a4661692e0866b3ae03f9460b95d6ab98 .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/855761890" 
	@${RM} ${OBJECTDIR}/_ext/855761890/sys_int.o.d 
	@${RM} ${OBJECTDIR}/_ext/855761890/sys_int.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/855761890/sys_int.o.d" -o ${OBJECTDIR}/_ext/855761890/sys_int.o ../src/config/sam_c21n_xpro/system/int/src/sys_int.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1758384875/initialization.o: ../src/config/sam_c21n_xpro/initialization.c  .generated_files/flags/sam_c21n_xpro/1f9df800993e88a9797827b32162f0e7214d4824 .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1758384875" 
	@${RM} ${OBJECTDIR}/_ext/1758384875/initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/1758384875/initialization.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1758384875/initialization.o.d" -o ${OBJECTDIR}/_ext/1758384875/initialization.o ../src/config/sam_c21n_xpro/initialization.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1758384875/interrupts.o: ../src/config/sam_c21n_xpro/interrupts.c  .generated_files/flags/sam_c21n_xpro/b0ea39edfffd891711b27dde96aa7b505f51100e .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1758384875" 
	@${RM} ${OBJECTDIR}/_ext/1758384875/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/1758384875/interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1758384875/interrupts.o.d" -o ${OBJECTDIR}/_ext/1758384875/interrupts.o ../src/config/sam_c21n_xpro/interrupts.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1758384875/exceptions.o: ../src/config/sam_c21n_xpro/exceptions.c  .generated_files/flags/sam_c21n_xpro/e085ed19f95994e995fee6fbe1e740e48d149e32 .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1758384875" 
	@${RM} ${OBJECTDIR}/_ext/1758384875/exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1758384875/exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1758384875/exceptions.o.d" -o ${OBJECTDIR}/_ext/1758384875/exceptions.o ../src/config/sam_c21n_xpro/exceptions.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1758384875/startup_xc32.o: ../src/config/sam_c21n_xpro/startup_xc32.c  .generated_files/flags/sam_c21n_xpro/5e76128bd17c5757826935703105b7788d6f59c5 .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1758384875" 
	@${RM} ${OBJECTDIR}/_ext/1758384875/startup_xc32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1758384875/startup_xc32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1758384875/startup_xc32.o.d" -o ${OBJECTDIR}/_ext/1758384875/startup_xc32.o ../src/config/sam_c21n_xpro/startup_xc32.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1758384875/libc_syscalls.o: ../src/config/sam_c21n_xpro/libc_syscalls.c  .generated_files/flags/sam_c21n_xpro/115b01e700548c9d669a4ec0394a887135041af6 .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1758384875" 
	@${RM} ${OBJECTDIR}/_ext/1758384875/libc_syscalls.o.d 
	@${RM} ${OBJECTDIR}/_ext/1758384875/libc_syscalls.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1758384875/libc_syscalls.o.d" -o ${OBJECTDIR}/_ext/1758384875/libc_syscalls.o ../src/config/sam_c21n_xpro/libc_syscalls.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1758384875/tasks.o: ../src/config/sam_c21n_xpro/tasks.c  .generated_files/flags/sam_c21n_xpro/b810330a11451c5de685c46e3a7adef896e10173 .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1758384875" 
	@${RM} ${OBJECTDIR}/_ext/1758384875/tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/1758384875/tasks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1758384875/tasks.o.d" -o ${OBJECTDIR}/_ext/1758384875/tasks.o ../src/config/sam_c21n_xpro/tasks.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/sam_c21n_xpro/d7d8b42026e5cc9e314cb280aef12591abc9840a .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/app.o: ../src/app.c  .generated_files/flags/sam_c21n_xpro/7d61984881acc8b66fec166b3ea45e0cf16ab7f5 .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/app.o.d" -o ${OBJECTDIR}/_ext/1360937237/app.o ../src/app.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
else
${OBJECTDIR}/_ext/1360937237/appiot.o: ../src/appiot.c  .generated_files/flags/sam_c21n_xpro/75734c351c7a6c357c5f32a5dd47f01b06e27620 .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/appiot.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/appiot.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/appiot.o.d" -o ${OBJECTDIR}/_ext/1360937237/appiot.o ../src/appiot.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/moden.o: ../src/moden.c  .generated_files/flags/sam_c21n_xpro/5ba6ba898f65b32fffedadd4d5ed5d0aed9ac1ee .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/moden.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/moden.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/moden.o.d" -o ${OBJECTDIR}/_ext/1360937237/moden.o ../src/moden.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/canapp.o: ../src/canapp.c  .generated_files/flags/sam_c21n_xpro/3ee61ee7bdc223a6c8dc99ae5629c59fe6705881 .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/canapp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/canapp.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/canapp.o.d" -o ${OBJECTDIR}/_ext/1360937237/canapp.o ../src/canapp.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/appuart.o: ../src/appuart.c  .generated_files/flags/sam_c21n_xpro/ad0d14937f30e3ee330fe0716be29d54dcfb6475 .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/appuart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/appuart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/appuart.o.d" -o ${OBJECTDIR}/_ext/1360937237/appuart.o ../src/appuart.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/appemueeprom.o: ../src/appemueeprom.c  .generated_files/flags/sam_c21n_xpro/e0f2289042e2694b393e55eb93d07958e8f13434 .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/appemueeprom.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/appemueeprom.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/appemueeprom.o.d" -o ${OBJECTDIR}/_ext/1360937237/appemueeprom.o ../src/appemueeprom.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/apptimer.o: ../src/apptimer.c  .generated_files/flags/sam_c21n_xpro/78fb66582c85f448806458e56c8683271ae2eb6a .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/apptimer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/apptimer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/apptimer.o.d" -o ${OBJECTDIR}/_ext/1360937237/apptimer.o ../src/apptimer.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/app_uart_debug.o: ../src/app_uart_debug.c  .generated_files/flags/sam_c21n_xpro/3044ba23ca4b94b7fc6d43d3c00a3203324ed2c2 .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app_uart_debug.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app_uart_debug.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/app_uart_debug.o.d" -o ${OBJECTDIR}/_ext/1360937237/app_uart_debug.o ../src/app_uart_debug.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1936826263/drv_at24.o: ../src/config/sam_c21n_xpro/driver/at24/src/drv_at24.c  .generated_files/flags/sam_c21n_xpro/d4177b7f4679bbe943f44aee4c91e3a4a6d5e80d .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1936826263" 
	@${RM} ${OBJECTDIR}/_ext/1936826263/drv_at24.o.d 
	@${RM} ${OBJECTDIR}/_ext/1936826263/drv_at24.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1936826263/drv_at24.o.d" -o ${OBJECTDIR}/_ext/1936826263/drv_at24.o ../src/config/sam_c21n_xpro/driver/at24/src/drv_at24.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1274584173/drv_usart.o: ../src/config/sam_c21n_xpro/driver/usart/src/drv_usart.c  .generated_files/flags/sam_c21n_xpro/172a095949e34d6c1726fa1443b77b80de5e3706 .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1274584173" 
	@${RM} ${OBJECTDIR}/_ext/1274584173/drv_usart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1274584173/drv_usart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1274584173/drv_usart.o.d" -o ${OBJECTDIR}/_ext/1274584173/drv_usart.o ../src/config/sam_c21n_xpro/driver/usart/src/drv_usart.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1019481632/emulated_eeprom.o: ../src/config/sam_c21n_xpro/library/emulated_eeprom/emulated_eeprom.c  .generated_files/flags/sam_c21n_xpro/5ba94fc607ab753edad9ba2b7529360677e183c1 .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1019481632" 
	@${RM} ${OBJECTDIR}/_ext/1019481632/emulated_eeprom.o.d 
	@${RM} ${OBJECTDIR}/_ext/1019481632/emulated_eeprom.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1019481632/emulated_eeprom.o.d" -o ${OBJECTDIR}/_ext/1019481632/emulated_eeprom.o ../src/config/sam_c21n_xpro/library/emulated_eeprom/emulated_eeprom.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1617700295/plib_adc0.o: ../src/config/sam_c21n_xpro/peripheral/adc/plib_adc0.c  .generated_files/flags/sam_c21n_xpro/79f361586a4e778cd970a0605c02c9fba9fa67ea .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1617700295" 
	@${RM} ${OBJECTDIR}/_ext/1617700295/plib_adc0.o.d 
	@${RM} ${OBJECTDIR}/_ext/1617700295/plib_adc0.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1617700295/plib_adc0.o.d" -o ${OBJECTDIR}/_ext/1617700295/plib_adc0.o ../src/config/sam_c21n_xpro/peripheral/adc/plib_adc0.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1617702135/plib_can0.o: ../src/config/sam_c21n_xpro/peripheral/can/plib_can0.c  .generated_files/flags/sam_c21n_xpro/ba09e4774946ac9a43c8e90b0c1ab3ea6ecf0278 .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1617702135" 
	@${RM} ${OBJECTDIR}/_ext/1617702135/plib_can0.o.d 
	@${RM} ${OBJECTDIR}/_ext/1617702135/plib_can0.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1617702135/plib_can0.o.d" -o ${OBJECTDIR}/_ext/1617702135/plib_can0.o ../src/config/sam_c21n_xpro/peripheral/can/plib_can0.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/166077579/plib_clock.o: ../src/config/sam_c21n_xpro/peripheral/clock/plib_clock.c  .generated_files/flags/sam_c21n_xpro/3e192c04b30f394a47b3385cfe9b30ca5b7579dd .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/166077579" 
	@${RM} ${OBJECTDIR}/_ext/166077579/plib_clock.o.d 
	@${RM} ${OBJECTDIR}/_ext/166077579/plib_clock.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/166077579/plib_clock.o.d" -o ${OBJECTDIR}/_ext/166077579/plib_clock.o ../src/config/sam_c21n_xpro/peripheral/clock/plib_clock.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1617704294/plib_eic.o: ../src/config/sam_c21n_xpro/peripheral/eic/plib_eic.c  .generated_files/flags/sam_c21n_xpro/e2322e7b1da6756e7fb919d2d241f478937cfc8f .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1617704294" 
	@${RM} ${OBJECTDIR}/_ext/1617704294/plib_eic.o.d 
	@${RM} ${OBJECTDIR}/_ext/1617704294/plib_eic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1617704294/plib_eic.o.d" -o ${OBJECTDIR}/_ext/1617704294/plib_eic.o ../src/config/sam_c21n_xpro/peripheral/eic/plib_eic.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/163928093/plib_evsys.o: ../src/config/sam_c21n_xpro/peripheral/evsys/plib_evsys.c  .generated_files/flags/sam_c21n_xpro/947a27d064c47b9bc99fdb398f9b9ba9e4bb2cdb .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/163928093" 
	@${RM} ${OBJECTDIR}/_ext/163928093/plib_evsys.o.d 
	@${RM} ${OBJECTDIR}/_ext/163928093/plib_evsys.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/163928093/plib_evsys.o.d" -o ${OBJECTDIR}/_ext/163928093/plib_evsys.o ../src/config/sam_c21n_xpro/peripheral/evsys/plib_evsys.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1390493541/plib_nvic.o: ../src/config/sam_c21n_xpro/peripheral/nvic/plib_nvic.c  .generated_files/flags/sam_c21n_xpro/5152234d58e4178306146977cc8a8f7579671e89 .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1390493541" 
	@${RM} ${OBJECTDIR}/_ext/1390493541/plib_nvic.o.d 
	@${RM} ${OBJECTDIR}/_ext/1390493541/plib_nvic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1390493541/plib_nvic.o.d" -o ${OBJECTDIR}/_ext/1390493541/plib_nvic.o ../src/config/sam_c21n_xpro/peripheral/nvic/plib_nvic.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/770299191/plib_nvmctrl.o: ../src/config/sam_c21n_xpro/peripheral/nvmctrl/plib_nvmctrl.c  .generated_files/flags/sam_c21n_xpro/fdc3c711f1698a826adf93a93e7dd9cabc315b5f .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/770299191" 
	@${RM} ${OBJECTDIR}/_ext/770299191/plib_nvmctrl.o.d 
	@${RM} ${OBJECTDIR}/_ext/770299191/plib_nvmctrl.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/770299191/plib_nvmctrl.o.d" -o ${OBJECTDIR}/_ext/770299191/plib_nvmctrl.o ../src/config/sam_c21n_xpro/peripheral/nvmctrl/plib_nvmctrl.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1390440390/plib_port.o: ../src/config/sam_c21n_xpro/peripheral/port/plib_port.c  .generated_files/flags/sam_c21n_xpro/60134ead0e7c41b496e3cd183001f514f806838d .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1390440390" 
	@${RM} ${OBJECTDIR}/_ext/1390440390/plib_port.o.d 
	@${RM} ${OBJECTDIR}/_ext/1390440390/plib_port.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1390440390/plib_port.o.d" -o ${OBJECTDIR}/_ext/1390440390/plib_port.o ../src/config/sam_c21n_xpro/peripheral/port/plib_port.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1451668420/plib_sercom2_i2c_master.o: ../src/config/sam_c21n_xpro/peripheral/sercom/i2c_master/plib_sercom2_i2c_master.c  .generated_files/flags/sam_c21n_xpro/8e86a5a279b894c7cb2f4ab87b8cc3bdf72dd1aa .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1451668420" 
	@${RM} ${OBJECTDIR}/_ext/1451668420/plib_sercom2_i2c_master.o.d 
	@${RM} ${OBJECTDIR}/_ext/1451668420/plib_sercom2_i2c_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1451668420/plib_sercom2_i2c_master.o.d" -o ${OBJECTDIR}/_ext/1451668420/plib_sercom2_i2c_master.o ../src/config/sam_c21n_xpro/peripheral/sercom/i2c_master/plib_sercom2_i2c_master.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1993392304/plib_sercom1_usart.o: ../src/config/sam_c21n_xpro/peripheral/sercom/usart/plib_sercom1_usart.c  .generated_files/flags/sam_c21n_xpro/8bd8e7ac5feda165e54ffb7d0ac716105db3b7e7 .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1993392304" 
	@${RM} ${OBJECTDIR}/_ext/1993392304/plib_sercom1_usart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1993392304/plib_sercom1_usart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1993392304/plib_sercom1_usart.o.d" -o ${OBJECTDIR}/_ext/1993392304/plib_sercom1_usart.o ../src/config/sam_c21n_xpro/peripheral/sercom/usart/plib_sercom1_usart.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1993392304/plib_sercom0_usart.o: ../src/config/sam_c21n_xpro/peripheral/sercom/usart/plib_sercom0_usart.c  .generated_files/flags/sam_c21n_xpro/49893a6291cbdd6b5c9714cda83f5d0d460b615a .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1993392304" 
	@${RM} ${OBJECTDIR}/_ext/1993392304/plib_sercom0_usart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1993392304/plib_sercom0_usart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1993392304/plib_sercom0_usart.o.d" -o ${OBJECTDIR}/_ext/1993392304/plib_sercom0_usart.o ../src/config/sam_c21n_xpro/peripheral/sercom/usart/plib_sercom0_usart.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1004774289/plib_systick.o: ../src/config/sam_c21n_xpro/peripheral/systick/plib_systick.c  .generated_files/flags/sam_c21n_xpro/6979d2e82e7d1d59982f5d4e90961469a400428c .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1004774289" 
	@${RM} ${OBJECTDIR}/_ext/1004774289/plib_systick.o.d 
	@${RM} ${OBJECTDIR}/_ext/1004774289/plib_systick.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1004774289/plib_systick.o.d" -o ${OBJECTDIR}/_ext/1004774289/plib_systick.o ../src/config/sam_c21n_xpro/peripheral/systick/plib_systick.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1617721454/plib_wdt.o: ../src/config/sam_c21n_xpro/peripheral/wdt/plib_wdt.c  .generated_files/flags/sam_c21n_xpro/e36aa59bfcf0a561e1baf17c0cf92661eb5ad826 .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1617721454" 
	@${RM} ${OBJECTDIR}/_ext/1617721454/plib_wdt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1617721454/plib_wdt.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1617721454/plib_wdt.o.d" -o ${OBJECTDIR}/_ext/1617721454/plib_wdt.o ../src/config/sam_c21n_xpro/peripheral/wdt/plib_wdt.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/730014449/xc32_monitor.o: ../src/config/sam_c21n_xpro/stdio/xc32_monitor.c  .generated_files/flags/sam_c21n_xpro/b48e5b730d7de4b927fd3e6aec83bc4c2e3f07df .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/730014449" 
	@${RM} ${OBJECTDIR}/_ext/730014449/xc32_monitor.o.d 
	@${RM} ${OBJECTDIR}/_ext/730014449/xc32_monitor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/730014449/xc32_monitor.o.d" -o ${OBJECTDIR}/_ext/730014449/xc32_monitor.o ../src/config/sam_c21n_xpro/stdio/xc32_monitor.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/855761890/sys_int.o: ../src/config/sam_c21n_xpro/system/int/src/sys_int.c  .generated_files/flags/sam_c21n_xpro/29d69add7e51097585c7e8a6ebd308b2b4fb4136 .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/855761890" 
	@${RM} ${OBJECTDIR}/_ext/855761890/sys_int.o.d 
	@${RM} ${OBJECTDIR}/_ext/855761890/sys_int.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/855761890/sys_int.o.d" -o ${OBJECTDIR}/_ext/855761890/sys_int.o ../src/config/sam_c21n_xpro/system/int/src/sys_int.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1758384875/initialization.o: ../src/config/sam_c21n_xpro/initialization.c  .generated_files/flags/sam_c21n_xpro/14f7fd93cca8ffdaf40c9da234efff017116c0ee .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1758384875" 
	@${RM} ${OBJECTDIR}/_ext/1758384875/initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/1758384875/initialization.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1758384875/initialization.o.d" -o ${OBJECTDIR}/_ext/1758384875/initialization.o ../src/config/sam_c21n_xpro/initialization.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1758384875/interrupts.o: ../src/config/sam_c21n_xpro/interrupts.c  .generated_files/flags/sam_c21n_xpro/c345ce9b275277518026294beba91281585384ac .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1758384875" 
	@${RM} ${OBJECTDIR}/_ext/1758384875/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/1758384875/interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1758384875/interrupts.o.d" -o ${OBJECTDIR}/_ext/1758384875/interrupts.o ../src/config/sam_c21n_xpro/interrupts.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1758384875/exceptions.o: ../src/config/sam_c21n_xpro/exceptions.c  .generated_files/flags/sam_c21n_xpro/e91f4c4ea4d909b4bf5cd02f406e499c02cad6d .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1758384875" 
	@${RM} ${OBJECTDIR}/_ext/1758384875/exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1758384875/exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1758384875/exceptions.o.d" -o ${OBJECTDIR}/_ext/1758384875/exceptions.o ../src/config/sam_c21n_xpro/exceptions.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1758384875/startup_xc32.o: ../src/config/sam_c21n_xpro/startup_xc32.c  .generated_files/flags/sam_c21n_xpro/a4068cb983cde43e57f22fd5e37097665a4799c3 .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1758384875" 
	@${RM} ${OBJECTDIR}/_ext/1758384875/startup_xc32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1758384875/startup_xc32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1758384875/startup_xc32.o.d" -o ${OBJECTDIR}/_ext/1758384875/startup_xc32.o ../src/config/sam_c21n_xpro/startup_xc32.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1758384875/libc_syscalls.o: ../src/config/sam_c21n_xpro/libc_syscalls.c  .generated_files/flags/sam_c21n_xpro/aae0fb9ac19297e224c69d70d98711d036af460 .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1758384875" 
	@${RM} ${OBJECTDIR}/_ext/1758384875/libc_syscalls.o.d 
	@${RM} ${OBJECTDIR}/_ext/1758384875/libc_syscalls.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1758384875/libc_syscalls.o.d" -o ${OBJECTDIR}/_ext/1758384875/libc_syscalls.o ../src/config/sam_c21n_xpro/libc_syscalls.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1758384875/tasks.o: ../src/config/sam_c21n_xpro/tasks.c  .generated_files/flags/sam_c21n_xpro/cdf3b7e2788d7f2b944f816f375db21ebecd3c25 .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1758384875" 
	@${RM} ${OBJECTDIR}/_ext/1758384875/tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/1758384875/tasks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1758384875/tasks.o.d" -o ${OBJECTDIR}/_ext/1758384875/tasks.o ../src/config/sam_c21n_xpro/tasks.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/sam_c21n_xpro/7e5ec4f0ba5bef98b9f8f6568f1a2b6b4670edcc .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/app.o: ../src/app.c  .generated_files/flags/sam_c21n_xpro/44ab26131cdd2838c1aec3d849b1063c2f809cab .generated_files/flags/sam_c21n_xpro/656c69c14871583ce4e283f707599601d1a2cd0b
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/sam_c21n_xpro" -I"../src/packs/ATSAMC21E18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/app.o.d" -o ${OBJECTDIR}/_ext/1360937237/app.o ../src/app.c    -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wformat=2 -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code -Wmissing-noreturn -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/sam_c21n_xpro.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    ../src/config/sam_c21n_xpro/ATSAMC21E18A.ld
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g   -mprocessor=$(MP_PROCESSOR_OPTION) -mno-device-startup-code -o ${DISTDIR}/sam_c21n_xpro.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=_min_heap_size=1024,--gc-sections,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",-DROM_LENGTH=0x40000,--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}/samc21"
	
else
${DISTDIR}/sam_c21n_xpro.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   ../src/config/sam_c21n_xpro/ATSAMC21E18A.ld
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION) -mno-device-startup-code -o ${DISTDIR}/sam_c21n_xpro.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_sam_c21n_xpro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=1024,--gc-sections,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",-DROM_LENGTH=0x40000,--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}/samc21"
	${MP_CC_DIR}\\xc32-bin2hex ${DISTDIR}/sam_c21n_xpro.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
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
