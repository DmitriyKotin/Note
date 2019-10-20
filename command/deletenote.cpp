#include "deletenote.h"
#include "logic/notejsonerror.h"


namespace command {

  DeleteNote::DeleteNote(const logic::Node* const node)
    : Command("delete_note")
    , m_node(node)
  {
  }


  QJsonValue DeleteNote::toJson() const
  {
    QJsonObject json;
    json["id"] = m_node->id();
    return json;
  }


  void DeleteNote::fromJson(const QJsonValue& json)
  {
    Q_UNUSED(json)
  }


  bool DeleteNote::isDublicate(const Command* const other) const
  {
    const DeleteNote* command = dynamic_cast<const DeleteNote*>(other);
    if (command == nullptr)
      return false;
    return m_node->id() == command->m_node->id();
  }

} // namespace command
