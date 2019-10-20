#include "updatedisplayinfo.h"
#include "logic/notejsonerror.h"


namespace command {

  UpdateDisplayInfo::UpdateDisplayInfo(const logic::Node* const node)
    : Command("update_display_info")
    , m_node(node)
  {
  }


  QJsonValue UpdateDisplayInfo::toJson() const
  {
    return QJsonValue();
    //QJsonObject json = m_node->toJson().toObject();
    //      json["id"] = m_node->id();
    //      return json;
  }


  void UpdateDisplayInfo::fromJson(const QJsonValue& json)
  {
    Q_UNUSED(json)
  }


  bool UpdateDisplayInfo::isDublicate(const Command* const other) const
  {
    const UpdateDisplayInfo* command = dynamic_cast<const UpdateDisplayInfo*>(other);
    if (command == nullptr)
      return false;
    return m_node->id() == command->m_node->id();
  }

} // namespace command
