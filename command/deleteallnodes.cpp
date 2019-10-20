#include "deleteallnodes.h"
#include "logic/notejsonerror.h"


namespace command {

  DeleteAllNodes::DeleteAllNodes()
    : Command("delete_all_nodes")
  {
  }


  QJsonValue DeleteAllNodes::toJson() const
  {
    return QJsonValue();
  }


  void DeleteAllNodes::fromJson(const QJsonValue& json)
  {
    Q_UNUSED(json)
  }


  bool DeleteAllNodes::isDublicate(const Command* const other) const
  {
    const DeleteAllNodes* command = dynamic_cast<const DeleteAllNodes*>(other);
    return command != nullptr;
  }

} // namespace command
