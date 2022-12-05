cmake_minimum_required(VERSION 3.23)
project(Automatic_Bargain_Hunting C)

set(CMAKE_C_STANDARD 11)

add_executable(Automatic_Bargain_Hunting src/main.c)

add_executable(Composition src/Composition.c)
add_executable(Data_collection src/Data_collection.c)
add_executable(Functions src/functions.c)
