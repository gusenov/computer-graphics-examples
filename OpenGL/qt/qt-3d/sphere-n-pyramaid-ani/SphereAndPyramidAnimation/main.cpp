#include <QGuiApplication>
#include <QQuickView>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQuickView view;
    view.resize(300, 300);
    
    // Делает так, чтобы при изменении окна QQuickView автоматически
    // производились изменения размеров основного QМL-элемента в соответствии с новыми
    // размерами окна.
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    
    view.setSource(url);  // загружает исходный код QМL-программы
    
    view.show();
    return app.exec();
}
