#pragma once

#include "core/command.h"


namespace command {

  class Logout : public Command
  {
  public:
    explicit Logout();

  public:
    QJsonValue toJson() const override;
    void fromJson(const QJsonValue& json) override;

  public:
    bool checkDublicate() const override {return true;}
    bool isDublicate(const Command* const other) const override;
  };

} // namespace command
