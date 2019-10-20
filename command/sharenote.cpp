#include "sharenote.h"
#include "logic/notejsonerror.h"


namespace command {

  ShareNote::ShareNote(const logic::Node* const node)
    : Command("share_note")
    , m_node(node)
  {
  }


  QJsonValue ShareNote::toJson() const
  {
    QJsonObject json;
    json["id"] = m_node->id();
    return json;
  }


  void ShareNote::fromJson(const QJsonValue& json)
  {
    Q_UNUSED(json)
  }


  bool ShareNote::isDublicate(const Command* const other) const
  {
    const ShareNote* command = dynamic_cast<const ShareNote*>(other);
    if (command == nullptr)
      return false;
    return m_node->id() == command->m_node->id();
  }

} // namespace command
