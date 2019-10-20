#pragma once

#include "core/command.h"
#include "logic/node.h"


namespace command {

  class GetNodeValue : public Command
  {
  public:
    explicit GetNodeValue(const logic::Node* const node);

  public:
    QJsonValue toJson() const override;
    void fromJson(const QJsonValue& json) override;

  public:
    bool checkDublicate() const override {return true;};
    bool isDublicate(const Command* const other) const override;

  public:
    int version() const {return m_version;}
    QString value() const {return m_value;}

  private:
    const logic::Node* const m_node;
    int m_version;
    QString m_value;
  };

} // namespace command
