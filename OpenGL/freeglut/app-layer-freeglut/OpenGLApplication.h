#ifndef _OPENGLAPP_H_
#define _OPENGLAPP_H_

#ifdef _MSC_VER
#include <Windows.h>
#include <GL/GL.h>
#elif __APPLE__
#include <OpenGL/GL.h>
#endif

#include <GL/freeglut.h>

class OpenGLApplication {
public:
	OpenGLApplication();
	~OpenGLApplication();
	void Initialize();
	// FreeGLUT callbacks //
	virtual void Keyboard(unsigned char key, int x, int y);
	virtual void KeyboardUp(unsigned char key, int x, int y);
	virtual void Special(int key, int x, int y);
	virtual void SpecialUp(int key, int x, int y);
	virtual void Reshape(int w, int h);
	virtual void Idle();
	virtual void Mouse(int button, int state, int x, int y);
	virtual void PassiveMotion(int x, int y);
	virtual void Motion(int x, int y);
	virtual void Display();
};

#endif
