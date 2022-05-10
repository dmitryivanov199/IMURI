cmake_minimum_required(VERSION 3.20)

project(IMURI)

set(CMAKE_CXX_STANDARD 11)

add_executable(IMURI main.cpp
        source/radio_app/radio_app.h
        source/radio_app/radio_app.cpp
        source/radio_app/radio_app_status/radio_app_status.h
        source/imuri/imuri.h
        source/radio_computer/radio_computer.h
        source/radio_computer/radio_computer.cpp
        source/error_codes/error_codes.h
        source/rap/rap_header.h
        source/rap/date.h
        source/rap/ura_code_section.h source/rap/padding_bit.h)