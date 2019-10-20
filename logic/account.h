#pragma once

#include "node.h"


namespace logic {

  class Account : public Node
  {
    Q_OBJECT

    Q_PROPERTY(QString login READ login WRITE setLogin NOTIFY loginChanged)
    Q_PROPERTY(QString password READ password WRITE setPassword NOTIFY passwordChanged)
    Q_PROPERTY(QString email READ email WRITE setEmail NOTIFY emailChanged)
    Q_PROPERTY(QString uri READ uri WRITE setUri NOTIFY uriChanged)

  public:
    explicit Account(QObject* parent = nullptr);
    ~Account() override = default;

  public:
    Q_INVOKABLE bool isFolder() const override {return false;}

    //      void fromJson(const QJsonValue& json);
    void fromOldJson(const QJsonValue& json);
    QJsonValue toJson() const;

  public:
    QString login() const;
    QString password() const;
    QString email() const;
    QString uri() const;

  public slots:
    void setLogin(const QString& login);
    void setPassword(const QString& password);
    void setEmail(const QString& email);
    void setUri(const QString& uri);

  signals:
    void loginChanged(const QString&);
    void passwordChanged(const QString&);
    void emailChanged(const QString&);
    void uriChanged(const QString&);

  public:    
    QUrl qmlPage() const override {return QUrl("qrc:/qml/AccountPage.qml");}
    QUrl smallIcon() const override {return QUrl("qrc:/qml/image/account_small.png");}
    QUrl bigIcon() const override {return QUrl("qrc:/qml/image/account_big.png");}

  private:
    void valueFromJson(const QJsonObject& json) override;

  private:
    QString m_login;
    QString m_password;
    QString m_email;
    QString m_uri;
  };

} // namespace logic
