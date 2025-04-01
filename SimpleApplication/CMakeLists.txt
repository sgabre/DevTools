cmake_minimum_required(VERSION 3.20)
project(Simply LANGUAGES C)

add_executable(Simply)
target_sources(Simply PRIVATE Application.c Module.c Module.h)
install(TARGETS Simply)

