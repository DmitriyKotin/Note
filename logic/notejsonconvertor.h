#pragma once

#include <QObject>
#include <QJsonValue>
#include "node.h"
#include "displayinfo.h"


namespace logic {

  class JsonConvertor
  {
  public:
    static Node* createNode(const QJsonValue& json, QObject* parent);
    static QJsonValue createJson(const Node* const node);

  private:
    static Node* createNode(const DisplayInfo::Type type, QObject* parent);
  };

} // namespace logic
