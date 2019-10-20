#pragma once

#include "common/ijsonble.h"
#include <QUrl>


namespace logic {

  class Type : public IJsonble
  {
  public:
    enum NodeType {
      Unknow = -1,
      Folder = 0,
      Memo = 1,
      Account = 2,
      Contact = 3,
      BankCard = 4,
      File = 5,
    } m_type = Unknow;

  public:
    Type() = default;
    ~Type() = default;
    Type(const NodeType type);

  public:
    bool isFolder() const;

  public:
    QUrl page() const;
    QUrl smallIcon() const;
    QUrl bigIcon() const;

  public:
    void fromJson(const QJsonValue& json) override;
    QJsonValue toJson() const override;
  };

} // namespace logic
