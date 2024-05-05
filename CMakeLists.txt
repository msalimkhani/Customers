cmake_minimum_required(VERSION 3.26)
project(Customers)
set(CMAKE_CXX_STANDARD 17)
include_directories(include
                    src)
file(GLOB SRCS "include/*" "src/*")
add_executable(customers ${SRCS})