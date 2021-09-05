#include "BulletOpenGLApplication.h"
#include "FreeGLUTCallbacks.h"

int main(int argc, char** argv)
{
	BulletOpenGLApplication demo;
	return glutmain(argc, argv, 640, 360, "Introduction to Game Physics with Bullet Physics and OpenGL", &demo);
}