#include "oglpyramid.h"
#include <QOpenGLFunctions>
#include <QMouseEvent>

OGLPyramid::OGLPyramid(QWidget *parent)
    : QOpenGLWidget(parent)

    // Инициализации переменных-членов для поворота.
    , m_xRotate(0)
    , m_yRotate(0)
{
}

OGLPyramid::~OGLPyramid()
{
}

/*virtual*/void OGLPyramid::initializeGL()
{
    QOpenGLFunctions* pFunc = QOpenGLContext::currentContext()->functions();

    // При инициализации с помощью метода glClearColor() устанавливается черный цвет очистки
    // буфера изображения.
    pFunc->glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // Функция glEnable() устанавливает режим разрешения проверки глубины фрагментов.
    pFunc->glEnable(GL_DEPTH_TEST);

    // Режим сглаживания цветов по умолчанию разрешен,
    // поэтому его необходимо отключить, передав в функцию glShadeMode() флаг GL_FLAT,
    // иначе боковые грани пирамиды будут иметь радужную окраску.
    glShadeModel(GL_FLAT);

    // Создает дисплейный список для пирамиды и возвращает
    // его номер, который присваивается переменной m_nPyrarnid. Параметр, передаваемый
    // в этот метод, задает размеры самой пирамиды.
    m_nPyramid = createPyramid(1.2f);
}

/*virtual*/void OGLPyramid::resizeGL(int nWidth, int nHeight)
{
    // устанавливает размеры видового окна равными размерам окна виджета.
    glViewport (0, 0, (GLint) nWidth, (GLint) nHeight);

    // делает текущей матрицу проектирования.
    glMatrixMode(GL_PROJECTION);

    // присваивает матрице проектирования единичную матрицу.
    glLoadIdentity();

    // задает так называемую пирамиду видимости.
    glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 10.0);
    // Ее параметры задают
    // положения левой, правой, верхней, нижней, передней и задней отсекающих плоскостей.
    // Последние два значения должны быть положительными и отсчитываться от центра проецирования
    // вдоль оси Z - по ним устанавливается значение перспективы.
}

/*virtual*/void OGLPyramid::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // При рисовании после очистки буфера изображения текущей устанавливается матрица моделирования,
    // служащая для задания положения объекта и его ориентации
    glMatrixMode(GL_MODELVIEW);

    // присваивает матрице моделирования единичную матрицу.
    glLoadIdentity();

    // сдвигает начало системы координат по оси Z на 3 единицы.
    glTranslatef(0.0, 0.0, -3.0);

    // поворачивает систему координат вокруг осей Х и У на угол, задаваемый переменными
    // m_xRotate и m_yRotate.
    glRotatef(m_xRotate, 1.0, 0.0, 0.0);
    glRotatef(m_yRotate, 0.0, 1.0, 0.0);

    // Передача в функцию glCallList() номера дисплейного списка пирамиды отобразит эту пирамиду.
    glCallList(m_nPyramid);
}

/*virtual*/void OGLPyramid::mousePressEvent(QMouseEvent* pe)
{
    // При нажатии пользователем кнопки мыши переменной m_ptPosition присваиваются координаты
    // указателя мыши
    m_ptPosition = pe->pos();
}

/*virtual*/void OGLPyramid::mouseMoveEvent(QMouseEvent* ре)
{
    // В методе обработки события перемещения мыши вычисляются углы поворота
    // для осей Х и У.
    m_xRotate += 180 * (GLfloat) (ре->y() - m_ptPosition.y()) / height ();
    m_yRotate += 180 * (GLfloat) (ре->x() - m_ptPosition.x()) / width();

    // Вызов метода updateGL () обновляет изображение на экране, используя новые углы поворота.
    // updateGL();  // error: use of undeclared identifier 'updateGL'

    // >> Just call update, that should be enough
    // https://forum.qt.io/topic/48468/how-to-use-updategl-method-qith-qglview/6
    update();

    // Переменной m_ptPosition присваивается актуальная координата указателя мыши.
    m_ptPosition = ре->pos();
}

// Метод createPyramid() создает дисплейный список для отображения пирамиды и возвращает его номер.
GLuint OGLPyramid::createPyramid(GLfloat fSize/*=1.0f*/)
{
    // возвращает первый свободный номер для идентификации дисплейного списка.
    GLuint n = glGenLists(1);

    // Этот номер передается в функцию glNewList().
    // Второй параметр, GL_COMPILE, говорит о том, что команды нужно лишь запомнить.
    glNewList(n, GL_COMPILE);

        // Все команды, находящиеся между функциями glNewList() и glEndList(), помещаются
        // в соответствующий дисплейный список.

        // Тип GL_TRIANGLE_FAN задает треугольники с общей вершиной, которая идет первой в списке.
        glBegin(GL_TRIANGLE_FAN);
            glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
            glVertex3f(0.0, fSize, 0.0);

            // Следующие две вершины задают треугольник.
            glVertex3f(-fSize, -fSize, fSize);
            glVertex3f(fSize, -fSize, fSize);

            // Затем каждая последующая вершина, совместно с предыдущей, задает следующий треугольник.
            glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
            glVertex3f(fSize, -fSize, -fSize);

            glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
            glVertex3f(-fSize, -fSize, -fSize);

            glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
            glVertex3f(-fSize, -fSize, fSize);
        glEnd();

        // А для типа фигуры GL_QUADS каждые четыре вершины задают четырехугольник.
        glBegin(GL_QUADS);
            glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
            glVertex3f(-fSize, -fSize, fSize);
            glVertex3f(fSize, -fSize, fSize);
            glVertex3f(fSize, -fSize, -fSize);
            glVertex3f(-fSize, -fSize, -fSize);
        glEnd();
    glEndList () ;
    return n;
}
