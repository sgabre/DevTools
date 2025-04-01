mkdir build && cmake -B ./build -S . -DCMAKE_BUILD_TYPE=Debug && cmake --build ./build --config Debug 

My goal is to be able to compile the Module for the main os 
| Windows | Mac OS X | Linux |
|---------|---------|---------|
| CommandInLine.exe |CommandInLine|CommandInLine |
|iDynamicLib.lib|iDynamicLib.a|iDynamicLib.a|
|Module.dll|Module.dylib|Module.so|
|Module.a|Module.a|Module.a|


