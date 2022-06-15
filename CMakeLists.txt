cmake_minimum_required(VERSION 3.10)

project(skeleton VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

# add the executable
add_executable(skeleton ./src/skeleton.cpp  ./src/View/view.cpp ./src/Controler/controler.cpp ./src/model/Rectangle.cpp ./src/model/Dessin.cpp src/model/Forme.cpp src/model/Point.cpp src/model/Oval.cpp src/model/Ligne.cpp)
target_link_libraries(skeleton ${wxWidgets_LIBRARIES})

include_directories(src src/View src/model src/Controler)
