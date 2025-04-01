#/Dynamic/Application/CMakeLists.txt



# Path to the external library files
#set(EXTERNAL_LIB_PATH "${CMAKE_SOURCE_DIR}/Libraries")

# Specify the include directory for the external library
#include_directories("${EXTERNAL_LIB_PATH}/inc")



#message(STATUS "EXTERNAL_LIB_PATH: ${EXTERNAL_LIB_PATH}")


# Set source files for the application
set(SOURCES
	Application.c
)

# Create the executable for the application
ADD_EXECUTABLE(Shared ${SOURCES})

# Link with the Module library if required
#TARGET_LINK_LIBRARIES(Shared PRIVATE DynamicLib "${EXTERNAL_LIB_PATH}/Lib/STM32F401RE-Board.lib")
TARGET_LINK_LIBRARIES(Shared PRIVATE CLIExt DynamicLib)

# Include directories
TARGET_INCLUDE_DIRECTORIES(Shared PRIVATE ${CMAKE_CURRENT_LIST_DIR})


