cmake_minimum_required(VERSION 3.0)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(SimplyGB)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(SOURCES
  src/audio.cpp
  src/cart.cpp
  src/cpu.cpp
  src/gameboy.cpp
  src/gpu.cpp
  src/input.cpp
  src/instructions.cpp
  src/main.cpp
  src/mmu.cpp
)

add_executable(SimplyGB ${SOURCES})
