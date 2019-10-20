#pragma once

#include "core/command.h"
#include "logic/nodelist.h"
#include "logic/node.h"
#include <QString>


namespace command {

  class OldGetNode : public Command
  {
  public:
    explicit OldGetNode(const logic::Node* const parent, const QString& key);

  public:
    QJsonValue toJson() const override;
    void fromJson(const QJsonValue& json) override;

  public:
    bool checkDublicate() const override {return true;};
    bool isDublicate(const Command* const other) const override;

  private:
    const logic::Node* const m_parent;
    QString m_key;
  };

} // namespace command
