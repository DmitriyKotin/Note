#include "folder.h"


namespace logic {

  Folder::Folder(QObject* parent)
    : Node(parent)
  {
  }


  void Folder::valueFromJson(const QJsonObject& json)
  {
    Q_UNUSED(json)
  }


  void Folder::fromOldJson(const QJsonValue& json)
  {
    if (json.isObject()) {
      QJsonObject object = json.toObject();

      m_key = object["key"].toString();
    }
  }


  QJsonValue Folder::toJson() const
  {
    return QJsonValue();
  }


  void Folder::clear()
  {
    m_children.clear();
  }


  int Folder::count() const
  {
    return m_children.count();
  }


  Node* Folder::value(const int index) const
  {
    return m_children.value(index);
  }


  int Folder::indexOf(Node* node) const
  {
    return m_children.indexOf(node);
  }


  bool Folder::exist(const Node* node) const
  {
    return m_children.exist(node);
  }


  void Folder::append(Node* node)
  {
    m_children.append(node);
  }


  void Folder::remove(Node* node)
  {
    m_children.remove(node);
  }


  QString Folder::key() const
  {
    return m_key;
  }


  void Folder::setKey(const QString& key)
  {
    if (m_key != key) {
      m_key = key;
      emit keyChanged(m_key);
    }
  }

} // namespace logic
