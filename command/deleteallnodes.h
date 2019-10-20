#pragma once

#include "core/command.h"


namespace command {

  class DeleteAllNodes : public Command
  {
  public:
    explicit DeleteAllNodes();

  public:
    QJsonValue toJson() const override;
    void fromJson(const QJsonValue& json) override;

  public:
    bool checkDublicate() const override {return true;};
    bool isDublicate(const Command* const other) const override;
  };

} // namespace command
