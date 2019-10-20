#pragma once

#include <QObject>
#include <QString>
#include <QJsonObject>
#include <QQueue>
#include <QList>
#include "command.h"
#include "error.h"

// TODO: Добавить таймер
// NOTE: проверить все аргументы функций
class CommandPool : public QObject
{
  Q_OBJECT

public:
  explicit CommandPool(QObject* parent = nullptr);
  virtual ~CommandPool() override = default;

public:
  void add(Command* command);

public:
  bool isExclusive() const;
  bool isEmpty() const;
  bool isActive() const;

public slots:
  void request(Command* command);
  void response(const QJsonObject& json);

private:
  void execute(Command* command);
  void enqueue(Command* command);

  void addExclusive(Command* command);
  void addNormal(Command* command);

  bool existInQueue(Command* command) const;
  bool existInExecute(Command* command) const;

  void finishError(Command* command, const Error& error);
  void finishOk(Command* command);

  void remove(Command* command);

  Command* findActiveCommand(const int id) const;

private:
  QQueue<Command*> m_queueCommands;
  QList<Command*> m_activeCommands;

  bool m_isExclusive = false;
  int m_togetherCommand = 1024;

  int m_currentActionId = 42;
};
