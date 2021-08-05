cmake_minimum_required(VERSION 3.20)

project(IMURI)

set(CMAKE_CXX_STANDARD 14)
set(CPPUTEST_HOME "/home/apt-15/Docs/soft/cpputest-3.8/")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I${CPPUTEST_HOME}/include")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -include ${CPPUTEST_HOME}/include/CppUTest/MemoryLeakDetectorNewMacros.h")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -include ${CPPUTEST_HOME}/include/CppUTest/MemoryLeakDetectorMallocMacros.h")

set(CMAKE_CXX_STANDARD_LIBRARIES "${CMAKE_CXX_STANDARD_LIBRARIES} -L${CPPUTEST_HOME}/lib -lCppUTest -lCppUTestExt")

add_executable(IMURI main.cpp
        source/md5/md5.h
        source/md5/md5.cpp
        source/radio_app/radio_app.h
        source/radio_app/radio_app.cpp
        source/radio_app/ra_option_id/ra_option_id.h
        tests/md5/test.cpp)