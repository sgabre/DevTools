mkdir build && cmake -B ./build -S . -DCMAKE_BUILD_TYPE=Debug && cmake --build ./build --config Debug 



BUILD_DIR=../Build
SOURCE_DIR=.
CONFIG=Debug
TEST_LEVEL=None
TOOLCHAIN=../.cmake/toolchains/gcc-arm-none-eabi.cmake
INSTALL_DIR="/Users/sgabre/git/TestHarness/Libraries/"
BUILD_SHARED=OFF

# Windows 

## Windows - Executable & Static Library - Debug

CONFIG=Debug
TOOLCHAIN=../.cmake/toolchains/toolchain-windows.cmake
BUILD_SHARED=OFF

## Windows - Executable & Static Library - Release

CONFIG=Release
TOOLCHAIN=../.cmake/toolchains/toolchain-windows.cmake
BUILD_SHARED=OFF

## Windows - Executable & Shared Library - Debug

CONFIG=Debug
TOOLCHAIN=../.cmake/toolchains/toolchain-windows.cmake
BUILD_SHARED=ON

## Windows - Executable & Shared Library - Release

CONFIG=Release
TOOLCHAIN=../.cmake/toolchains/toolchain-windows.cmake
BUILD_SHARED=ON

## Windows - Executable & Shared Library & Static Library  - Debug

CONFIG=Debug
TOOLCHAIN=../.cmake/toolchains/toolchain-windows.cmake
BUILD_SHARED=BOTH

## Windows - Executable & Shared Library & Static Library  - Release

CONFIG=Release
TOOLCHAIN=../.cmake/toolchains/toolchain-windows.cmake
BUILD_SHARED=BOTH


## Windows - Executable & Static Library - Debug

CONFIG=Debug
TOOLCHAIN=../.cmake/toolchains/toolchain-windows.cmake
BUILD_SHARED=OFF


# Mac OS X

## Mac OS X  - Executable & Static Library - Release

CONFIG=Release
TOOLCHAIN=../.cmake/toolchains/toolchain-macos.cmake
BUILD_SHARED=OFF

## Mac OS X  - Executable & Shared Library - Debug

CONFIG=Debug
TOOLCHAIN=../.cmake/toolchains/toolchain-macos.cmake
BUILD_SHARED=ON

## Mac OS X  - Executable & Shared Library - Release

CONFIG=Release
TOOLCHAIN=../.cmake/toolchains/toolchain-macos.cmake
BUILD_SHARED=ON

## Mac OS X  - Executable & Shared Library & Static Library  - Debug

CONFIG=Debug
TOOLCHAIN=../.cmake/toolchains/toolchain-macos.cmake
BUILD_SHARED=BOTH

## Mac OS X  - Executable & Shared Library & Static Library  - Release

CONFIG=Release
TOOLCHAIN=../.cmake/toolchains/toolchain-macos.cmake
BUILD_SHARED=BOTH


# Linux 


# Raspberry 


# Microcontroller 


## Microcontroller  - Executable & Static Library - Debug

CONFIG=Debug
TOOLCHAIN=../.cmake/toolchains/toolchain-macos.cmake
BUILD_SHARED=OFF

## Microcontroller  - Executable & Static Library - Release

CONFIG=Release
TOOLCHAIN=../.cmake/toolchains/toolchain-macos.cmake
BUILD_SHARED=OFF



echo "Configuration"
cmake -B ${BUILD_DIR} -S ${SOURCE_DIR} -DTEST_LEVEL=${TEST_LEVEL}

echo "--Building--"
cmake --build ${BUILD_DIR}  --config ${CONFIG}  

echo "--Testing--"
ctest -C ${CONFIG} -VV --test-dir  ${BUILD_DIR}

echo "--Deployement--"
cmake --install ${BUILD_DIR} --prefix ${INSTALL_DIR}

echo "--Packing--"


