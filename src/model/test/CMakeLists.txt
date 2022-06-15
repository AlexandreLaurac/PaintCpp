cmake_minimum_required(VERSION 3.10)

project(skeleton VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

# add the executable
add_executable(test ./main.cpp  ../Dessin.cpp ../Forme.cpp ../Point.cpp ../Rectangle.cpp ../Oval.cpp)
target_link_libraries(test ${wxWidgets_LIBRARIES})

include_directories(..)
