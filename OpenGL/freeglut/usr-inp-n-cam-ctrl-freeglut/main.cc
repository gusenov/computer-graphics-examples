#include "FreeGLUTCallbacks.h"

int main(int argc, char** argv)
{
	OpenGLApplication demo;
	return glutmain(argc, argv, 640, 360, "OpenGL", &demo);
}
