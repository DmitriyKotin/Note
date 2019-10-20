#include "nodekey.h"
#include "notejsonerror.h"
//#include <cs_crypt.h>
//#include <contactlist.h>


namespace logic {

  Key::Key()
  {
    generate();
  }


  Key::Key(const QJsonObject& json)
  {
    fromJson(json);
  }


  void Key::fromJson(const QJsonObject& json)
  {
    if (!json.contains("key"))
      throw logic::JsonError("not find key key");
    if (!json.contains("key_version"))
      throw logic::JsonError("not find key key_version");

    QString key = json["key"].toString();
    m_version = json["key_version"].toInt();

//    QByteArray favoriteKey = ContactList::getInstance()->myUser()->groupKey(m_version);
//    m_key = CS_Crypt::getInstance()->decrypt(QByteArray::fromBase64(key.toUtf8()), favoriteKey);
  }


  void Key::toJson(QJsonObject& json) const
  {
//    QByteArray favoriteKey = ContactList::getInstance()->myUser()->groupKey(m_version);
//    const QString key =  CS_Crypt::getInstance()->encrypt(m_key, favoriteKey).toBase64();

//    json["key"] = key;
//    json["key_version"] = m_version;
  }


  QByteArray Key::decrypt(const QString& data) const
  {
//    return CS_Crypt::getInstance()->decrypt(QByteArray::fromBase64(data.toUtf8()), m_key);

    return QByteArray();
  }


  QString Key::encrypt(const QString& data) const
  {
//    return CS_Crypt::getInstance()->encrypt(data.toUtf8(), m_key).toBase64();
    return "";
  }


  bool Key::isEmpty() const
  {
    return m_key.isEmpty();
  }

  void Key::generate()
  {
    m_version = 0;
//    m_key = CS_Crypt::getInstance()->generateKey(key_size);
  }

} // namespace logic
