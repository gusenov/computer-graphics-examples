#ifndef OGLPYRAMID_H
#define OGLPYRAMID_H

#include <QOpenGLWidget>

class OGLPyramid : public QOpenGLWidget
{
    Q_OBJECT

public:
    OGLPyramid(QWidget *parent = nullptr);
    ~OGLPyramid() override;

protected:
    // Методы, унаследованные от QOpenGLWidget.
    virtual void initializeGL() override;
    virtual void resizeGL(int nWidth, int nНeight) override;
    virtual void paintGL() override;

    // Переопределяются методы обработки
    // события мыши mousePressEvent() и mouseMoveEvent() для осуществления поворота пирамиды.
    virtual void mousePressEvent(QMouseEvent* pe) override;
    virtual void mouseMoveEvent(QMouseEvent* ре) override;

    // Создает дисплейный список для отображения объекта пирамиды.
    GLuint createPyramid(GLfloat fSize = 1.0f);

private:
    GLuint m_nPyramid;  // хранит номер дисплейного списка объекта пирамиды.
    // Дисплейные списки позволяют выделить конкретный набор команд, запомнить его и вызывать
    // всякий раз, когда в нем возникает необходимость. Этот механизм очень похож на вызов
    // обычных функций или на механизм записи графических команд, предоставляемый
    // классом QPicture. Для запуска команд дисплейного списка необходимо знать присвоенный
    // ему уникальный номер.

    // для хранения углов поворота по осям Х и У.
    GLfloat m_xRotate;
    GLfloat m_yRotate;

    QPoint m_ptPosition;  // хранит координату указателя мыши в момент нажатия.
};
#endif // OGLPYRAMID_H
