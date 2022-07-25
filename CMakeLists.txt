cmake_minimum_required(VERSION 3.21)
project(my_containers)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(my_containers main.cpp MyArray.h MyArray.cpp MyVector.h MyVector.cpp test.cpp)

target_link_libraries(my_containers gtest_main)
add_test(NAME my_containers_test COMMAND my_containers)



