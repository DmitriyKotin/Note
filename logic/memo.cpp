#include "memo.h"


namespace logic {

  Memo::Memo(QObject* parent)
    : Node(parent)
  {
  }


  void Memo::valueFromJson(const QJsonObject& json)
  {
    m_comment = json["comment"].toString();
  }


  void Memo::fromOldJson(const QJsonValue& json)
  {
    if (json.isObject()) {
      QJsonObject object = json.toObject();
      m_comment = object["content"].toString();
    }
  }


  QJsonValue Memo::toJson() const
  {
    QJsonObject json;
    json["comment"] = m_comment;
    return json;
  }

} // namespace logic
