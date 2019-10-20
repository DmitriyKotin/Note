#pragma once

#include "node.h"


namespace logic {

  class Contact : public Node
  {
    Q_OBJECT

    Q_PROPERTY(QString firstName READ firstName WRITE setFirstName NOTIFY firstNameChanged)
    Q_PROPERTY(QString secondName READ secondName WRITE setSecondName NOTIFY secondNameChanged)
    Q_PROPERTY(QString companyName READ companyName WRITE setCompanyName NOTIFY companyNameChanged)
    Q_PROPERTY(QString phoneNumber READ phoneNumber WRITE setPhoneNumber NOTIFY phoneNumberChanged)
    Q_PROPERTY(QString email READ email WRITE setEmail NOTIFY emailChanged)
    Q_PROPERTY(QString address READ address WRITE setAddress NOTIFY addressChanged)

  public:
    explicit Contact(QObject* parent = nullptr);
    ~Contact() override = default;

  public:
    Q_INVOKABLE bool isFolder() const override {return false;}

    //      void fromJson(const QJsonValue& json);
    void fromOldJson(const QJsonValue& json);
    QJsonValue toJson() const;

  public:
    QString firstName() const;
    QString secondName() const;
    QString companyName() const;
    QString phoneNumber() const;
    QString email() const;
    QString address() const;

    void setFirstName(const QString& firstName);
    void setSecondName(const QString& secondName);
    void setCompanyName(const QString& company);
    void setPhoneNumber(const QString& phoneNumber);
    void setEmail(const QString& email);
    void setAddress(const QString& address);

  signals:
    void firstNameChanged(const QString&);
    void secondNameChanged(const QString&);
    void companyNameChanged(const QString&);
    void phoneNumberChanged(const QString&);
    void emailChanged(const QString&);
    void addressChanged(const QString&);

  public:
    QUrl qmlPage() const override {return QUrl("qrc:/qml/ContactPage.qml");}
    QUrl smallIcon() const override {return QUrl("qrc:/qml/image/contact_small.png");}
    QUrl bigIcon() const override {return QUrl("qrc:/qml/image/contact_big.png");}

  private:
    void valueFromJson(const QJsonObject& json) override;

  private:
    QString m_firstName;
    QString m_secondName;
    QString m_companyName;
    QString m_phoneNumber;
    QString m_email;
    QString m_address;
  };

} // namespace logic
