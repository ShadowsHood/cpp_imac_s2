# la version de cmake à utiliser
cmake_minimum_required(VERSION 3.0)

# La version du C++ que l'on souhaite utiliser (dans notre cas C++17)
set(CMAKE_CXX_STANDARD 17)

# Le nom du projet
project(TD01)

# On souhaite placer l'exécutable dans un sous-dossier "bin" au lieu de le mettre dans le dossier build
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# On indique que l'on souhaite faire un exécutable avec nos deux fichiers .cpp
add_executable(exo "src/main.cpp" "src/utils.cpp" "src/fraction.cpp")

# le dossier contenant les fichiers d'en-tête pour notre executable helloImac
target_include_directories(exo PUBLIC "src/")