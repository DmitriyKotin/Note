#pragma once

#include "node.h"


namespace logic {

  class BankCard : public Node
  {
    Q_OBJECT

    Q_PROPERTY(QString number READ number WRITE setNumber NOTIFY numberChanged)
    Q_PROPERTY(QString validThru READ validThru WRITE setValidThru NOTIFY validThruChanged)
    Q_PROPERTY(QString holderName READ holderName WRITE setHolderName NOTIFY holderNameChanged)
    Q_PROPERTY(QString cvc READ cvc WRITE setCvc NOTIFY cvcChanged)

  public:
    explicit BankCard(QObject* parent = nullptr);
    ~BankCard() override = default;

  public:
    Q_INVOKABLE bool isFolder() const override {return false;}

    //      void fromJson(const QJsonValue& json);
    void fromOldJson(const QJsonValue& json);
    QJsonValue toJson() const;

  public:
    QString number() const;
    QString validThru() const;
    QString holderName() const;
    QString cvc() const;

    void setNumber(const QString& number);
    void setValidThru(const QString& thru);
    void setHolderName(const QString& holderName);
    void setCvc(const QString& cvc);

  signals:
    void numberChanged(const QString&);
    void validThruChanged(const QString&);
    void holderNameChanged(const QString&);
    void cvcChanged(const QString&);

  public:
    QUrl qmlPage() const override {return QUrl("qrc:/qml/BankCardPage.qml");}
    QUrl smallIcon() const override {return QUrl("qrc:/qml/image/bankcard_small.png");}
    QUrl bigIcon() const override {return QUrl("qrc:/qml/image/bankcard_big.png");}

  private:
    void valueFromJson(const QJsonObject& json) override;

  private:
    QString m_number;
    QString m_validThru;
    QString m_holderName;
    QString m_cvc;
  };

} // namespace logic
