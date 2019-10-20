#pragma once

#include "node.h"
#include "nodetype.h"
#include <QJsonValue>


namespace logic {

  class Factory
  {
  public:
    static Folder* createRoot(QObject* parent);
  };

} // namespace logic
