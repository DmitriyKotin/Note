#pragma once

#include <functional>
#include <QString>
#include <QJsonValue>
#include "error.h"


class Command
{
public:
  explicit Command(const QString& name, const bool old = false);
  virtual ~Command() = default;

public:
  virtual QJsonValue toJson() const = 0;
  virtual void fromJson(const QJsonValue& json) = 0;

public:
  QString name() const;
  int id() const;
  int timeout() const;
  bool isExclusive() const;
  bool isExecute() const;
  bool isCancel() const;

  void setId(const int id);
  void setTimeout(const int timeout);
  void setExclusive(const bool exclusive = true);
  void setExecute(const bool execute = true);
  void setCancel(const bool cancel = true);

public:
  bool isOk() const;
  bool isError() const;
  bool isOld() const;
  Error error() const;

public:
  virtual bool checkDublicate() const;
  virtual bool isDublicate(const Command* const other) const;

public:
  void onStart();
  void onSucceed();
  void onError(const Error& error);
  void onReject();
  void onTimeout();
  void onDublicate();
  void onDone(const bool status);

public:
  void setStartCallback(std::function<void()>&& callback);
  void setSucceedCallback(std::function<void()>&& callback);
  void setErrorCallback(std::function<void(const Error&)>&& callback);
  void setRejectCallback(std::function<void()>&& callback);
  void setTimeoutCallback(std::function<void()>&& callback, const int timeout = TIMEOUT);
  void setDublicateCallback(std::function<void()>&& callback);
  void setDoneCallback(std::function<void(bool)>&& callback);

protected:
  void setError(const Error& error);

protected:
  QString m_name;

  int m_id = INVALID_ACTION_ID;
  int m_timeout = TIMEOUT;

  bool m_exclusive = false;
  bool m_execute = false;
  bool m_cancel = false;
  bool m_old = false;

  Error m_error;

  std::function<void()> m_startCallback;    // начало выполнения команды
  std::function<void()> m_succeedCallback;  // при успешном выполнении
  std::function<void(const Error&)> m_errorCallback;    // при ошибочном выполнении
  std::function<void()> m_rejectCallback;   // при обрыве комманды
  std::function<void()> m_timeoutCallback;  // при отсутсвии ответа в течении таймаута
  std::function<void()> m_dublicateCallback;// команда дубликат
  std::function<void(bool)> m_doneCallback; // завершение выполнения команды

private:
  static const int INVALID_ACTION_ID = -1;
  static const int TIMEOUT = 4000; // 4 sec
};
