#pragma once

#include <QObject>
#include "logic/folder.h"
#include "logic/node.h"
#include "model.h"


class Presenter : public QObject
{
  Q_OBJECT

  Q_PROPERTY(QUrl page READ page NOTIFY pageChanged)
  Q_PROPERTY(logic::Node* node READ node NOTIFY nodeChanged)
  Q_PROPERTY(logic::Folder* folder READ folder NOTIFY folderChanged)
  Q_PROPERTY(bool isRoot READ isRoot NOTIFY isRootChanged)

public:
  explicit Presenter(logic::Folder* root, QObject* parent = nullptr);
  ~Presenter() override = default;

public:
  QUrl page() const;
  logic::Node* node() const {return  m_node;}
  logic::Folder* folder() const {return m_folder;}
  bool isRoot() const;

  Q_INVOKABLE presenter::Model* model() {return m_model;}

public slots:
  Q_INVOKABLE void selectNode(logic::Node* node);
  Q_INVOKABLE void closeNode();
  Q_INVOKABLE void selectFolder(logic::Folder* folder);
  Q_INVOKABLE void selectHomeFolder();
  Q_INVOKABLE void selectBackFolder();

  void setNode(logic::Node* node);
  void setFolder(logic::Folder* folder);

signals:
  void pageChanged(const QUrl&);
  void nodeChanged(logic::Node*);
  void folderChanged(logic::Folder*);
  void isRootChanged(const bool);
  void closedNode();

private:
  logic::Folder* m_folder = nullptr;
  logic::Folder* m_root = nullptr;
  logic::Node* m_node = nullptr;

  presenter::Model* m_model;
};
