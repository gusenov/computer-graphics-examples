cmake_minimum_required(VERSION 3.14)

# Здесь указзывается, что проект только на языке C,
# поэтому будет использоваться C compiler установленный в системе по умолчанию.
project(solid-sphere-animation C)

add_executable(
	solid-sphere-animation
	sinsphere.c
)

# find_package(OpenGL) найдет пакет, но не будет линковать пакет к таргету.
find_package(OpenGL REQUIRED)
# Для того чтобы убедиться, что OpenGL действительно найден можно проверить
# OpenGL_FOUND или использовать REQUIRED, который остановит cmake, если не
# найдет OpenGL.

find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

# target_link_libraries(<target> <item>)
target_link_libraries(solid-sphere-animation ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
