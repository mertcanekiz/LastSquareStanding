cmake_minimum_required(VERSION 2.8)
project(lss)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ..)
file(GLOB SOURCE_FILES
    "src/*.h"
    "src/*.cc")
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
include(FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2_image REQUIRED sdl2_image)
pkg_search_module(SDL2_ttf REQUIRED sdl2_ttf)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2_image_LIBRARIES} ${SDL2_ttf_LIBRARIES})
