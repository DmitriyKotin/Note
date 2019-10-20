#include "account.h"


namespace logic {

  Account::Account(QObject* parent)
    : Node(parent)
  {
  }


  void Account::valueFromJson(const QJsonObject& json)
  {
    m_login = json["login"].toString();
    m_password = json["password"].toString();
    m_email = json["email"].toString();
    m_uri = json["uri"].toString();
    m_comment = json["comment"].toString();
  }


  //    void Account::fromJson(const QJsonValue& json)
  //    {
  //      if (json.isObject()) {
  //        QJsonObject object = json.toObject();

  //        m_login = object["login"].toString();
  //        m_password = object["password"].toString();
  //        m_email = object["email"].toString();
  //        m_uri = object["uri"].toString();
  //        m_comment = object["comment"].toString();
  //      }
  //    }


  void Account::fromOldJson(const QJsonValue& json)
  {
    if (json.isObject()) {
      QJsonObject object = json.toObject();

      m_login = object["logic"].toString();
      m_password  = object["password"].toString();
      m_email = object["email"].toString();
      m_uri = object["uri"].toString();
      m_comment = object["comment"].toString();
    }
  }


  QJsonValue Account::toJson() const
  {
    QJsonObject json;
    json["login"] = m_login;
    json["password"] = m_password;
    json["email"] = m_email;
    json["uri"] = m_uri;
    json["comment"] = m_comment;
    return json;
  }


  QString Account::login() const
  {
    return m_login;
  }

  QString Account::password() const
  {
    return m_password;
  }

  QString Account::email() const
  {
    return m_email;
  }

  QString Account::uri() const
  {
    return m_uri;
  }


  void Account::setLogin(const QString& login)
  {
    if (m_login != login) {
      m_login = login;
      emit loginChanged(m_login);
    }
  }

  void Account::setPassword(const QString& password)
  {
    if (m_password != password) {
      m_password = password;
      emit passwordChanged(m_password);
    }
  }

  void Account::setEmail(const QString& email)
  {
    if (m_email != email) {
      m_email = email;
      emit emailChanged(m_email);
    }
  }

  void Account::setUri(const QString& uri)
  {
    if (m_uri != uri) {
      m_uri = uri;
      emit uriChanged(m_uri);
    }
  }

} // namespace logic
