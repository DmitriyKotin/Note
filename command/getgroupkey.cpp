#include "getgroupkey.h"
#include "QJsonObject"


namespace command {

  GetGroupKey::GetGroupKey()
    : Command("getGroupKey")
  {
  }


  QJsonValue GetGroupKey::toJson() const
  {
    QJsonObject json;
    json["user_id"] = 1;
    return json;
  }


  void GetGroupKey::fromJson(const QJsonValue& json)
  {
    Q_UNUSED(json)
  }


  bool GetGroupKey::isDublicate(const Command* const other) const
  {
    const GetGroupKey* command = dynamic_cast<const GetGroupKey*>(other);
    return command != nullptr;
  }

} // namespace command
