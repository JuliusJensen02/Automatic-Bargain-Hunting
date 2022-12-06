cmake_minimum_required(VERSION 3.23)
project(Automatic_Bargain_Hunting C)

set(CMAKE_C_STANDARD 11)



add_library(Data_collection src/Data_collection.c)
add_library(Function        src/functions.c)
add_library(Comparison      src/price_comparison.c)


add_executable(Automatic_Bargain_Hunting src/main.c)

target_link_libraries(Automatic_Bargain_Hunting Data_collection)
target_link_libraries(Automatic_Bargain_Hunting Function)
target_link_libraries(Automatic_Bargain_Hunting Comparison)
