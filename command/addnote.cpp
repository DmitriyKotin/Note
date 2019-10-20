#include "addnote.h"
#include "logic/notejsonerror.h"
#include "logic/notejsonconvertor.h"


namespace command {

  AddNote::AddNote(const logic::Node* const node)
    : Command("add_note")
    , m_node(node)
  {
  }


  QJsonValue AddNote::toJson() const
  {
    return logic::JsonConvertor::createJson(m_node);
  }


  void AddNote::fromJson(const QJsonValue& json)
  {
    if (!json.isObject())
      throw logic::JsonError("it is not QJsonObject " + m_node->toString());

    QJsonObject object = json.toObject();
    m_id = object["id"].toInt();
    if (m_id <= 0)
      throw logic::JsonError("error index for node " + m_node->toString());
  }


  bool AddNote::isDublicate(const Command* const other) const
  {
    const AddNote* command = dynamic_cast<const AddNote*>(other);
    if (command == nullptr)
      return false;
    return m_node->name() == command->m_node->name();
  }


  int AddNote::id() const
  {
    return m_id;
  }

} // namespace command
