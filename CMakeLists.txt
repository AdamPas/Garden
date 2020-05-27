cmake_minimum_required(VERSION 3.15)
project(Garden LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(LIBRARY_VERSIONED "${PROJECT_NAME}")
SET(CMAKE_BUILD_TYPE "Debug")

# -------------- Add subdirectories with own CMakeFile.txt ----------- #
# The compiled library code is here
add_subdirectory(src)

# The executable code is here
add_subdirectory(bin)
# -------------- Add subdirectories with own CMakeFile.txt ----------- #

