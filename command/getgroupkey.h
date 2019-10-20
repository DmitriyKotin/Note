#pragma once

#include "core/command.h"
#include <QByteArray>


namespace command {

  class GetGroupKey : public Command
  {
  public:
    explicit GetGroupKey();

  public:
    QJsonValue toJson() const override;
    void fromJson(const QJsonValue& json) override;

  public:
    bool checkDublicate() const override {return true;}
    bool isDublicate(const Command* const other) const override;

  public:
    QByteArray key() const {return m_key;}

  private:
    QByteArray m_key;
  };

} // namespace command
