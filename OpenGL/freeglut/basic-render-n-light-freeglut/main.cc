#include "FreeGLUTCallbacks.h"

int main(int argc, char** argv)
{
    OpenGLApplication demo;
    return glutmain(argc, argv, 1024, 768, "OpenGL", &demo);
}
