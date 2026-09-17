
cmake_minimum_required(VERSION 3.20)

project(password_generator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

FetchContent_Declare(
    nana
    GIT_REPOSITORY https://github.com/cnjinhao/nana.git
    GIT_TAG        master
)

FetchContent_MakeAvailable(nana)

add_executable(password_generator
    src/main.cpp
)

target_link_libraries(password_generator
    PRIVATE
        nana
)
