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
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=x64
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/1b3a7b97/main.o \
	${OBJECTDIR}/getopt.o


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
LDLIBSOPTIONS=-L../Lib/${CND_CONF} -LlibEasyRTSPClient/Lib/${CND_CONF} -L../Lib/EasyAACEncloder/${CND_CONF}

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_CONF}/easyrtmp_rtsp

${CND_CONF}/easyrtmp_rtsp: ${OBJECTFILES}
	${MKDIR} -p ${CND_CONF}
	${LINK.cc} -o ${CND_CONF}/easyrtmp_rtsp ${OBJECTFILES} ${LDLIBSOPTIONS} -leasyrtmp -leasyrtspclient -leasyaacencoder -pthread -lrt

${OBJECTDIR}/_ext/1b3a7b97/main.o: /mnt/hgfs/E/04GitExtension/EasyRTMP/EasyRTMP_Demo/EasyRTMP_RTSP/main.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/1b3a7b97
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -IlibEasyRTSPClient/Include -I../Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1b3a7b97/main.o /mnt/hgfs/E/04GitExtension/EasyRTMP/EasyRTMP_Demo/EasyRTMP_RTSP/main.cpp

${OBJECTDIR}/getopt.o: getopt.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -IlibEasyRTSPClient/Include -I../Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/getopt.o getopt.c

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
