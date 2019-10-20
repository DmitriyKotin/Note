#include "bankcard.h"


namespace logic {

  BankCard::BankCard(QObject* parent)
    : Node(parent)
  {
  }


  void BankCard::valueFromJson(const QJsonObject& json)
  {
    m_number = json["number"].toString();
    m_validThru = json["valid_thru"].toString();
    m_holderName = json["holder_name"].toString();
    m_cvc = json["cvc"].toString();
    m_comment = json["comment"].toString();
  }


  void BankCard::fromOldJson(const QJsonValue& json)
  {
    if (json.isObject()) {
      QJsonObject object = json.toObject();

      m_number = object["numberCard"].toString();

      const QString month = object["month"].toString();
      const QString year = object["year"].toString();
      m_validThru = month + year;

      const QString name = object["name"].toString();
      const QString surname = object["surname"].toString();
      m_holderName = name + " " + surname;

      m_cvc = object["cvc"].toString();
      m_comment = object["comment"].toString();
    }
  }


  QJsonValue BankCard::toJson() const
  {
    QJsonObject json;
    json["number"] = m_number;
    json["valid_thru"] = m_validThru;
    json["holder_name"] = m_holderName;
    json["cvc"] = m_cvc;
    json["comment"] = m_comment;
    return json;
  }


  QString BankCard::number() const
  {
    return m_number;
  }

  QString BankCard::validThru() const
  {
    return m_validThru;
  }

  QString BankCard::holderName() const
  {
    return m_holderName;
  }

  QString BankCard::cvc() const
  {
    return m_cvc;
  }


  void BankCard::setNumber(const QString& number)
  {
    if (m_number != number) {
      m_number = number;
      emit numberChanged(m_number);
    }
  }

  void BankCard::setValidThru(const QString& thru)
  {
    if (m_validThru != thru) {
      m_validThru = thru;
      emit validThruChanged(m_validThru);
    }
  }

  void BankCard::setHolderName(const QString& holderName)
  {
    if (m_holderName != holderName) {
      m_holderName = holderName;
      emit holderNameChanged(m_holderName);
    }
  }

  void BankCard::setCvc(const QString& cvc)
  {
    if (m_cvc != cvc) {
      m_cvc = cvc;
      emit cvcChanged(m_cvc);
    }
  }

} // namespace logic
