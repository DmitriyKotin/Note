#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "logic/notedirector.h"
#include "logic/node.h"
#include "logic/account.h"
#include "logic/bankcard.h"
#include "logic/contact.h"
#include "logic/folder.h"
#include "logic/file.h"
#include "logic/memo.h"


//int main(int argc, char *argv[])
//{
//  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

//  QGuiApplication app(argc, argv);

//  logic::Director director;
//  director.init();

//  QQmlApplicationEngine engine;
//  engine.addImportPath("qrc:/");


//  qmlRegisterUncreatableType<presenter::Model>("rendall", 1, 0, "NodeModel", "can't create presenter::Model");
//  qmlRegisterUncreatableType<logic::Node>("rendall", 1, 0, "Node", "can't create Node");
//  qmlRegisterType<logic::Account>("rendall", 1, 0, "Account");
//  qmlRegisterType<logic::BankCard>("rendall", 1, 0, "BankCard");
//  qmlRegisterType<logic::Contact>("rendall", 1, 0, "Contact");
//  qmlRegisterType<logic::Folder>("rendall", 1, 0, "Folder");
//  qmlRegisterType<logic::File>("rendall", 1, 0, "File");
//  qmlRegisterType<logic::Memo>("rendall", 1, 0, "Memo");


//  engine.rootContext()->setContextProperty("Director", &director);
//  engine.rootContext()->setContextProperty("Presenter", director.presenter());

//  const QUrl url(QStringLiteral("qrc:/main.qml"));
//  QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
//                   &app, [url](QObject *obj, const QUrl &objUrl) {
//    if (!obj && url == objUrl)
//      QCoreApplication::exit(-1);
//  }, Qt::QueuedConnection);
//  engine.load(url);

//  return app.exec();
//}
