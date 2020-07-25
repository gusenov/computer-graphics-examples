cmake_minimum_required(VERSION 3.14)

project(GL07BouncingBall)

add_executable(
	GL07BouncingBall
	GL07BouncingBall.cpp
)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )
target_link_libraries(GL07BouncingBall ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
