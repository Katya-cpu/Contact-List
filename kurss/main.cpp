#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "contactmodel.h"
#include "contactfiltermodel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QCoreApplication::setOrganizationName("YourCompany");
    QCoreApplication::setApplicationName("ContactList");

    qmlRegisterType<ContactModel>("contactlist", 1, 0, "ContactModel");
    qmlRegisterType<ContactFilterModel>("contactlist", 1, 0, "ContactFilterModel");

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("kurss", "Main");

    return app.exec();
}
