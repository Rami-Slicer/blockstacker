cmake_minimum_required(VERSION 3.0.0)
project(blockstacker VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic")
# set(CMAKE_BUILD_TYPE debug)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

add_subdirectory(src/)
add_subdirectory(libnbtplusplus/)
add_subdirectory(voxelite/)



include_directories(include/)
include_directories(voxelite/include/)
include_directories(/usr/include/python3.9/)

link_libraries(z python3.9)

# find_package(Boost REQUIRED)


add_executable(blockstacker ${blockstacker_SRC})
target_link_libraries(blockstacker nbt++)
target_link_libraries(blockstacker voxelite)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
