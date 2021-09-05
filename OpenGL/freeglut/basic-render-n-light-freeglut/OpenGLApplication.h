#ifndef _OPENGLAPP_H_
#define _OPENGLAPP_H_

#ifdef _MSC_VER
#include <Windows.h>
#include <GL/GL.h>
#elif __APPLE__
#include <OpenGL/GL.h>
#endif

#include <GL/freeglut.h>

#include <array>
#include <cmath>
using Vector3 = std::array<float, 3>;
inline float getX(Vector3 const& v) { return v[0]; }
inline float getY(Vector3 const& v) { return v[1]; }
inline float getZ(Vector3 const& v) { return v[2]; }
inline void normalize(Vector3& v) {
	auto len = std::sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
	v[0] /= len; v[1] /= len; v[2] /= len;
}
inline Vector3 cross(Vector3 const& v1, Vector3 const& v2) {
	return Vector3{getY(v1) * getZ(v2) - getZ(v1) * getY(v2),
				   getZ(v1) * getX(v2) - getX(v1) * getZ(v2),
				   getX(v1) * getY(v2) - getY(v1) * getX(v2)};
}
inline Vector3 operator-(Vector3 const& a, Vector3 const& b) {
	return Vector3{getX(a)-getX(b), getY(a)-getY(b), getZ(a)-getZ(b)};
}

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

	// drawing functions
	void DrawBox(const Vector3 &halfSize, const Vector3 &color = Vector3 {1.0f, 1.0f, 1.0f});

protected:
	// camera control
	Vector3 m_cameraPosition; // the camera's current position
	Vector3 m_cameraTarget;	 // the camera's lookAt target
	float m_nearPlane; // minimum distance the camera will render
	float m_farPlane; // farthest distance the camera will render
	Vector3 m_upVector; // keeps the camera rotated correctly

	int m_screenWidth;
	int m_screenHeight;
};

#endif
