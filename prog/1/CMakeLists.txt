cmake_minimum_required(VERSION 4.3)

project(main1_1 C)

set(CMAKE_C_STANDARD 11)

add_executable(main1_1 pw01-1.c
        main1.2.c
        main1.3.c
        main1.4.c
        main1.5.c
        main1.6.c
        main1.7.c
        main1.8.c
        main1.9.cpp
        main1.10.cpp)

target_link_libraries(main1_1 C)