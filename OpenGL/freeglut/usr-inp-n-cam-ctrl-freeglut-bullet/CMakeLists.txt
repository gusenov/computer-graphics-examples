cmake_minimum_required(VERSION 3.14)
project(UserInputAndCameraControl)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME}
    main.cpp
    BulletOpenGLApplication.cpp
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

# Bullet
target_include_directories(${PROJECT_NAME} PRIVATE "/usr/local/include/bullet/")
target_link_directories(${PROJECT_NAME} PRIVATE "/usr/local/lib/")
target_link_libraries(${PROJECT_NAME}
	Bullet2FileLoader
	Bullet3Collision
	Bullet3Common
	Bullet3Dynamics
	Bullet3Geometry
	Bullet3OpenCL_clew
	BulletCollision
	BulletDynamics
	BulletFileLoader
	BulletInverseDynamics
	BulletInverseDynamicsUtils
	BulletRobotics
	BulletSoftBody
	BulletWorldImporter
	BulletXmlWorldImporter
	ConvexDecomposition
	GIMPACTUtils
	HACD
	LinearMath)
#
