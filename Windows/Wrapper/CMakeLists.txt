cmake_minimum_required(VERSION 3.10)
project(Wrapper LANGUAGES C)

add_library(Wrapper SHARED src/mylib.c)
target_include_directories(Wrapper PUBLIC include)

# Définir WRAPPER_EXPORTS pour la compilation de la DLL
target_compile_definitions(Wrapper PRIVATE WRAPPER_EXPORTS)