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
ifeq "$(wildcard nbproject/Makefile-local-XC8_18F87K22.mk)" "nbproject/Makefile-local-XC8_18F87K22.mk"
include nbproject/Makefile-local-XC8_18F87K22.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=XC8_18F87K22
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=cof
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/FPQ-1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/FPQ-1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/source/TaskManager.p1 ${OBJECTDIR}/source/ConfigurationBits.p1 ${OBJECTDIR}/source/Interrupts.p1 ${OBJECTDIR}/source/Main.p1 ${OBJECTDIR}/source/User.p1 ${OBJECTDIR}/source/DataCommsTask.p1 ${OBJECTDIR}/source/TimerTask.p1 ${OBJECTDIR}/source/SystemSetup.p1 ${OBJECTDIR}/source/InputTask.p1 ${OBJECTDIR}/source/OutputTask.p1 ${OBJECTDIR}/source/Model.p1 ${OBJECTDIR}/source/OutputSequences.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/source/TaskManager.p1.d ${OBJECTDIR}/source/ConfigurationBits.p1.d ${OBJECTDIR}/source/Interrupts.p1.d ${OBJECTDIR}/source/Main.p1.d ${OBJECTDIR}/source/User.p1.d ${OBJECTDIR}/source/DataCommsTask.p1.d ${OBJECTDIR}/source/TimerTask.p1.d ${OBJECTDIR}/source/SystemSetup.p1.d ${OBJECTDIR}/source/InputTask.p1.d ${OBJECTDIR}/source/OutputTask.p1.d ${OBJECTDIR}/source/Model.p1.d ${OBJECTDIR}/source/OutputSequences.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/source/TaskManager.p1 ${OBJECTDIR}/source/ConfigurationBits.p1 ${OBJECTDIR}/source/Interrupts.p1 ${OBJECTDIR}/source/Main.p1 ${OBJECTDIR}/source/User.p1 ${OBJECTDIR}/source/DataCommsTask.p1 ${OBJECTDIR}/source/TimerTask.p1 ${OBJECTDIR}/source/SystemSetup.p1 ${OBJECTDIR}/source/InputTask.p1 ${OBJECTDIR}/source/OutputTask.p1 ${OBJECTDIR}/source/Model.p1 ${OBJECTDIR}/source/OutputSequences.p1


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
	${MAKE}  -f nbproject/Makefile-XC8_18F87K22.mk dist/${CND_CONF}/${IMAGE_TYPE}/FPQ-1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F2585
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/source/TaskManager.p1: source/TaskManager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/source 
	@${RM} ${OBJECTDIR}/source/TaskManager.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  -D__DEBUG=1 --debugger=pickit2  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"/Users/David/Projects/FPQ-OnGitHub/Platform Research/MCU_c/FPQ-1.X/source/headers" -I"/Applications/microchip/xc8/v1.12/include/plib" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib "--errformat=%f:%l: error: %s" "--warnformat=%f:%l: warning: %s" "--msgformat=%f:%l: advisory: %s"  -o${OBJECTDIR}/source/TaskManager.p1  source/TaskManager.c 
	@-${MV} ${OBJECTDIR}/source/TaskManager.d ${OBJECTDIR}/source/TaskManager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/source/TaskManager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/source/ConfigurationBits.p1: source/ConfigurationBits.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/source 
	@${RM} ${OBJECTDIR}/source/ConfigurationBits.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  -D__DEBUG=1 --debugger=pickit2  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"/Users/David/Projects/FPQ-OnGitHub/Platform Research/MCU_c/FPQ-1.X/source/headers" -I"/Applications/microchip/xc8/v1.12/include/plib" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib "--errformat=%f:%l: error: %s" "--warnformat=%f:%l: warning: %s" "--msgformat=%f:%l: advisory: %s"  -o${OBJECTDIR}/source/ConfigurationBits.p1  source/ConfigurationBits.c 
	@-${MV} ${OBJECTDIR}/source/ConfigurationBits.d ${OBJECTDIR}/source/ConfigurationBits.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/source/ConfigurationBits.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/source/Interrupts.p1: source/Interrupts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/source 
	@${RM} ${OBJECTDIR}/source/Interrupts.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  -D__DEBUG=1 --debugger=pickit2  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"/Users/David/Projects/FPQ-OnGitHub/Platform Research/MCU_c/FPQ-1.X/source/headers" -I"/Applications/microchip/xc8/v1.12/include/plib" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib "--errformat=%f:%l: error: %s" "--warnformat=%f:%l: warning: %s" "--msgformat=%f:%l: advisory: %s"  -o${OBJECTDIR}/source/Interrupts.p1  source/Interrupts.c 
	@-${MV} ${OBJECTDIR}/source/Interrupts.d ${OBJECTDIR}/source/Interrupts.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/source/Interrupts.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/source/Main.p1: source/Main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/source 
	@${RM} ${OBJECTDIR}/source/Main.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  -D__DEBUG=1 --debugger=pickit2  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"/Users/David/Projects/FPQ-OnGitHub/Platform Research/MCU_c/FPQ-1.X/source/headers" -I"/Applications/microchip/xc8/v1.12/include/plib" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib "--errformat=%f:%l: error: %s" "--warnformat=%f:%l: warning: %s" "--msgformat=%f:%l: advisory: %s"  -o${OBJECTDIR}/source/Main.p1  source/Main.c 
	@-${MV} ${OBJECTDIR}/source/Main.d ${OBJECTDIR}/source/Main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/source/Main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/source/User.p1: source/User.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/source 
	@${RM} ${OBJECTDIR}/source/User.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  -D__DEBUG=1 --debugger=pickit2  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"/Users/David/Projects/FPQ-OnGitHub/Platform Research/MCU_c/FPQ-1.X/source/headers" -I"/Applications/microchip/xc8/v1.12/include/plib" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib "--errformat=%f:%l: error: %s" "--warnformat=%f:%l: warning: %s" "--msgformat=%f:%l: advisory: %s"  -o${OBJECTDIR}/source/User.p1  source/User.c 
	@-${MV} ${OBJECTDIR}/source/User.d ${OBJECTDIR}/source/User.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/source/User.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/source/DataCommsTask.p1: source/DataCommsTask.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/source 
	@${RM} ${OBJECTDIR}/source/DataCommsTask.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  -D__DEBUG=1 --debugger=pickit2  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"/Users/David/Projects/FPQ-OnGitHub/Platform Research/MCU_c/FPQ-1.X/source/headers" -I"/Applications/microchip/xc8/v1.12/include/plib" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib "--errformat=%f:%l: error: %s" "--warnformat=%f:%l: warning: %s" "--msgformat=%f:%l: advisory: %s"  -o${OBJECTDIR}/source/DataCommsTask.p1  source/DataCommsTask.c 
	@-${MV} ${OBJECTDIR}/source/DataCommsTask.d ${OBJECTDIR}/source/DataCommsTask.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/source/DataCommsTask.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/source/TimerTask.p1: source/TimerTask.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/source 
	@${RM} ${OBJECTDIR}/source/TimerTask.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  -D__DEBUG=1 --debugger=pickit2  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"/Users/David/Projects/FPQ-OnGitHub/Platform Research/MCU_c/FPQ-1.X/source/headers" -I"/Applications/microchip/xc8/v1.12/include/plib" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib "--errformat=%f:%l: error: %s" "--warnformat=%f:%l: warning: %s" "--msgformat=%f:%l: advisory: %s"  -o${OBJECTDIR}/source/TimerTask.p1  source/TimerTask.c 
	@-${MV} ${OBJECTDIR}/source/TimerTask.d ${OBJECTDIR}/source/TimerTask.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/source/TimerTask.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/source/SystemSetup.p1: source/SystemSetup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/source 
	@${RM} ${OBJECTDIR}/source/SystemSetup.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  -D__DEBUG=1 --debugger=pickit2  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"/Users/David/Projects/FPQ-OnGitHub/Platform Research/MCU_c/FPQ-1.X/source/headers" -I"/Applications/microchip/xc8/v1.12/include/plib" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib "--errformat=%f:%l: error: %s" "--warnformat=%f:%l: warning: %s" "--msgformat=%f:%l: advisory: %s"  -o${OBJECTDIR}/source/SystemSetup.p1  source/SystemSetup.c 
	@-${MV} ${OBJECTDIR}/source/SystemSetup.d ${OBJECTDIR}/source/SystemSetup.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/source/SystemSetup.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/source/InputTask.p1: source/InputTask.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/source 
	@${RM} ${OBJECTDIR}/source/InputTask.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  -D__DEBUG=1 --debugger=pickit2  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"/Users/David/Projects/FPQ-OnGitHub/Platform Research/MCU_c/FPQ-1.X/source/headers" -I"/Applications/microchip/xc8/v1.12/include/plib" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib "--errformat=%f:%l: error: %s" "--warnformat=%f:%l: warning: %s" "--msgformat=%f:%l: advisory: %s"  -o${OBJECTDIR}/source/InputTask.p1  source/InputTask.c 
	@-${MV} ${OBJECTDIR}/source/InputTask.d ${OBJECTDIR}/source/InputTask.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/source/InputTask.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/source/OutputTask.p1: source/OutputTask.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/source 
	@${RM} ${OBJECTDIR}/source/OutputTask.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  -D__DEBUG=1 --debugger=pickit2  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"/Users/David/Projects/FPQ-OnGitHub/Platform Research/MCU_c/FPQ-1.X/source/headers" -I"/Applications/microchip/xc8/v1.12/include/plib" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib "--errformat=%f:%l: error: %s" "--warnformat=%f:%l: warning: %s" "--msgformat=%f:%l: advisory: %s"  -o${OBJECTDIR}/source/OutputTask.p1  source/OutputTask.c 
	@-${MV} ${OBJECTDIR}/source/OutputTask.d ${OBJECTDIR}/source/OutputTask.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/source/OutputTask.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/source/Model.p1: source/Model.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/source 
	@${RM} ${OBJECTDIR}/source/Model.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  -D__DEBUG=1 --debugger=pickit2  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"/Users/David/Projects/FPQ-OnGitHub/Platform Research/MCU_c/FPQ-1.X/source/headers" -I"/Applications/microchip/xc8/v1.12/include/plib" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib "--errformat=%f:%l: error: %s" "--warnformat=%f:%l: warning: %s" "--msgformat=%f:%l: advisory: %s"  -o${OBJECTDIR}/source/Model.p1  source/Model.c 
	@-${MV} ${OBJECTDIR}/source/Model.d ${OBJECTDIR}/source/Model.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/source/Model.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/source/OutputSequences.p1: source/OutputSequences.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/source 
	@${RM} ${OBJECTDIR}/source/OutputSequences.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  -D__DEBUG=1 --debugger=pickit2  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"/Users/David/Projects/FPQ-OnGitHub/Platform Research/MCU_c/FPQ-1.X/source/headers" -I"/Applications/microchip/xc8/v1.12/include/plib" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib "--errformat=%f:%l: error: %s" "--warnformat=%f:%l: warning: %s" "--msgformat=%f:%l: advisory: %s"  -o${OBJECTDIR}/source/OutputSequences.p1  source/OutputSequences.c 
	@-${MV} ${OBJECTDIR}/source/OutputSequences.d ${OBJECTDIR}/source/OutputSequences.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/source/OutputSequences.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/source/TaskManager.p1: source/TaskManager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/source 
	@${RM} ${OBJECTDIR}/source/TaskManager.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"/Users/David/Projects/FPQ-OnGitHub/Platform Research/MCU_c/FPQ-1.X/source/headers" -I"/Applications/microchip/xc8/v1.12/include/plib" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib "--errformat=%f:%l: error: %s" "--warnformat=%f:%l: warning: %s" "--msgformat=%f:%l: advisory: %s"  -o${OBJECTDIR}/source/TaskManager.p1  source/TaskManager.c 
	@-${MV} ${OBJECTDIR}/source/TaskManager.d ${OBJECTDIR}/source/TaskManager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/source/TaskManager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/source/ConfigurationBits.p1: source/ConfigurationBits.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/source 
	@${RM} ${OBJECTDIR}/source/ConfigurationBits.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"/Users/David/Projects/FPQ-OnGitHub/Platform Research/MCU_c/FPQ-1.X/source/headers" -I"/Applications/microchip/xc8/v1.12/include/plib" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib "--errformat=%f:%l: error: %s" "--warnformat=%f:%l: warning: %s" "--msgformat=%f:%l: advisory: %s"  -o${OBJECTDIR}/source/ConfigurationBits.p1  source/ConfigurationBits.c 
	@-${MV} ${OBJECTDIR}/source/ConfigurationBits.d ${OBJECTDIR}/source/ConfigurationBits.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/source/ConfigurationBits.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/source/Interrupts.p1: source/Interrupts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/source 
	@${RM} ${OBJECTDIR}/source/Interrupts.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"/Users/David/Projects/FPQ-OnGitHub/Platform Research/MCU_c/FPQ-1.X/source/headers" -I"/Applications/microchip/xc8/v1.12/include/plib" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib "--errformat=%f:%l: error: %s" "--warnformat=%f:%l: warning: %s" "--msgformat=%f:%l: advisory: %s"  -o${OBJECTDIR}/source/Interrupts.p1  source/Interrupts.c 
	@-${MV} ${OBJECTDIR}/source/Interrupts.d ${OBJECTDIR}/source/Interrupts.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/source/Interrupts.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/source/Main.p1: source/Main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/source 
	@${RM} ${OBJECTDIR}/source/Main.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"/Users/David/Projects/FPQ-OnGitHub/Platform Research/MCU_c/FPQ-1.X/source/headers" -I"/Applications/microchip/xc8/v1.12/include/plib" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib "--errformat=%f:%l: error: %s" "--warnformat=%f:%l: warning: %s" "--msgformat=%f:%l: advisory: %s"  -o${OBJECTDIR}/source/Main.p1  source/Main.c 
	@-${MV} ${OBJECTDIR}/source/Main.d ${OBJECTDIR}/source/Main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/source/Main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/source/User.p1: source/User.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/source 
	@${RM} ${OBJECTDIR}/source/User.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"/Users/David/Projects/FPQ-OnGitHub/Platform Research/MCU_c/FPQ-1.X/source/headers" -I"/Applications/microchip/xc8/v1.12/include/plib" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib "--errformat=%f:%l: error: %s" "--warnformat=%f:%l: warning: %s" "--msgformat=%f:%l: advisory: %s"  -o${OBJECTDIR}/source/User.p1  source/User.c 
	@-${MV} ${OBJECTDIR}/source/User.d ${OBJECTDIR}/source/User.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/source/User.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/source/DataCommsTask.p1: source/DataCommsTask.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/source 
	@${RM} ${OBJECTDIR}/source/DataCommsTask.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"/Users/David/Projects/FPQ-OnGitHub/Platform Research/MCU_c/FPQ-1.X/source/headers" -I"/Applications/microchip/xc8/v1.12/include/plib" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib "--errformat=%f:%l: error: %s" "--warnformat=%f:%l: warning: %s" "--msgformat=%f:%l: advisory: %s"  -o${OBJECTDIR}/source/DataCommsTask.p1  source/DataCommsTask.c 
	@-${MV} ${OBJECTDIR}/source/DataCommsTask.d ${OBJECTDIR}/source/DataCommsTask.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/source/DataCommsTask.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/source/TimerTask.p1: source/TimerTask.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/source 
	@${RM} ${OBJECTDIR}/source/TimerTask.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"/Users/David/Projects/FPQ-OnGitHub/Platform Research/MCU_c/FPQ-1.X/source/headers" -I"/Applications/microchip/xc8/v1.12/include/plib" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib "--errformat=%f:%l: error: %s" "--warnformat=%f:%l: warning: %s" "--msgformat=%f:%l: advisory: %s"  -o${OBJECTDIR}/source/TimerTask.p1  source/TimerTask.c 
	@-${MV} ${OBJECTDIR}/source/TimerTask.d ${OBJECTDIR}/source/TimerTask.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/source/TimerTask.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/source/SystemSetup.p1: source/SystemSetup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/source 
	@${RM} ${OBJECTDIR}/source/SystemSetup.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"/Users/David/Projects/FPQ-OnGitHub/Platform Research/MCU_c/FPQ-1.X/source/headers" -I"/Applications/microchip/xc8/v1.12/include/plib" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib "--errformat=%f:%l: error: %s" "--warnformat=%f:%l: warning: %s" "--msgformat=%f:%l: advisory: %s"  -o${OBJECTDIR}/source/SystemSetup.p1  source/SystemSetup.c 
	@-${MV} ${OBJECTDIR}/source/SystemSetup.d ${OBJECTDIR}/source/SystemSetup.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/source/SystemSetup.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/source/InputTask.p1: source/InputTask.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/source 
	@${RM} ${OBJECTDIR}/source/InputTask.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"/Users/David/Projects/FPQ-OnGitHub/Platform Research/MCU_c/FPQ-1.X/source/headers" -I"/Applications/microchip/xc8/v1.12/include/plib" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib "--errformat=%f:%l: error: %s" "--warnformat=%f:%l: warning: %s" "--msgformat=%f:%l: advisory: %s"  -o${OBJECTDIR}/source/InputTask.p1  source/InputTask.c 
	@-${MV} ${OBJECTDIR}/source/InputTask.d ${OBJECTDIR}/source/InputTask.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/source/InputTask.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/source/OutputTask.p1: source/OutputTask.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/source 
	@${RM} ${OBJECTDIR}/source/OutputTask.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"/Users/David/Projects/FPQ-OnGitHub/Platform Research/MCU_c/FPQ-1.X/source/headers" -I"/Applications/microchip/xc8/v1.12/include/plib" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib "--errformat=%f:%l: error: %s" "--warnformat=%f:%l: warning: %s" "--msgformat=%f:%l: advisory: %s"  -o${OBJECTDIR}/source/OutputTask.p1  source/OutputTask.c 
	@-${MV} ${OBJECTDIR}/source/OutputTask.d ${OBJECTDIR}/source/OutputTask.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/source/OutputTask.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/source/Model.p1: source/Model.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/source 
	@${RM} ${OBJECTDIR}/source/Model.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"/Users/David/Projects/FPQ-OnGitHub/Platform Research/MCU_c/FPQ-1.X/source/headers" -I"/Applications/microchip/xc8/v1.12/include/plib" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib "--errformat=%f:%l: error: %s" "--warnformat=%f:%l: warning: %s" "--msgformat=%f:%l: advisory: %s"  -o${OBJECTDIR}/source/Model.p1  source/Model.c 
	@-${MV} ${OBJECTDIR}/source/Model.d ${OBJECTDIR}/source/Model.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/source/Model.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/source/OutputSequences.p1: source/OutputSequences.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/source 
	@${RM} ${OBJECTDIR}/source/OutputSequences.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"/Users/David/Projects/FPQ-OnGitHub/Platform Research/MCU_c/FPQ-1.X/source/headers" -I"/Applications/microchip/xc8/v1.12/include/plib" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib "--errformat=%f:%l: error: %s" "--warnformat=%f:%l: warning: %s" "--msgformat=%f:%l: advisory: %s"  -o${OBJECTDIR}/source/OutputSequences.p1  source/OutputSequences.c 
	@-${MV} ${OBJECTDIR}/source/OutputSequences.d ${OBJECTDIR}/source/OutputSequences.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/source/OutputSequences.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/FPQ-1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) --chip=$(MP_PROCESSOR_OPTION) -G --asmlist -mdist/${CND_CONF}/${IMAGE_TYPE}/FPQ-1.X.${IMAGE_TYPE}.map  -D__DEBUG=1 --debugger=pickit2  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"/Users/David/Projects/FPQ-OnGitHub/Platform Research/MCU_c/FPQ-1.X/source/headers" -I"/Applications/microchip/xc8/v1.12/include/plib" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib "--errformat=%f:%l: error: %s" "--warnformat=%f:%l: warning: %s" "--msgformat=%f:%l: advisory: %s"   -odist/${CND_CONF}/${IMAGE_TYPE}/FPQ-1.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/FPQ-1.X.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/FPQ-1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) --chip=$(MP_PROCESSOR_OPTION) -G --asmlist -mdist/${CND_CONF}/${IMAGE_TYPE}/FPQ-1.X.${IMAGE_TYPE}.map  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"/Users/David/Projects/FPQ-OnGitHub/Platform Research/MCU_c/FPQ-1.X/source/headers" -I"/Applications/microchip/xc8/v1.12/include/plib" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib "--errformat=%f:%l: error: %s" "--warnformat=%f:%l: warning: %s" "--msgformat=%f:%l: advisory: %s"   -odist/${CND_CONF}/${IMAGE_TYPE}/FPQ-1.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/XC8_18F87K22
	${RM} -r dist/XC8_18F87K22

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
