cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)

project(TD03)

function(add_exercise FOLDER)
    file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS ${FOLDER}/*.cpp)
    set(PROJECT_INCLUDE ${FOLDER}/)

    add_executable(${FOLDER} ${PROJECT_SOURCES})
endfunction(add_exercise)


add_exercise(Exo1)
add_exercise(Exo2)
add_exercise(Exo3)