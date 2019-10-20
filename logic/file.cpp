#include "file.h"


namespace logic {

  File::File(QObject* parent)
    : Node(parent)
  {
  }


  void File::valueFromJson(const QJsonObject& json)
  {
    m_name = json["file_name"].toString();
    m_key = json["file_path_key"].toString();
    m_comment = json["comment"].toString();
  }


  void File::fromOldJson(const QJsonValue& json)
  {
    Q_UNUSED(json)
  }


  QJsonValue File::toJson() const
  {
    QJsonObject json;
    json["file_name"] = m_name;
    json["file_path_key"] = m_key;
    json["comment"] = m_comment;
    return json;
  }


  QString File::name() const
  {
    return m_name;
  }


  QString File::key() const
  {
    return m_key;
  }


  void File::setName(const QString& name)
  {
    if (m_name != name) {
      m_name = name;
      emit nameChanged(m_name);
    }
  }

  void File::setKey(const QString& key)
  {
    if (m_key != key) {
      m_key = key;
      emit keyChanged(m_key);
    }
  }

} // namespace logic
