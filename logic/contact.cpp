#include "contact.h"


namespace logic {

  Contact::Contact(QObject* parent)
    : Node(parent)
  {
  }


  void Contact::valueFromJson(const QJsonObject& json)
  {
    m_firstName = json["first_name"].toString();
    m_secondName = json["second_name"].toString();
    m_companyName = json["company_name"].toString();
    m_phoneNumber = json["phone_name"].toString();
    m_email = json["email"].toString();
    m_address = json["address"].toString();
    m_comment = json["comment"].toString();
  }


  void Contact::fromOldJson(const QJsonValue& json)
  {
    if (json.isObject()) {
      QJsonObject object = json.toObject();

      m_firstName = object["name"].toString();
      m_secondName = object["second_name"].toString();
      m_companyName = object["company"].toString();
      m_phoneNumber = object["number"].toString();
      m_email = object["email"].toString();
      m_address = object["address"].toString();
      m_comment = object["comment"].toString();
    }
  }


  QJsonValue Contact::toJson() const
  {
    QJsonObject json;
    json["first_name"] = m_firstName;
    json["second_name"] = m_secondName;
    json["company_name"] = m_companyName;
    json["phone_name"] = m_phoneNumber;
    json["email"] = m_email;
    json["address"] = m_address;
    json["comment"] = m_comment;
    return json;
  }


  QString Contact::firstName() const
  {
    return m_firstName;
  }

  QString Contact::secondName() const
  {
    return m_secondName;
  }

  QString Contact::companyName() const
  {
    return m_companyName;
  }

  QString Contact::phoneNumber() const
  {
    return m_phoneNumber;
  }

  QString Contact::email() const
  {
    return m_email;
  }

  QString Contact::address() const
  {
    return m_address;
  }


  void Contact::setFirstName(const QString& firstName)
  {
    if (m_firstName != firstName) {
      m_firstName = firstName;
      emit firstNameChanged(m_firstName);
    }
  }

  void Contact::setSecondName(const QString& secondName)
  {
    if (m_secondName != secondName) {
      m_secondName = secondName;
      emit secondNameChanged(m_secondName);
    }
  }

  void Contact::setCompanyName(const QString& company)
  {
    if (m_companyName != company) {
      m_companyName = company;
      emit companyNameChanged(m_companyName);
    }
  }

  void Contact::setPhoneNumber(const QString& phoneNumber)
  {
    if (m_phoneNumber != phoneNumber) {
      m_phoneNumber = phoneNumber;
      emit phoneNumberChanged(m_phoneNumber);
    }
  }

  void Contact::setEmail(const QString& email)
  {
    if (m_email != email) {
      m_email = email;
      emit emailChanged(m_email);
    }
  }

  void Contact::setAddress(const QString& address)
  {
    if (m_address != address) {
      m_address = address;
      emit addressChanged(m_address);
    }
  }

} // namespace logic
