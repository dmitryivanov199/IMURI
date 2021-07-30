cmake_minimum_required(VERSION 3.20)
project(IMURI)

set(CMAKE_CXX_STANDARD 14)

add_executable(IMURI main.cpp source/md5/md5.h source/md5/md5.cpp source/radio_app/radio_app.h source/radio_app/radio_app.cpp source/radio_app/ra_option_id/ra_option_id.h)
