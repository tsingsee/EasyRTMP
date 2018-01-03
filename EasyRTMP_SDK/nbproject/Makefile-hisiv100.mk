#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=arm-hisiv100-linux-uclibcgnueabi-gcc
CCC=arm-hisiv100-linux-uclibcgnueabi-g++
CXX=arm-hisiv100-linux-uclibcgnueabi-g++
FC=gfortran
AS=arm-hisiv100-linux-uclibcgnueabi-as

# Macros
CND_PLATFORM=hisiv100-Linux
CND_DLIB_EXT=so
CND_CONF=hisiv100
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/getopt.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/trace.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L../Lib/EasyAACEncloder/${CND_CONF} -LSDK/Lib/hisiv100 -L../Lib/hisiv100_static

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_CONF}/easyrtmp_sdk

${CND_CONF}/easyrtmp_sdk: ${OBJECTFILES}
	${MKDIR} -p ${CND_CONF}
	${LINK.cc} -o ${CND_CONF}/easyrtmp_sdk ${OBJECTFILES} ${LDLIBSOPTIONS} -lNetLib -leasyrtmp -leasyaacencoder -pthread

${OBJECTDIR}/getopt.o: getopt.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -DHI_OS_LINUX -D_ARM -D_FILE_OFFSET_BITS=64 -I../Include -ISDK/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/getopt.o getopt.c

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DHI_OS_LINUX -D_ARM -D_FILE_OFFSET_BITS=64 -I../Include -ISDK/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/trace.o: trace.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -DHI_OS_LINUX -D_ARM -D_FILE_OFFSET_BITS=64 -I../Include -ISDK/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/trace.o trace.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
