#include "OpenGLApplication.h"

OpenGLApplication::OpenGLApplication()
    : m_cameraPosition(Vector3 {10.0f, 5.0f, 0.0f})
    , m_cameraTarget(Vector3 {0.0f, 0.0f, 0.0f})
    , m_upVector(Vector3 {0.0f, 1.0f, 0.0f})
    , m_nearPlane(1.0f)
    , m_farPlane(1000.0f)
{}

OpenGLApplication::~OpenGLApplication() = default;

void OpenGLApplication::Initialize() 
{
    // this function is called inside glutmain() after
    // creating the window, but before handing control
    // to FreeGLUT

    // set the backbuffer clearing color to a lightish blue
    glClearColor(0.6, 0.65, 0.85, 0);
}

void OpenGLApplication::Keyboard(unsigned char key, int x, int y) 
{}

void OpenGLApplication::KeyboardUp(unsigned char key, int x, int y)
{}

void OpenGLApplication::Special(int key, int x, int y) 
{}

void OpenGLApplication::SpecialUp(int key, int x, int y) 
{}

void OpenGLApplication::Reshape(int w, int h) 
{
    // this function is called once during application intialization
    // and again every time we resize the window

    // grab the screen width/height
    m_screenWidth = w;
    m_screenHeight = h;
    // set the viewport
    glViewport(0, 0, w, h);
    // update the camera
    UpdateCamera();
}

void OpenGLApplication::Idle() 
{
    // this function is called frequently, whenever FreeGlut
    // isn't busy processing its own events. It should be used
    // to perform any updating and rendering tasks

    // clear the backbuffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // update the camera
    UpdateCamera();

    // swap the front and back buffers
    glutSwapBuffers();
}

void OpenGLApplication::Mouse(int button, int state, int x, int y) 
{}

void OpenGLApplication::PassiveMotion(int x, int y) 
{}

void OpenGLApplication::Motion(int x, int y) 
{}

void OpenGLApplication::Display() 
{}

void OpenGLApplication::UpdateCamera() {
	// exit in erroneous situations
	if (m_screenWidth == 0 && m_screenHeight == 0)
		return;

	// select the projection matrix
	glMatrixMode(GL_PROJECTION);
	// set it to the matrix-equivalent of 1
	glLoadIdentity();
	// determine the aspect ratio of the screen
	float aspectRatio = m_screenWidth / (float)m_screenHeight;
	// create a viewing frustum based on the aspect ratio and the
	// boundaries of the camera
	glFrustum (-aspectRatio * m_nearPlane, aspectRatio * m_nearPlane, -m_nearPlane, m_nearPlane, m_nearPlane, m_farPlane);
	// the projection matrix is now set

	// select the view matrix
	glMatrixMode(GL_MODELVIEW);
	// set it to '1'
	glLoadIdentity();
	// create a view matrix based on the camera's position and where it's
	// looking
	gluLookAt(m_cameraPosition[0], m_cameraPosition[1], m_cameraPosition[2], 
              m_cameraTarget[0], m_cameraTarget[1], m_cameraTarget[2], 
              getX(m_upVector), getY(m_upVector), getZ(m_upVector));
	// the view matrix is now set
}
