#pragma once

#include "core/command.h"
#include "logic/nodelist.h"
#include <QObject>


namespace command {

  class GetNodeTree : public Command
  {
  public:
    explicit GetNodeTree(QObject* parent);

  public:
    QJsonValue toJson() const override;
    void fromJson(const QJsonValue& json) override;

  public:
    bool checkDublicate() const override {return true;}
    bool isDublicate(const Command* const other) const override;

  public:
    logic::NodeList& list() {return m_list;}

  private:
    QObject* m_parent;
    logic::NodeList m_list;
  };

} // namespace command

