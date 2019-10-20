#include "logout.h"


namespace command {

  Logout::Logout()
    : Command("logout")
  {
  }


  QJsonValue Logout::toJson() const
  {
    return QJsonValue();
  }


  void Logout::fromJson(const QJsonValue& json)
  {
    Q_UNUSED(json)
  }


  bool Logout::isDublicate(const Command* const other) const
  {
    const Logout* command = dynamic_cast<const Logout*>(other);
    return command != nullptr;
  }

} // namespace command
