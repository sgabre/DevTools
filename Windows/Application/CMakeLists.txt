cmake_minimum_required(VERSION 3.10)
project(Static LANGUAGES C)

# Ajouter l'exécutable
add_executable(Static src/main.c)

# Spécifier l'emplacement de MyLibrary (ajuste le chemin si nécessaire)
set(LIB_PATH "../Libraries")

# Inclure les headers de la bibliothèque
target_include_directories(Static PRIVATE "${LIB_PATH}/inc")

# Lier la DLL (on lie avec le fichier .lib sous Windows)
target_link_libraries(Static "${LIB_PATH}/DLL/Wrapper.lib")

# Copier la DLL dans le dossier de l'exécutable après la compilation
add_custom_command(TARGET Static POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${MYLIB_PATH}/Wrapper.dll"
    "$<TARGET_FILE_DIR:Static>"
)