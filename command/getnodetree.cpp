#include "getnodetree.h"
#include "logic/notejsonconvertor.h"
#include "logic/node.h"
#include "logic/notejsonerror.h"


namespace command {

  GetNodeTree::GetNodeTree(QObject* parent)
    : Command("get_note_tree")
    , m_parent(parent)
  {
  }


  QJsonValue GetNodeTree::toJson() const
  {
    return QJsonValue();
  }


  void GetNodeTree::fromJson(const QJsonValue& json)
  {
    if (!json.isArray())
      throw logic::JsonError("it is not QJsonArray");

    QJsonArray array = json.toArray();
    m_list.clear();
    m_list.reserve(array.size());

    for(const auto& value : qAsConst(array)) {
      auto node = logic::JsonConvertor::createNode(value, m_parent);
      if (node != nullptr)
        m_list.append(node);
    }
  }


  bool GetNodeTree::isDublicate(const Command* const other) const
  {
    const GetNodeTree* command = dynamic_cast<const GetNodeTree*>(other);
    return command != nullptr;
  }

} // namespace command
