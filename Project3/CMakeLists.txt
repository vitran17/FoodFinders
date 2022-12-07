#cmake_minimum_required(VERSION 3.21)
#project(Project3)
#
#set(CMAKE_CXX_STANDARD 14)
#
#add_executable(Project3 main.cpp restaurant.h restaurant.cpp)
cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Project3)


## If you want to link SFML statically
# set(SFML_STATIC_LIBRARIES TRUE)

## In most cases better set in the CMake cache
# set(SFML_DIR "<sfml root prefix>/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(Project3 main.cpp restaurant.h restaurant.cpp MainMenu.cpp MainMenu.h mainSFML.cpp)
target_link_libraries(Project3 sfml-graphics sfml-audio)