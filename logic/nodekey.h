#pragma once

#include <QByteArray>
#include <QJsonObject>


namespace logic {

  // NOTE: Упорядочить работу с кодировками. Правильно выставить toUtf8 и toLatin (для base64 нужен именно toLatin)
  class Key
  {
  public:
    Key();
    explicit Key(const QJsonObject& json);
    ~Key() = default;

  public:
    void fromJson(const QJsonObject& json);
    void toJson(QJsonObject& json) const;

    QByteArray decrypt(const QString& data) const;
    QString encrypt(const QString& data) const;

    bool isEmpty() const;
    void generate();

  private:
    int m_version = -1;
    QByteArray m_key;

    static const int key_size = 32;
  };

} // namespace logic
