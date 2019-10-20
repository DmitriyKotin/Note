#pragma once

#include <QObject>
#include "nodelist.h"
#include "node.h"
#include "folder.h"
#include "presenter/presenter.h"
#include "notestorage.h"


namespace logic {

  class Director : public QObject
  {
    Q_OBJECT

  public:
    explicit Director(QObject* parent = nullptr);
    ~Director() override = default;

  public:
    void init();

  public:
    Q_INVOKABLE void getTree();
    Q_INVOKABLE void getValue(Node* node);

    Q_INVOKABLE void addNote(Node* note, Folder* folder);
    Q_INVOKABLE void deleteNote(Node* note, Folder* folder);
    Q_INVOKABLE void saveNote(Node* note);
    Q_INVOKABLE void updateDisplayInfo(Node* note);
    Q_INVOKABLE void renameNote(Node* node, const QString& name);

    Q_INVOKABLE void getShared();
    Q_INVOKABLE void shareNote(Node* note);

  public:
    Q_INVOKABLE bool canCreateNode(const QString& name);
    Q_INVOKABLE bool canRenameNode(const QString& name);

  public:
    Presenter* presenter();

  signals:
    // NOTE: message тут нужен, для использования его на стороне QML
    void okMessage(const QString& message);
    void errorMessage(const QString& message);

  private:
    Storage m_storage;
    Presenter m_presenter;
  };

} // namespace logic
