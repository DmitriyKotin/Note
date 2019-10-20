#include "getshared.h"
#include "logic/node.h"
#include "logic/notejsonerror.h"


namespace command {

  GetShared::GetShared(QObject* parent)
    : Command("get_shared")
    , m_parent(parent)
  {
  }


  QJsonValue GetShared::toJson() const
  {
    return QJsonValue();
  }


  void GetShared::fromJson(const QJsonValue& json)
  {
    Q_UNUSED(json)
  }


  bool GetShared::isDublicate(const Command* const other) const
  {
    const GetShared* command = dynamic_cast<const GetShared*>(other);
    return command != nullptr;
  }

} // namespace command
