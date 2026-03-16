#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtWebView>
#include <QMessageBox>
#include <QObject>

// User defined headers
#include "dscontroller.h"
#include "requests.h"
#include "permissionmanager.h"
#include "singleinstanceguard.h"
#include "globals.h"

int main(int argc, char *argv[])
{
    QtWebView::initialize();        // WebEngine init
    QApplication app(argc, argv);   // App init
    qApp->setApplicationName("co.ke.codeart.digisto");

    // Register message handler
    // qInstallMessageHandler(Configurator::messageHandler);

    // Make sure there is no other instance running
    SingleInstanceGuard instance("Digisto");
    if (!instance.tryToRun()) {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Icon::Critical);
        msgBox.setText(
            QString(QObject::tr("There is another %1 instance running!\n"))
                .arg("Digisto"));
        msgBox.exec();
        return 127;
    }

    // Create the dscontroller instance
    DsController dsController;
    PermissionManager pMan{&dsController, &dsController};
    QQmlApplicationEngine engine;

    // Register dscontroller to QML
    engine.rootContext()->setContextProperty("dsController", &dsController);
    engine.rootContext()->setContextProperty("dsPermissionManager", &pMan);

    qmlRegisterType<Requests>("app.digisto.modules", 1, 0, "Requests");
    // qmlRegisterSingletonType(QUrl("qrc:/app/digisto/modules/Theme.qml"), "app.digisto.modules", 1, 0, "Theme");
    // qmlRegisterSingletonType(QUrl("qrc:/app/digisto/modules/IconType.qml"), "app.digisto.modules", 1, 0, "IconType");

    const QUrl url(QStringLiteral("qrc:/ui/Main.qml"));

    engine.addImportPath(":/");

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
