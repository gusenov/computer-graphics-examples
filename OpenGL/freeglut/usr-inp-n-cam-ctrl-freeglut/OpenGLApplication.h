#ifndef _BULLETOPENGLAPP_H_
#define _BULLETOPENGLAPP_H_

#ifdef _MSC_VER
#include <Windows.h>
#include <GL/GL.h>
#elif __APPLE__
#include <OpenGL/GL.h>
#endif

#include <GL/freeglut.h>

#include "Vec3.h"

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

	// camera functions
	void UpdateCamera();
	void RotateCamera(float &angle, float value);
	void ZoomCamera(float distance);

	// drawing functions
	void DrawBox(const Vec3f &halfSize, const Vec3f &color = Vec3f(1.0f, 1.0f, 1.0f));

protected:
	// camera control
	Vec3f m_cameraPosition; // the camera's current position
	Vec3f m_cameraTarget;	 // the camera's lookAt target
	float m_nearPlane; // minimum distance the camera will render
	float m_farPlane; // farthest distance the camera will render
	Vec3f m_upVector; // keeps the camera rotated correctly
	float m_cameraDistance; // distance from the camera to its target
	float m_cameraPitch; // pitch of the camera 
	float m_cameraYaw; // yaw of the camera

	int m_screenWidth;
	int m_screenHeight;
};
#endif
