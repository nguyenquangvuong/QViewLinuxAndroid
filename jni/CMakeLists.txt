# 
#   CMakeLists.txt
#   QView v1.0
# 
#   Created by Luu Kien on 16/02/2023
#   Copyright © 2020 16/02/2023. All rights reserved.
# 

cmake_minimum_required(VERSION 3.0)

# C++ std 14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-no-pie")

project(QView1.0)

#OpenCV
set(OpenCV_DIR ${CMAKE_SOURCE_DIR}/local)
find_package(OpenCV REQUIRED HINTS ${OpenCV_DIR})
#find_package(OpenCV REQUIRED)
 
#Libevent
set(LIBEVENT_LIBS "-levent")
find_library(EVENT_LIBRARY REQUIRED PATHS /usr/lib /usr/local/lib)

#OpenGL 
#find_package(OpenGL REQUIRED)

#glfw3
#set(glfw3_LIBS "-lglfw" )
#find_package(glfw3 REQUIRED) 

#GLUT 
#find_package(GLUT REQUIRED)
#include_directories(${GLUT_INCLUDE_DIRS})

#Setup
include_directories(glad/include)
file(GLOB SOURCES *.cpp )
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
    ${OpenCV_LIBS}
    ${LIBEVENT_LIBS}
    -lpthread
)

