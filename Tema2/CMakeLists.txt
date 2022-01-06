#CMake version
cmake_minimum_required(VERSION 3.0)





set(myproject "exec")
#Project name
project(${myproject})


#Specify the required C++ standard
set(CMAKE_CXX STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)



#Define executable
add_executable(${PROJECT_NAME} 
	Main.cpp
	Pasare.cpp
	Rata.cpp)


