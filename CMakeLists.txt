cmake_minimum_required(VERSION 3.15)
include(ExternalProject)
include(GNUInstallDirs)
include(macros.cmake)

project(MyDemo)

set(CMAKE_CXX_STANDARD 17)
    if(COMMAND cmake_policy)
      cmake_policy(SET CMP0003 NEW)
    endif(COMMAND cmake_policy)
add_definitions(-D_HAS_STD_BYTE=0)

SET(CMAKE_CXX_FLAGS "-std=c++11 -O3")

set (CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" CACHE STRING "default install path" FORCE )
list(APPEND CMAKE_MODULE_PATH  ${CMAKE_SOURCE_DIR}/cmake ${CMAKE_INSTALL_PREFIX})

set(CMAKE_BUILD_TYPE "Debug")

set(EXTERNAL_DIR_LOCATION ${CMAKE_BINARY_DIR})  
set(EXTERNAL_DIR_INSTALL_LOCATION ${CMAKE_BINARY_DIR})  


#Choreograph
# Configure external project
execute_process(
     COMMAND ${CMAKE_COMMAND}      
     -DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX} 
     -DINSTALL_DIR_ABSOLUTE=${INSTALL_DIR_ABSOLUTE} 
     -DDEFAULT_BUILD_COMMAND=${DEFAULT_BUILD_COMMAND} 
     -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
     ${CMAKE_SOURCE_DIR}/Choreograph
     WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/Choreograph
 )


#Build external project
execute_process( COMMAND ${CMAKE_COMMAND} 
  --build ${CMAKE_SOURCE_DIR}/Choreograph
  --config ${CMAKE_BUILD_TYPE} 
)


find_package(Choreograph REQUIRED)
if(Choreograph_FOUND)
  message(STATUS "Choreograph found")
  message(STATUS "CHOREOGRAPH_INCLUDE_DIR ${CHOREOGRAPH_INCLUDE_DIR}")
  message(STATUS "CHOREOGRAPH_LIBRARY ${CHOREOGRAPH_LIBRARY}")
else()
  message(STATUS "Choreograph NOT found" )
endif()


include_directories(
    ${CHOREOGRAPH_INCLUDE_DIR}
)

set(EXTERNAL_LIBRARIES
    ${CHOREOGRAPH_LIBRARY}
)

add_library(
    my-lerp-lib    
    Interpolation.cpp
    Interpolation.h
)


add_executable(my-demo Main.cpp)

target_link_libraries(my-demo PUBLIC my-lerp-lib ${EXTERNAL_LIBRARIES} )