#pragma once

#include "core/command.h"
#include "logic/node.h"


namespace command {

  class UpdateDisplayInfo : public Command
  {
  public:
    explicit UpdateDisplayInfo(const logic::Node* const node);

  public:
    QJsonValue toJson() const override;
    void fromJson(const QJsonValue& json) override;

  public:
    bool checkDublicate() const override {return true;};
    bool isDublicate(const Command* const other) const override;

  private:
    const logic::Node* const m_node;
  };

} // namespace command
