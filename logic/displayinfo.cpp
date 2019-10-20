#include "displayinfo.h"
#include <QJsonDocument>
#include <QtGlobal>
#include <QDebug>


namespace logic {

  DisplayInfo::DisplayInfo(const Key& key)
    : m_key(key)
  {
  }

  DisplayInfo::DisplayInfo(const QJsonValue& json, const Key& key)
    : m_key(key)
  {
    fromJson(json);
  }


  DisplayInfo::DisplayInfo(DisplayInfo&& other)
    : m_key(other.m_key)
  {
    std::swap(m_type, other.m_type);
    std::swap(m_name, other.m_name);
    std::swap(m_createTime, other.m_createTime);
    std::swap(m_changeTime, other.m_changeTime);
    std::swap(m_tag, other.m_tag);
    std::swap(m_version, other.m_version);
  }


  DisplayInfo& DisplayInfo::operator=(DisplayInfo&& other)
  {
    if (this != &other) {
      std::swap(m_type, other.m_type);
      std::swap(m_name, other.m_name);
      std::swap(m_createTime, other.m_createTime);
      std::swap(m_changeTime, other.m_changeTime);
      std::swap(m_tag, other.m_tag);
      std::swap(m_version, other.m_version);
    }
    return *this;
  }


  void DisplayInfo::fromJson(const QJsonValue& json)
  {
    const QString info = json.toString();
    QByteArray data = m_key.decrypt(info);
    QJsonDocument document = QJsonDocument::fromJson(data);

    if (document.isObject()) {
      QJsonObject object = document.object();
      m_name = object["title"].toString();

      int type = object["type"].toInt(-1);
      if (type >= Folder && type <= File)
        m_type = static_cast<Type>(type);
    }
  }


  QJsonValue DisplayInfo::toJson() const
  {
    QJsonObject object;
    object["title"] = m_name;
    object["type"] = m_type;

    QJsonDocument doc(object);
    const QString value(doc.toJson(QJsonDocument::Compact));
    const QString info = m_key.encrypt(value);
    return info;
  }


  void DisplayInfo::setName(const QString& name)
  {
    m_name = name;
  }

} // namespace logic
