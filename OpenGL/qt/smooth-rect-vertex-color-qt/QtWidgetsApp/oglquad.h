#ifndef OGLQUAD_H
#define OGLQUAD_H

#include <QOpenGLWidget>

// Чтобы воспользоваться OpenGL, необходимо унаследовать класс QOpenGLWidget. Как видно
// из названия, этот класс является виджетом и организует соединение с функциями библиотеки
// OpenGL.
// Объекты класса QOpenGLWidget могут также использоваться в качестве контекста рисования
// для QPainter.

// ======================================================================
class OGLQuad : public QOpenGLWidget
{
    Q_OBJECT

    // В унаследованном от QOpenGLWidget классе необходимо, по меньшей мере, переопределить
    // три виртуальных метода: initializeGL(), resizeGL() и paintGL(). Эти методы определены
    // в классе QOpenGLWidget как virtual protected.
protected:
    void initializeGL() override;
    void resizeGL(int nWidth, int nHeight) override;
    void paintGL() override;

public:
    OGLQuad(QWidget *parent = nullptr);
    ~OGLQuad() override;
};
#endif // OGLQUAD_H
