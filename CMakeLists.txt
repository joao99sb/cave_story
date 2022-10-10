cmake_minimum_required(VERSION 3.7.0)
project(cave_story VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_COMPILE "/usr/bin/g++")

# or
# but this way is less recommended
# see why: https://stackoverflow.com/questions/1027247/is-it-better-to-specify-source-files-with-glob-or-each-file-individually-in-cmak/1060061#1060061
# file(GLOB  SRC_FILES src/*.h src/*.cpp)
# add_executable(cave_story_bin src/main.cpp ${SRC_FILES})

# add_executable(cave_story_bin src/main.cpp src/game.cpp src/game.h)
target_link_libraries(cave_story_bin SDL2main SDL2)

target_compile_features(cave_story_bin PRIVATE cxx_std_14)