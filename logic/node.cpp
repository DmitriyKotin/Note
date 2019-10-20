#include "node.h"
#include "notefactory.h"
#include "folder.h"
#include <QDebug>


namespace logic {

  Node::Node(QObject* parent)
    : QObject(parent)
    , m_info(m_key)
  {
  }


  void Node::setValue(const QString& value)
  {
    QByteArray data = m_key.decrypt(value);
    QJsonDocument json = QJsonDocument::fromJson(data);
    if (json.isObject()) {
      valueFromJson(json.object());
      m_isLoaded = true;
    }
    valueChanged();
  }


  QString Node::value() const
  {
    //      if (m_entity == nullptr) {
    //        qDebug() << "null entity from node " << m_name;
    //        return "";
    //      }

    //      QJsonDocument doc(m_entity->toJson().toObject());
    //      const QString value(doc.toJson(QJsonDocument::Compact));
    //      const QString data = m_key.encrypt(value);
    //      return data;
    return "";
  }


  QString Node::fullPath() const
  {
    //      QString path = m_name;
    //      Node* parent = qobject_cast<Node*>(this->parent());

    //      while (parent != nullptr) {
    //        path.push_front("/");
    //        path.push_front(parent->name());
    //        parent = qobject_cast<Node*>(parent->parent());
    //      }
    //      return path;
    return "";
  }


  QString Node::toString() const
  {
    return QString("%1:%2").arg(m_id).arg(name());
  }


  int Node::id() const
  {
    return m_id;
  }

  QString Node::name() const
  {
    return m_info.name();
  }


  db_ptr<Folder> Node::folder() const
  {
    return m_folder;
  }

  int Node::user() const
  {
    return m_user;
  }

  int Node::version() const
  {
    return m_version;
  }

  QString Node::comment() const
  {
    return m_comment;
  }


  void Node::setId(const int id)
  {
    if (m_id != id) {
      m_id = id;
    }
  }

  void Node::setName(const QString& name)
  {
    if (m_info.name() != name) {
      m_info.setName(name);
      emit nameChanged(m_info.name());
    }
  }

  void Node::setUser(const int user)
  {
    if (m_user != user) {
      m_user = user;
      emit userChanged(m_user);
    }
  }

  void Node::setVersion(const int version)
  {
    if (m_version != version) {
      m_version = version;
      emit versionChanged(m_version);
    }
  }

  void Node::setComment(const QString& comment)
  {
    if (m_comment != comment) {
      m_comment = comment;
      emit commentChanged(m_comment);
    }
  }


  void Node::setFolder(const int id)
  {
    m_folder = id;
  }

  void Node::setFolder(Folder* folder)
  {
    m_folder = folder;
  }

} // namespace logic
