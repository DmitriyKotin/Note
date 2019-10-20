#include <QApplication>
#include <FelgoApplication>
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


// uncomment this line to add the Live Client Module and use live reloading with your custom C++ code
//#include <FelgoLiveClient>


int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  FelgoApplication felgo;

  // Use platform-specific fonts instead of Felgo's default font
  felgo.setPreservePlatformFonts(true);

  QQmlApplicationEngine engine;
  engine.addImportPath("qrc:/");

  felgo.initialize(&engine);

  // Set an optional license key from project file
  // This does not work if using Felgo Live, only for Felgo Cloud Builds and local builds
  felgo.setLicenseKey(PRODUCT_LICENSE_KEY);

  // use this during development
  // for PUBLISHING, use the entry point below
  //  felgo.setMainQmlFileName(QStringLiteral("qml/Main.qml"));

  // use this instead of the above call to avoid deployment of the qml files and compile them into the binary with qt's resource system qrc
  // this is the preferred deployment option for publishing games to the app stores, because then your qml files and js files are protected
  // to avoid deployment of your qml files and images, also comment the DEPLOYMENTFOLDERS command in the .pro file
  // also see the .pro file for more details


  logic::Director director;
  director.init();

  qmlRegisterUncreatableType<presenter::Model>("rendall", 1, 0, "NodeModel", "can't create presenter::Model");
  qmlRegisterUncreatableType<logic::Node>("rendall", 1, 0, "Node", "can't create Node");
  qmlRegisterType<logic::Account>("rendall", 1, 0, "Account");
  qmlRegisterType<logic::BankCard>("rendall", 1, 0, "BankCard");
  qmlRegisterType<logic::Contact>("rendall", 1, 0, "Contact");
  qmlRegisterType<logic::Folder>("rendall", 1, 0, "Folder");
  qmlRegisterType<logic::File>("rendall", 1, 0, "File");
  qmlRegisterType<logic::Memo>("rendall", 1, 0, "Memo");

  engine.rootContext()->setContextProperty("Director", &director);
  engine.rootContext()->setContextProperty("Presenter", director.presenter());


  felgo.setMainQmlFileName(QStringLiteral("qrc:/qml/Main.qml"));

  engine.load(QUrl(felgo.mainQmlFileName()));

  // to start your project as Live Client, comment (remove) the lines "felgo.setMainQmlFileName ..." & "engine.load ...",
  // and uncomment the line below
  //FelgoLiveClient client (&engine);

  return app.exec();
}
