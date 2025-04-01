
#/Modularizing/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(Modularizing VERSION 0.0.0)

# Ensure the Libraries directory exists before installation
set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/Libraries)

# Define valid build types
set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS Release Debug UnitTesting)

# Display the current build type
message(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
#message(STATUS "CMAKE_PROJECT_NAME: ${CMAKE_PROJECT_NAME}")
#message(STATUS "MAJOR_VERSION: ${PROJECT_VERSION_MAJOR}")
#message(STATUS "MINOR_VERSION: ${PROJECT_VERSION_MINOR}")
#message(STATUS "PATCH_VERSION: ${PROJECT_VERSION_PATCH}")

# Display the toolchain details in the output
message(STATUS "C Compiler: ${CMAKE_C_COMPILER}")
message(STATUS "C++ Compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "ASM Compiler: ${CMAKE_ASM_COMPILER}")
message(STATUS "Linker: ${CMAKE_LINKER}")
message(STATUS "C Flags: ${CMAKE_C_FLAGS}")
message(STATUS "CXX Flags: ${CMAKE_CXX_FLAGS}")



add_subdirectory("Application")
add_subdirectory("Module")
add_subdirectory("Shell")







install(TARGETS Module)





