cmake_minimum_required(VERSION 3.15)
project(Extraclase1)

set(CMAKE_PREFIX_PATH "/home/gretchell/Qt5.14.1/5.14.1/gcc_64")

set(CMAKE_CXX_STANDARD 14)
find_package(Qt5Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_executable(Extraclase1 GUI/main.cpp GUI/mainwindow.cpp GUI/mainwindow.h GUI/mainwindow.ui GUI/ui_mainwindow.h Socket/cliente.cpp Socket/cliente.h)
target_link_libraries(Extraclase1 Qt5::Core Qt5::Widgets)