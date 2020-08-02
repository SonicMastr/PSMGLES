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


file(GLOB_RECURSE sources CONFIGURE_DEPENDS src/*.c src/include/*.h)
set(source
  src/psmgles.c
  src/taiutils.c
  src/exports.c
  src/egl.c
  src/gl.c
  src/pgl.c
)


add_library(${PROJECT_NAME} STATIC ${sources})
#target_include_directories(${PROJECT_NAME} PUBLIC
#  src/include
#)

include_directories(src/include src/include/EGL src/include/GLES2 src/include/KHR src/include/PSMGLES)

target_link_libraries(${PROJECT_NAME}
  taihen_stub
  SceLibc_stub
  SceLibKernel_stub
  SceKernelThreadMgr_stub
  SceKernelModulemgr_stub
  SceSysmodule_stub
  SceIofilemgr_stub
)