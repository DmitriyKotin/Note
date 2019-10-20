# allows to add DEPLOYMENTFOLDERS and links to the Felgo library and QtCreator auto-completion
CONFIG += felgo
CONFIG += c++14

QT += quick
QT += qml
QT += websockets


# uncomment this line to add the Live Client Module and use live reloading with your custom C++ code
# for the remaining steps to build a custom Live Code Reload app see here: https://felgo.com/custom-code-reload-app/
# CONFIG += felgo-live

# Project identifier and version
# More information: https://felgo.com/doc/felgo-publishing/#project-configuration
PRODUCT_IDENTIFIER = com.yourcompany.wizardEVAP.Note
PRODUCT_VERSION_NAME = 1.0.0
PRODUCT_VERSION_CODE = 1

# Optionally set a license key that is used instead of the license key from
# main.qml file (App::licenseKey for your app or GameWindow::licenseKey for your game)
# Only used for local builds and Felgo Cloud Builds (https://felgo.com/cloud-builds)
# Not used if using Felgo Live
PRODUCT_LICENSE_KEY = ""

#qmlFolder.source = qml
#DEPLOYMENTFOLDERS += qmlFolder # comment for publishing

assetsFolder.source = assets
DEPLOYMENTFOLDERS += assetsFolder

# Add more folders to ship with the application here

RESOURCES += \ #    resources.qrc # uncomment for publishing
    main.qrc

# NOTE: for PUBLISHING, perform the following steps:
# 1. comment the DEPLOYMENTFOLDERS += qmlFolder line above, to avoid shipping your qml files with the application (instead they get compiled to the app binary)
# 2. uncomment the resources.qrc file inclusion and add any qml subfolders to the .qrc file; this compiles your qml files and js files to the app binary and protects your source code
# 3. change the setMainQmlFile() call in main.cpp to the one starting with "qrc:/" - this loads the qml files from the resources
# for more details see the "Deployment Guides" in the Felgo Documentation

# during development, use the qmlFolder deployment because you then get shorter compilation times (the qml files do not need to be compiled to the binary but are just copied)
# also, for quickest deployment on Desktop disable the "Shadow Build" option in Projects/Builds - you can then select "Run Without Deployment" from the Build menu in Qt Creator if you only changed QML files; this speeds up application start, because your app is not copied & re-compiled but just re-interpreted



#RESOURCES += \
#  qml/qml.qrc

## Additional import path used to resolve QML modules in Qt Creator's code model
#QML_IMPORT_PATH += \
#  $$PWD \
#  $$PWD/qml


## Additional import path used to resolve QML modules just for Qt Quick Designer
#QML_DESIGNER_IMPORT_PATH += \
#  $$PWD \
#  $$PWD/qml



# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp \
    core/command.cpp \
    core/commandpool.cpp \
    core/error.cpp \
    core/errorlist.cpp \
    core/webclient.cpp \
    core/webconnection.cpp \
    core/websocket.cpp \
    logic/account.cpp \
    logic/bankcard.cpp \
    logic/contact.cpp \
    logic/displayinfo.cpp \
    logic/file.cpp \
    logic/folder.cpp \
    logic/memo.cpp \
    logic/node.cpp \
    logic/nodekey.cpp \
    logic/nodelist.cpp \
    logic/nodetype.cpp \
    logic/notedirector.cpp \
    logic/notefactory.cpp \
    logic/notejsonconvertor.cpp \
    logic/notejsonerror.cpp \
    logic/notestorage.cpp \
    command/addnote.cpp \
    command/deleteallnodes.cpp \
    command/deletenote.cpp \
    command/getgroupkey.cpp \
    command/getnodetree.cpp \
    command/getnodevalue.cpp \
    command/getshared.cpp \
    command/login.cpp \
    command/logout.cpp \
    command/oldgetnode.cpp \
    command/renamenode.cpp \
    command/savenote.cpp \
    command/sharenote.cpp \
    command/updatedisplayinfo.cpp \
    presenter/model.cpp \
    presenter/presenter.cpp \
    main_old.cpp


android {
    ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
    OTHER_FILES += android/AndroidManifest.xml       android/build.gradle
}

ios {
    QMAKE_INFO_PLIST = ios/Project-Info.plist
    OTHER_FILES += $$QMAKE_INFO_PLIST
}

# set application icons for win and macx
win32 {
    RC_FILE += win/app_icon.rc
}
macx {
    ICON = macx/app_icon.icns
}

HEADERS += \
    common/db_ptr.h \
    common/ijsonble.h \
    common/itemlist.h \
    core/command.h \
    core/commandpool.h \
    core/error.h \
    core/errorlist.h \
    core/webclient.h \
    core/webconnection.h \
    core/websocket.h \
    logic/account.h \
    logic/bankcard.h \
    logic/contact.h \
    logic/displayinfo.h \
    logic/file.h \
    logic/folder.h \
    logic/memo.h \
    logic/node.h \
    logic/nodekey.h \
    logic/nodelist.h \
    logic/nodetype.h \
    logic/notedirector.h \
    logic/notefactory.h \
    logic/notejsonconvertor.h \
    logic/notejsonerror.h \
    logic/notestorage.h \
    command/addnote.h \
    command/deleteallnodes.h \
    command/deletenote.h \
    command/getgroupkey.h \
    command/getnodetree.h \
    command/getnodevalue.h \
    command/getshared.h \
    command/login.h \
    command/logout.h \
    command/oldgetnode.h \
    command/renamenode.h \
    command/savenote.h \
    command/sharenote.h \
    command/updatedisplayinfo.h \
    presenter/model.h \
    presenter/presenter.h

DISTFILES +=
