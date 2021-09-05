#ifndef OGLDRAW_H
#define OGLDRAW_H

#include <QOpenGLWidget>

// Класс OGLDraw наследуется от класса QOpenGLWidget.
class OGLDraw : public QOpenGLWidget
{
    Q_OBJECT

public:
    OGLDraw(QWidget *parent = nullptr);
    ~OGLDraw() override;

    // Метод draw(), получающий координаты х и у, с которых нужно начинать строить фигуру.
    // Тип фигуры задается третьим параметром.
    void draw(int xOffset, int yOffset, GLenum type);

protected:
    // Перезаписывает три виртуальных метода: initializeGL(), resizeGL() и paintGL().
    virtual void initializeGL() override;
    virtual void resizeGL(int nWidth, int nHeight) override;
    virtual void paintGL() override;
};
#endif // OGLDRAW_H
