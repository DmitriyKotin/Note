#include "notedirector.h"
#include "command/addnote.h"
#include "command/deletenote.h"
#include "command/getnodetree.h"
#include "command/getnodevalue.h"
#include "command/getshared.h"
#include "command/savenote.h"
#include "command/sharenote.h"
#include "command/updatedisplayinfo.h"
#include "command/renamenode.h"
#include "notefactory.h"
#include <QDebug>


namespace logic {

  Director::Director(QObject* parent)
    : QObject(parent)
    , m_presenter(m_storage.root())
  {

    connect(&m_storage, &Storage::beginAppend, m_presenter.model(), &presenter::Model::beginAppend);
    connect(&m_storage, &Storage::endAppend, m_presenter.model(), &presenter::Model::endAppend);


  }


  void Director::init()
  {
    m_storage.clear();
    m_storage.createFakeData();

    m_presenter.selectHomeFolder();

//    m_nodeModel->select(m_storage.root());
//    CS_Crypt::getInstance()->getGroupKey(ContactList::myUser(), [this](){getTree();});
  }


  void Director::getTree()
  {
    qDebug() << "get tree";

//    CommandBuilder<command::note::GetNodeTree>(this)
//        .onSucceeded([this](NodeList nodes) {
//      m_storage.setList(nodes);
//      m_nodeModel->select(m_storage.root());
//    })
//    .onFailed([this](ResponseError, const QString& message){
//      emit errorMessage(message);
//    })
//    .onTimeout([this]() {
//      emit errorMessage(tr("Сервер не отвечает"));
//    })
//        .onRejected([this]() {
//      emit errorMessage(tr("Запрос уже выполняется"));
//    })
//        .onDone([](bool){})
//        .build()
//        .execute();
  }


  void Director::getValue(Node* node)
  {
    qDebug() << "get value";

//    CommandBuilder<command::note::GetNodeValue>(node)
//        .onSucceeded([this](Node* node) {
//      m_nodeModel->change(node);
//      Folder* folder = qobject_cast<Folder*>(node);
//      if (folder != nullptr)
//        m_nodeModel->select(folder);
//    })
//    .onFailed([this](ResponseError, const QString& message){
//      emit errorMessage(message);
//    })
//    .onTimeout([this]() {
//      emit errorMessage(tr("Сервер не отвечает"));
//    })
//        .onRejected([this]() {
//      emit errorMessage(tr("Запрос уже выполняется"));
//    })
//        .onDone([](bool){})
//        .build()
//        .execute();
  }


  void Director::addNote(Node* node, Folder* folder)
  {
    qDebug() << "add note";
    m_storage.append(node, folder);

//    CommandBuilder<command::note::AddNote>(node)
//        .onSucceeded([this, folder](Node* node) {
//      m_storage.append(node, folder);
//    })
//        .onFailed([this](ResponseError, const QString& message){
//      emit errorMessage(message);
//    })
//    .onTimeout([this]() {
//      emit errorMessage(tr("Сервер не отвечает"));
//    })
//        .onRejected([this]() {
//      emit errorMessage(tr("Запрос уже выполняется"));
//    })
//        .onDone([](bool){})
//        .build()
//        .execute();
  }


  void Director::deleteNote(Node* node, Folder* folder)
  {
    qDebug() << "delete note";

//    CommandBuilder<command::note::DeleteNote>(node)
//        .onSucceeded([this, folder](Node* node) {
//      m_storage.remove(node, folder);
//    })
//        .onFailed([this](ResponseError, const QString& message){
//      emit errorMessage(message);
//    })
//    .onTimeout([this]() {
//      emit errorMessage(tr("Сервер не отвечает"));
//    })
//        .onRejected([this]() {
//      emit errorMessage(tr("Запрос уже выполняется"));
//    })
//        .onDone([](bool){})
//        .build()
//        .execute();
  }


  void Director::saveNote(Node* node)
  {
    qDebug() << "save note";

//    CommandBuilder<command::note::SaveNote>(node)
//        .onSucceeded([this](Node* node) {
//      m_nodeModel->change(node);
//    })
//    .onFailed([this](ResponseError, const QString& message){
//      emit errorMessage(message);
//    })
//    .onTimeout([this]() {
//      emit errorMessage(tr("Сервер не отвечает"));
//    })
//        .onRejected([this]() {
//      emit errorMessage(tr("Запрос уже выполняется"));
//    })
//        .onDone([](bool){})
//        .build()
//        .execute();
  }


  void Director::updateDisplayInfo(Node* node)
  {
    qDebug() << "update";

//    CommandBuilder<command::note::UpdateDisplayInfo>(node)
//        .onSucceeded([this](Node* node) {
//      m_nodeModel->change(node);
//    })
//    .onFailed([this](ResponseError, const QString& message){
//      emit errorMessage(message);
//    })
//    .onTimeout([this]() {
//      emit errorMessage(tr("Сервер не отвечает"));
//    })
//        .onRejected([this]() {
//      emit errorMessage(tr("Запрос уже выполняется"));
//    })
//        .onDone([](bool){})
//        .build()
//        .execute();
  }


  void Director::renameNote(Node* node, const QString& name)
  {
    qDebug() << "rename note";

//    CommandBuilder<command::note::RenameNote>(node, name)
//        .onSucceeded([this](Node* node) {
//      m_nodeModel->change(node);
//    })
//    .onFailed([this](ResponseError, const QString& message){
//      emit errorMessage(message);
//    })
//    .onTimeout([this]() {
//      emit errorMessage(tr("Сервер не отвечает"));
//    })
//        .onRejected([this]() {
//      emit errorMessage(tr("Запрос уже выполняется"));
//    })
//        .onDone([](bool){})
//        .build()
//        .execute();
  }



  void Director::getShared()
  {
//    CommandBuilder<command::note::GetShared>(this)
//        .onSucceeded([this](NodeList nodes) {
//      Q_UNUSED(nodes)
//    })
//    .onFailed([this](ResponseError, const QString& message){
//      emit errorMessage(message);
//    })
//    .onTimeout([this]() {
//      emit errorMessage(tr("Сервер не отвечает"));
//    })
//        .onRejected([this]() {
//      emit errorMessage(tr("Запрос уже выполняется"));
//    })
//        .onDone([](bool){})
//        .build()
//        .execute();
  }


  void Director::shareNote(Node* node)
  {
//    CommandBuilder<command::note::ShareNote>(node)
//        .onSucceeded([this](Node* node) {
//      Q_UNUSED(node)
//    })
//    .onFailed([this](ResponseError, const QString& message){
//      emit errorMessage(message);
//    })
//    .onTimeout([this]() {
//      emit errorMessage(tr("Сервер не отвечает"));
//    })
//        .onRejected([this]() {
//      emit errorMessage(tr("Запрос уже выполняется"));
//    })
//        .onDone([](bool){})
//        .build()
//        .execute();
  }


  bool Director::canCreateNode(const QString& name)
  {
    Q_UNUSED(name)

    //      if (name.isEmpty())
    //        return false;

    //      Node* parent = currentFolder();
    //      if (parent == nullptr)
    //        return false;
    //      return parent->children().find(name) == nullptr;

    return false;
  }


  bool Director::canRenameNode(const QString& name)
  {
    Q_UNUSED(name)

    //      if (name.isEmpty())
    //        return false;

    //      Node* parent = currentFolder();
    //      if (parent == nullptr)
    //        return false;
    //      return parent->children().find(name) == nullptr;

    return false;
  }


  Presenter* Director::presenter()
  {
    return &m_presenter;
  }

} // namespace logic
