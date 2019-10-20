#include "renamenode.h"
#include "logic/notejsonconvertor.h"
#include "logic/notejsonerror.h"


namespace command {

  RenameNote::RenameNote(const logic::Node* const node, const QString& name)
    : Command("update_display_info"),
      m_node(node),
      m_name(name)
  {
  }


  QJsonValue RenameNote::toJson() const
  {
    return logic::JsonConvertor::createJson(m_node);
  }


  void RenameNote::fromJson(const QJsonValue& json)
  {
    Q_UNUSED(json)
  }


  bool RenameNote::isDublicate(const Command* const other) const
  {
    const RenameNote* command = dynamic_cast<const RenameNote*>(other);
    if (command == nullptr)
      return false;
    return m_node->id() == command->m_node->id();
  }

} // namespace command
