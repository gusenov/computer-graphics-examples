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

	// create some floats for our ambient, diffuse, specular and position
	GLfloat ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f }; // dark grey
	GLfloat diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // white
	GLfloat specular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // white
	GLfloat position[] = { 5.0f, 10.0f, 1.0f, 0.0f };

	// set the ambient, diffuse, specular and position for LIGHT0
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0, GL_POSITION, position);

	glEnable(GL_LIGHTING); // enables lighting
	glEnable(GL_LIGHT0); // enables the 0th light
	glEnable(GL_COLOR_MATERIAL); // colors materials when lighting is enabled

	// enable specular lighting via materials
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMateriali(GL_FRONT, GL_SHININESS, 15);

	// enable smooth shading
	glShadeModel(GL_SMOOTH);

	// enable depth testing to be 'less than'
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

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

	// draw a simple box of size 1
	// also draw it red
	DrawBox(Vector3{1, 1, 1});

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
	gluLookAt(m_cameraPosition[0], m_cameraPosition[1], m_cameraPosition[2], m_cameraTarget[0], m_cameraTarget[1], m_cameraTarget[2], getX(m_upVector), getY(m_upVector), getZ(m_upVector));
	// the view matrix is now set
}

void OpenGLApplication::DrawBox(const Vector3 &halfSize, const Vector3 &color) {
	float halfWidth = getX(halfSize);
	float halfHeight = getY(halfSize);
	float halfDepth = getZ(halfSize);

	// set the object's color
	glColor3f(getX(color), getY(color), getZ(color));

	// create the vertex positions
	Vector3 vertices[8]={
	Vector3{halfWidth,halfHeight,halfDepth},
	Vector3{-halfWidth,halfHeight,halfDepth},
	Vector3{halfWidth,-halfHeight,halfDepth},
	Vector3{-halfWidth,-halfHeight,halfDepth},
	Vector3{halfWidth,halfHeight,-halfDepth},
	Vector3{-halfWidth,halfHeight,-halfDepth},
	Vector3{halfWidth,-halfHeight,-halfDepth},
	Vector3{-halfWidth,-halfHeight,-halfDepth}};

	// create the indexes for each triangle, using the
	// vertices above. Make it static so we don't waste
	// processing time recreating it over and over again
	static int indices[36] = {
		0,1,2,
		3,2,1,
		4,0,6,
		6,0,2,
		5,1,4,
		4,1,0,
		7,3,1,
		7,1,5,
		5,4,7,
		7,4,6,
		7,2,3,
		7,6,2};

	// start processing vertices as triangles
	glBegin (GL_TRIANGLES);

	// increment the loop by 3 each time since we create a
	// triangle with 3 vertices at a time.

	for (int i = 0; i < 36; i += 3) {
		// get the three vertices for the triangle based
		// on the index values set above
		// use const references so we don't copy the object
		// (a good rule of thumb is to never allocate/deallocate
		// memory during *every* render/update call. This should
		// only happen sporadically)
		const Vector3 &vert1 = vertices[indices[i]];
		const Vector3 &vert2 = vertices[indices[i+1]];
		const Vector3 &vert3 = vertices[indices[i+2]];

		// create a normal that is perpendicular to the
		// face (use the cross product)
		Vector3 normal = cross(vert3-vert1, vert2-vert1);
		normalize(normal);

		// set the normal for the subsequent vertices
		glNormal3f(getX(normal),getY(normal),getZ(normal));

		// create the vertices
		glVertex3f (getX(vert1), getY(vert1), getZ(vert1));
		glVertex3f (getX(vert2), getY(vert2), getZ(vert2));
		glVertex3f (getX(vert3), getY(vert3), getZ(vert3));
	}

	// stop processing vertices
	glEnd();
}