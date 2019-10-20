#pragma once

#include "common/itemlist.h"


namespace logic {

  class Node;
  class NodeList : public ItemList<Node>
  {

  public:
    void fromOldJson(const QJsonValue& json, QObject* parent)
    {
      Q_UNUSED(json)
      Q_UNUSED(parent)
      //        m_list.clear();
      //        if (json.isArray()) {
      //          QJsonArray array = json.toArray();
      //          for(const auto& value : array) {
      //            const QJsonObject& object = value.toObject();
      //            if (object.isEmpty())
      //              continue;

      //            Item* item = new Item(parent);
      //            item->fromJson(object);
      //            if (item->isValid())
      //              m_list.append(item);
      //            else
      //              delete item;
      //          }
      //        }
    }

  };

} // namespace logic
