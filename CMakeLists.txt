cmake_minimum_required(VERSION 2.8)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  if(DEFINED ENV{DOLCESDK})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{DOLCESDK}/share/dolce.toolchain.cmake" CACHE PATH "toolchain file")
  else()
    message(FATAL_ERROR "Please define DOLCESDK to point to your SDK path!")
  endif()
endif()

project(PsmGLES)
include("${DOLCESDK}/share/dolce.cmake" REQUIRED)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D__VITA__ -Wall -fno-lto -nostdlib")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(source
  src/psmgles.c
  src/taiutils.c
  src/exports.c
)


add_library(${PROJECT_NAME} STATIC ${source})

target_include_directories(${PROJECT_NAME} PUBLIC
  src/include
)