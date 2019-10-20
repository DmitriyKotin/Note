#pragma once

#include "core/command.h"
#include "logic/node.h"


namespace command {

  class AddNote : public Command
  {
  public:
    explicit AddNote(const logic::Node* const node);

  public:
    QJsonValue toJson() const override;
    void fromJson(const QJsonValue& json) override;

  public:
    bool checkDublicate() const override {return true;};
    bool isDublicate(const Command* const other) const override;

  public:
    int id() const;

  private:
    const logic::Node* const m_node;
    int m_id = -1;
  };

} // namespace command
