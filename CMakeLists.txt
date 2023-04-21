cmake_minimum_required(VERSION 3.23)
project(cpp_lab4)
set(CMAKE_CXX_STANDARD 14)

add_executable(cpp_lab4 main.cpp src/App.cpp src/App.h src/Service/ConsoleDisplayService.cpp src/Service/ConsoleDisplayService.h src/Service/DisplayServiceInterface.h src/Service/ExceptionService.h src/Geometry/Ellipse.cpp src/Geometry/Ellipse.h src/Service/FigureContainer.h src/Geometry/Figure.h src/Service/FigureContaienr.cpp src/Geometry/Triangle.cpp src/Geometry/Triangle.h)
