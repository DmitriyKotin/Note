#include "commandpool.h"
#include <QtAlgorithms>
#include "error.h"


namespace Json
{
  namespace Keys
  {
    const QString ActionId("actionId");
    const QString Command("command");
    const QString Error("error");
    const QString Payload("payload");
    const QString Args("args");
  } // namespace Keys
} // namespace Json


CommandPool::CommandPool(QObject* parent)
  : QObject(parent)
{
}


void CommandPool::add(Command* command)
{
  if (command->checkDublicate()) {
    if (existInExecute(command) || existInQueue(command)) {
      command->onDublicate();
      return;
    }
  }

  if (m_isExclusive) {
    enqueue(command);
  }
  else {
    if (command->isExclusive())
      addExclusive(command);
    else
      addNormal(command);
  }
}


bool CommandPool::isExclusive() const
{
  return m_isExclusive;
}


bool CommandPool::isEmpty() const
{
  return m_activeCommands.empty() && m_queueCommands.empty();
}


bool CommandPool::isActive() const
{
  return !m_activeCommands.empty();
}


void CommandPool::addExclusive(Command* command)
{
  if (m_activeCommands.empty())
    execute(command);
  else
    enqueue(command);
}


void CommandPool::addNormal(Command* command)
{
  if (m_activeCommands.size() < m_togetherCommand)
    execute(command);
  else
    enqueue(command);
}


bool CommandPool::existInQueue(Command* command) const
{
  return std::find_if(
        m_queueCommands.begin(),
        m_queueCommands.end(),
        [&command](const Command* cmd) {return command->isDublicate(cmd);}
  ) != m_queueCommands.end();
}


bool CommandPool::existInExecute(Command* command) const
{
  return std::find_if(
        m_activeCommands.begin(),
        m_activeCommands.end(),
        [&command](const Command* cmd) {return command->isDublicate(cmd);}
  ) != m_activeCommands.end();
}


void CommandPool::enqueue(Command* command)
{
  m_queueCommands.enqueue(command);
}


void CommandPool::execute(Command* command)
{
  command->onStart();
  m_activeCommands.push_back(command);
  request(command);
}


void CommandPool::request(Command* command)
{
  command->setId(m_currentActionId++);

//  QJsonObject json = command->toJson();
//  json[Json::Keys::ActionId] = command->id();

  //  m_client->send(command->name(), json);
  command->onStart();
}


void CommandPool::response(const QJsonObject& json)
{
  if (json.isEmpty() ||
      !json.contains(Json::Keys::ActionId) ||
      !json.contains(Json::Keys::Command) ||
      !json.contains(Json::Keys::Error)) {
    return;
  }

  const int id = json[Json::Keys::ActionId].toInt(-1);
  Command* command = findActiveCommand(id);
  if (command == nullptr)
    return;

  if (!json.contains(Json::Keys::Payload) && command->isOld())
    return;

  const QString name = json[Json::Keys::Command].toString();
  if (command->name() != name) {
    finishError(command, Error(1));
    return;
  }

  const Error error(json[Json::Keys::Error].toInt());
  if (error.isError()) {
    finishError(command, Error(2));
    return;
  }

  if (command->isOld())
    command->fromJson(json);
  else
    command->fromJson(json[Json::Keys::Payload]);

  if (command->isError()) {
    finishError(command, command->error());
    return;
  }

  finishOk(command);
}


void CommandPool::finishError(Command* command, const Error& error)
{
  command->onError(error);
  command->onDone(false);
  remove(command);
}


void CommandPool::finishOk(Command* command)
{
  command->onSucceed();
  command->onDone(true);
  remove(command);
}


Command* CommandPool::findActiveCommand(const int id) const
{
  auto iter = std::find_if(m_activeCommands.begin(), m_activeCommands.end(), [id](const Command* command){return command->id();});
  if (iter == m_activeCommands.end())
    return nullptr;
  return *iter;
}


void CommandPool::remove(Command* command)
{
  if (m_isExclusive)
    m_isExclusive = false;

  m_activeCommands.removeAll(command);
  delete command;
}
