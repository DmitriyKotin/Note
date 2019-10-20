#include "oldgetnode.h"
#include "logic/notejsonerror.h"


namespace command {

  OldGetNode::OldGetNode(const logic::Node* const parent, const QString& key)
    : Command("getNode")
    , m_parent(parent)
    , m_key(key)
  {
  }


  QJsonValue OldGetNode::toJson() const
  {
    QJsonObject json;
    json["key"] = m_key;
    return json;
  }


  void OldGetNode::fromJson(const QJsonValue& json)
  {
    Q_UNUSED(json)
  }


  bool OldGetNode::isDublicate(const Command* const other) const
  {
    const OldGetNode* command = dynamic_cast<const OldGetNode*>(other);
    return command != nullptr;
  }

} // namespace command
