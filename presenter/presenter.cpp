#include "presenter.h"
#include <QDebug>


Presenter::Presenter(logic::Folder* root, QObject* parent)
  : QObject(parent)
  , m_root(root)
{
  m_model = new presenter::Model(m_root, this);
}


QUrl Presenter::page() const
{
  if (m_node)
    return m_node->qmlPage();
  return QUrl();
}


bool Presenter::isRoot() const
{
  if (m_root == nullptr || m_folder == nullptr)
    return true;
  return m_root->id() == m_folder->id();
}


void Presenter::selectNode(logic::Node* node)
{
  logic::Folder* folder = qobject_cast<logic::Folder*>(node);

  if (folder != nullptr) {
    setNode(nullptr);
    selectFolder(folder);
  }
  else {
    setNode(node);
  }
}


void Presenter::closeNode()
{
  emit closedNode();
  setNode(nullptr);
}


void Presenter::selectFolder(logic::Folder* folder)
{
  m_model->select(folder);
  setFolder(folder);
  setNode(nullptr);
}


void Presenter::selectHomeFolder()
{
  selectFolder(m_root);
}


void Presenter::selectBackFolder()
{
  if (m_folder && !m_folder->folder().isNull())
    selectFolder(m_folder->folder());
}


void Presenter::setNode(logic::Node* node)
{
  if (m_node != node) {
    m_node = node;
    emit pageChanged(page());
    emit nodeChanged(m_node);
  }
}


void Presenter::setFolder(logic::Folder* folder)
{
  if (m_folder != folder) {
    m_folder = folder;
    emit folderChanged(m_folder);
    emit isRootChanged(isRoot());
  }
}
