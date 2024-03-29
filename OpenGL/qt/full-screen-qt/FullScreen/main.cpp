#include "openglwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OpenGLWidget w;

    // Поскольку класс QOpenGLWidget унаследован от QWidget, он обладает всеми свойствами,
    // присущими этому классу. Развернуть программу на полный экран очень просто - для этого
    // нужно заменить вызов метода

    //w.show();

    // на вызов метода
    w.showFullScreen();

    // В результате такой замены виджет верхнего уровня перекроет своим окном все остальные и займет весь
    // экран. Это очень удобно, так как дает возможность отлаживать программу в маленьком
    // окне, а когда она будет готова, просто поменять метод show() на showFullScreen().

    // Производительность ОреnGL-программы в полноэкранном режиме полностью зависит от
    // возможностей видеокарты.

    return a.exec();
}
