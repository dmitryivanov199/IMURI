cmake_minimum_required(VERSION 3.20)

project(IMURI)

set(CMAKE_CXX_STANDARD 14)

add_executable(IMURI main.cpp
        source/md5/md5.h
        source/md5/md5.cpp
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
        source/csl/administrator/administrator.h
        source/csl/mobility_policy_manager/mobility_policy_manager.h
        source/csl/networking_stack/networking_stack.h
        source/csl/monitor/monitor.h
        source/rcf/configuration_manager/configuration_manager.h
        source/rcf/radio_connection_manager/radio_connection_manager.h
        source/rcf/multi_radio_controller/multi_radio_controller.h
        source/rcf/resource_manager/resource_manager.h
        source/rcf/flow_controller/flow_controller.h
        source/csl/administrator/administrator.cpp
        source/rcf/configuration_manager/configuration_manager.cpp
        source/file_manager/file_manager.h
        source/file_manager/file_manager.cpp)