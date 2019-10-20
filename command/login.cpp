#include "login.h"
#include <QJsonObject>


namespace command {

  Login::Login(const QString& login, const QString& password)
    : Command("login")
    , m_login(login)
    , m_password(password)
  {
  }


  QJsonValue Login::toJson() const
  {
    QJsonObject json;
    json["login"] = m_login;
    json["password"] = m_password;
    return json;
  }


  void Login::fromJson(const QJsonValue& json)
  {
    Q_UNUSED(json)
  }


  bool Login::isDublicate(const Command* const other) const
  {
    const Login* command = dynamic_cast<const Login*>(other);
    return command != nullptr;
  }

} // namespace command
