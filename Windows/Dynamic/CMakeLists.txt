cmake_minimum_required(VERSION 3.10)
project(Dynamic LANGUAGES C)

# Ajouter l'exécutable
add_executable(Dynamic src/main.c)

# Copier la DLL après compilation pour s'assurer qu'elle est bien présente
set(LIB_PATH "../Libraries")

add_custom_command(TARGET Dynamic POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${LIB_PATH}/DLL/Wrapper.dll"
    "$<TARGET_FILE_DIR:Dynamic>"
)
