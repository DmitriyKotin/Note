#include "getnodevalue.h"
#include "logic/notejsonerror.h"


namespace command {

  GetNodeValue::GetNodeValue(const logic::Node* const node)
    : Command("get_note")
    , m_node(node)
  {
  }


  QJsonValue GetNodeValue::toJson() const
  {
    QJsonObject json;
    json["id"] = m_node->id();
    return json;
  }


  void GetNodeValue::fromJson(const QJsonValue& json)
  {
    if (!json.isObject())
      throw logic::JsonError("it is not QJsonObject " + m_node->toString());

    QJsonObject object = json.toObject();
    const int id = object["id"].toInt(-1);

    if (m_node->id() != id)
      throw logic::JsonError("error index for node " + m_node->toString());
    if (!object.contains("version"))
      throw logic::JsonError("not contains version for node " + m_node->toString());
    if (!object.contains("value"))
      throw logic::JsonError("not contains value for node " + m_node->toString());

    m_version = object["version"].toInt(-1);
    m_value = object["value"].toString();
  }


  bool GetNodeValue::isDublicate(const Command* const other) const
  {
    const GetNodeValue* command = dynamic_cast<const GetNodeValue*>(other);
    if (command == nullptr)
      return false;
    return m_node->id() == command->m_node->id();
  }

} // namespace command
