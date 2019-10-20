#pragma once

#include "core/command.h"
#include <QString>
#include <QByteArray>


namespace command {

  class Login : public Command
  {
  public:
    explicit Login(const QString& login, const QString& password);

  public:
    QJsonValue toJson() const override;
    void fromJson(const QJsonValue& json) override;

  public:
    bool checkDublicate() const override {return true;}
    bool isDublicate(const Command* const other) const override;

  public:
    QByteArray key() const {return m_key;}

  private:
    QString m_login;
    QString m_password;

    QByteArray m_key;
  };

} // namespace command
