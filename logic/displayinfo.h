#pragma once

#include "common/ijsonble.h"
#include "nodetype.h"
#include <QString>
#include <QDateTime>
#include <QList>
#include "nodekey.h"
#include <QJsonValue>


namespace logic {

  class DisplayInfo : public IJsonble
  {
  public:
    enum Type {
      Unknow = -1,
      Folder = 0,
      Memo = 1,
      Account = 2,
      Contact = 3,
      BankCard = 4,
      File = 5,
    };

  public:
    explicit DisplayInfo(const Key& key);
    explicit DisplayInfo(const QJsonValue& json, const Key& key);

    DisplayInfo(DisplayInfo&& other);
    DisplayInfo& operator=(DisplayInfo&& other);

  public:
    void fromJson(const QJsonValue& json) override;
    QJsonValue toJson() const override;

  public:
    Type type() const {return m_type;}
    QString name() const {return m_name;}
    QDateTime createTime() const {return m_createTime;}
    QDateTime changeTime() const {return m_changeTime;}
    int version() const {return m_version;}

  public:
    void setName(const QString& name);

  private:
    Type m_type;
    QString m_name;
    QDateTime m_createTime;
    QDateTime m_changeTime;
    QList<QString> m_tag;
    int m_version = 2;

    const Key& m_key;
  };

} // namespace logic
