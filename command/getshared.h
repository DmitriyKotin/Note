#pragma once

#include "core/command.h"
#include "logic/nodelist.h"
#include <QObject>


namespace command {

  class GetShared : public Command
  {
  public:
    explicit GetShared(QObject* parent);

  public:
    QJsonValue toJson() const override;
    void fromJson(const QJsonValue& json) override;

  public:
    bool checkDublicate() const override {return true;};
    bool isDublicate(const Command* const other) const override;

  private:
    QObject* m_parent = nullptr;
  };

} // namespace command
