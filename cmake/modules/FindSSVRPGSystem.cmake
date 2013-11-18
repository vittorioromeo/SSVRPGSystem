FIND_PATH(SSVRPGSYSTEM_INCLUDE_DIR
  NAMES SSVRPGSystem/SSVRPGSystem.hpp
  PATH_SUFFIXES include/
  PATHS "${PROJECT_SOURCE_DIR}/../SSVRPGSystem/"
  "${PROJECT_SOURCE_DIR}/extlibs/SSVRPGSystem/"
  ${SSVRPGSYSTEM_ROOT}
  $ENV{SSVRPGSYSTEM_ROOT}
  /usr/local/
  /usr/
  /sw/       
  /opt/local/
  /opt/csw/  
  /opt/
)

message("\nFound SSVRPGSystem include at: ${SSVRPGSYSTEM_INCLUDE_DIR}.\n")

FIND_LIBRARY(SSVRPGSYSTEM_LIBRARY
  NAMES SSVRPGSystem SSVRPGSystem-s
  PATH_SUFFIXES lib/ lib64/
  PATHS "${PROJECT_SOURCE_DIR}/../SSVRPGSystem/"
  "${PROJECT_SOURCE_DIR}/extlibs/SSVRPGSystem/"
  ${SSVRPGSYSTEM_ROOT}
  $ENV{SSVRPGSYSTEM_ROOT}
  /usr/local/
  /usr/
  /sw/       
  /opt/local/
  /opt/csw/  
  /opt/
)

message("\nFound SSVRPGSystem library at: ${SSVRPGSYSTEM_LIBRARY}.\n")

IF(SSVRPGSYSTEM_LIBRARY AND SSVRPGSYSTEM_INCLUDE_DIR)
  SET(SSVRPGSYSTEM_LIBRARIES ${SSVRPGSYSTEM_LIBRARY})
  SET(SSVRPGSYSTEM_FOUND TRUE)
ELSE(SSVRPGSYSTEM_LIBRARY AND SSVRPGSYSTEM_INCLUDE_DIR)
  SET(SSVRPGSYSTEM_FOUND FALSE)
ENDIF(SSVRPGSYSTEM_LIBRARY AND SSVRPGSYSTEM_INCLUDE_DIR)

IF(SSVRPGSYSTEM_FOUND)
  MESSAGE(STATUS "Found SSVRPGSystem in ${SSVRPGSYSTEM_INCLUDE_DIR}")
ELSE(SSVRPGSYSTEM_FOUND)
  IF(SSVRPGSYSTEM_FIND_REQUIRED)
    MESSAGE(FATAL_ERROR "Could not find SSVRPGSystem library")
  ENDIF(SSVRPGSYSTEM_FIND_REQUIRED)
ENDIF(SSVRPGSYSTEM_FOUND)

MARK_AS_ADVANCED(
  SSVRPGSYSTEM_LIBRARY
  SSVRPGSYSTEM_INCLUDE_DIR
)
