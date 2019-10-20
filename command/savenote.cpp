#include "savenote.h"
#include "logic/notejsonconvertor.h"
#include "logic/notejsonerror.h"


namespace command {

  SaveNote::SaveNote(const logic::Node* const node)
    : Command("save_note")
    , m_node(node)
  {
  }


  QJsonValue SaveNote::toJson() const
  {
    return logic::JsonConvertor::createJson(m_node);
  }


  void SaveNote::fromJson(const QJsonValue& json)
  {
    Q_UNUSED(json)
  }


  bool SaveNote::isDublicate(const Command* const other) const
  {
    const SaveNote* command = dynamic_cast<const SaveNote*>(other);
    if (command == nullptr)
      return false;
    return m_node->id() == command->m_node->id();
  }

} // namespace command
