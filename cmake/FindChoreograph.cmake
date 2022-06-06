message("FINDChoreograph CMAKE")
message("CMAKE_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX}")
message("CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE}")
set(LIBNAME Choreographd)

find_path(CHOREOGRAPH_INCLUDE_DIR
        NAMES
		choreograph/Choreograph.h
		HINTS
        ${CMAKE_INSTALL_PREFIX}/include/
)

message(STATUS "CHOREOGRAPH_INCLUDE_DIR  ${CHOREOGRAPH_INCLUDE_DIR}")


find_library(CHOREOGRAPH_LIBRARY
       NAMES
	   ${LIBNAME}
	   HINTS
        ${CMAKE_INSTALL_PREFIX}/lib/
)  

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Choreograph
	DEFAULT_MSG
	CHOREOGRAPH_INCLUDE_DIR
	CHOREOGRAPH_LIBRARY
)


