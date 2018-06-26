#include <QGuiApplication>
#include <app.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication application(argc, argv);
    App app;
    Q_UNUSED(app)
    return application.exec();
}
