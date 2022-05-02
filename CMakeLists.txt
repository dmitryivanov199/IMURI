cmake_minimum_required(VERSION 3.20)

project(IMURI)

set(CMAKE_CXX_STANDARD 14)

add_executable(IMURI main.cpp
        source/radio_app/radio_app.h
        source/radio_app/radio_app.cpp
        source/radio_app/ra_option/ra_option.h
        source/radio_app/radio_app_status/radio_app_status.h
        source/imuri/imuri.h
        source/imuri/administrative_services.h
        source/imuri/access_control_services.h
        source/imuri/data_flow_services.h
        source/radio_app/ra_parameter/ra_parameter.h
        source/radio_computer/radio_computer.h
        source/radio_computer/radio_computer.cpp
        source/error_codes/error_codes.h
        source/rap/rap_header.h
        source/rap/date.h
        source/rap/ura_code_section.h source/rap/padding_bit.h)