#include "oglquad.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OGLQuad w;  // объект класса OGLQuad, унаследованный от класса QOpenGLWidget.
    w.resize(200, 200);
    w.show();
    return a.exec();
}