| ?? 					| Windows			| Mac OS X 			| Linux				| Microcontroler	|
|-----------------------|-------------------|-------------------|-------------------|-------------------|
| Executable/Binary		| Debug, Release	|  Debug, Release	|  Debug, Release	|  Debug, Release	|
| Shared Library		| Debug, Release	|  Debug, Release	|  Debug, Release	|  Debug, Release	|
| Static Library		| Debug, Release	|  Debug, Release	|  Debug, Release	|  Debug, Release	|


git submodule add https://github.com/theNewDynamic/gohugo-theme-ananke themes/ananke
git submodule add https://github.com/lxndrblz/anatole.git themes/anatole

@startuml

package "DevTools" {
[Command-In-Line]  <<Executable>> as EXE
[CLI Extension]  <<Static Library>> as CLI
[Python]  <<Scripts>> as PLIB
[DLL]  <<Shared Library>> as DLIB
[Sofware Component]  <<Static Library>> as SLIB
[Bridge(s)]  <<Shared Library>> as XLIB
}

EXE --> DLIB
EXE --> CLI
PLIB --> DLIB
DLIB --> SLIB
SLIB --> XLIB


@enduml

@startuml

package "DevTools" {
[Command-In-Line] <<Executable>> 
[Python]
[Shared Abstraction Layer]<<Static Library>> 
[Shared Library] <<Shared Library>> 
[Static Library] <<Static Library>> 
[CMock Library] <<Static Library>> 
[Driver Abstraction Layer] <<Shared Library>> 
[I2C Driver] <<Shared Library>> 
[SPI Driver] <<Shared Library>> 
[UART Driver] <<Shared Library>> 
[GPIO Driver] <<Shared Library>> 
}

[Command-In-Line]--> [Shared Abstraction Layer]
[Python]--> [Shared Abstraction Layer]
[Shared Abstraction Layer] --> [Shared Library]

[Shared Library] --> [Static Library]

[Static Library] --> [CMock Library]
[Static Library] --> [Driver Abstraction Layer]

[Driver Abstraction Layer] --> [GPIO Driver]
[Driver Abstraction Layer] --> [UART Driver]
[Driver Abstraction Layer] --> [I2C Driver]
[Driver Abstraction Layer] --> [SPI Driver]


@enduml


@startuml





package "DevTools" {
[Command-In-Line] <<Executable>> 
[Python]
[Shared Abstraction Layer]<<Static Library>> 
[Shared Library] <<Shared Library>> 
[Static Library] <<Static Library>> 
[CMock Library] <<Static Library>> 
[Driver Abstraction Layer] <<Shared Library>> 
[I2C Driver] <<Shared Library>> 
[SPI Driver] <<Shared Library>> 
[UART Driver] <<Shared Library>> 
[GPIO Driver] <<Shared Library>> 
}

package "Windows" {
[I2C]  <<Shared Library>> as WI2C
}

package "Apple" {
[I2C]  <<Dynamic Link Library>> as MI2C
}

package "Linux" {
[I2C]  <<Shared Library>> as LI2C
[SPI]  <<Shared Library>> as LSPI
[UART]  <<Shared Library>> as LUART
}

[Command-In-Line]--> [Shared Abstraction Layer]
[Python]--> [Shared Abstraction Layer]
[Shared Abstraction Layer] --> [Shared Library]

[Shared Library] --> [Static Library]

[Static Library] --> [CMock Library]
[Static Library] --> [Driver Abstraction Layer]

[Driver Abstraction Layer] --> [GPIO Driver]
[Driver Abstraction Layer] --> [UART Driver]
[Driver Abstraction Layer] --> [I2C Driver]
[Driver Abstraction Layer] --> [SPI Driver]


@enduml




@startuml

package "DevTools" {
[Command-In-Line]  <<Executable>> as EXE
[CLI Extension]  <<Static Library>> as CLI
[Wrapper]  <<Python>> as PLIB
[DLL]  <<Shared Library>> as DLIB
[Firmware Component]  <<Static Library>> as SLIB
[Bridge(s)]  <<Shared Library>> as XLIB
}

EXE --> DLIB
EXE --> CLI
PLIB --> DLIB
DLIB --> SLIB
SLIB --> XLIB








@enduml