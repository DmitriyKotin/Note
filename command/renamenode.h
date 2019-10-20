#pragma once

#include "core/command.h"
#include "logic/node.h"


namespace command {

  class RenameNote : public Command
  {
  public:
    explicit RenameNote(const logic::Node* const node, const QString& name);

  public:
    QJsonValue toJson() const override;
    void fromJson(const QJsonValue& json) override;

  public:
    bool checkDublicate() const override {return true;};
    bool isDublicate(const Command* const other) const override;

  private:
    const logic::Node* const m_node = nullptr;
    const QString m_name;
  };

} // namespace command
