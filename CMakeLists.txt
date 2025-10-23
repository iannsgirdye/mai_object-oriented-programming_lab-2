cmake_minimum_required(VERSION 3.10)
project(mai_object-oriented-programming_lab-2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Пути к исходникам
include_directories(include)

# Основная библиотека
add_library(eleven_lib
  src/arithmetic.cpp
  src/compare.cpp
  src/constructors.cpp
  src/utilities.cpp
)

# Программа
add_executable(main_app ./src/main.cpp)
target_link_libraries(main_app PRIVATE eleven_lib)

# Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Тесты
add_executable(tests tests.cpp)
target_link_libraries(tests PRIVATE eleven_lib gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)
