#include "openglwidget.h"

OpenGLWidget::OpenGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
}

OpenGLWidget::~OpenGLWidget()
{
}

/*virtual*/void OpenGLWidget::initializeGL()
{
}

/*virtual*/void OpenGLWidget::resizeGL(int nWidth, int nHeight)
{
}

/*virtual*/void OpenGLWidget::paintGL()
{
}
