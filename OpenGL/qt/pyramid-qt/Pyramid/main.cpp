#include "oglpyramid.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OGLPyramid w;
    w.resize(200, 200);
    w.show();
    return a.exec();
}
