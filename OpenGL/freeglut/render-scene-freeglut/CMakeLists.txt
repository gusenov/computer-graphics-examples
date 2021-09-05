cmake_minimum_required(VERSION 3.14)
project(RenderingTheScene)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME}
    main.cc
    OpenGLApplication.cc
)

target_compile_definitions(${PROJECT_NAME} PRIVATE
	GL_SILENCE_DEPRECATION
)

# OpenGL
find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
#

# freeglut
set(FREEGLUT_DIR "/usr/local/Cellar/freeglut")
target_include_directories(${PROJECT_NAME} PRIVATE ${FREEGLUT_DIR}/3.0.0/include/)
target_link_libraries(${PROJECT_NAME} ${FREEGLUT_DIR}/3.0.0/lib/libglut.dylib)
#
