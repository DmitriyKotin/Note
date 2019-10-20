#include "command.h"


Command::Command(const QString& name, const bool old)
  : m_name(name),
    m_error(0),
    m_old(old)
{
}


QString Command::name() const
{
  return m_name;
}


int Command::id() const
{
  return m_id;
}

int Command::timeout() const
{
  return m_timeout;
}

bool Command::isExclusive() const
{
  return m_exclusive;
}

bool Command::isExecute() const
{
  return m_execute;
}

bool Command::isCancel() const
{
  return m_cancel;
}


void Command::setId(const int id)
{
  m_id = id;
}

void Command::setTimeout(const int timeout)
{
  m_timeout = timeout;
}

void Command::setExclusive(const bool exclusive)
{
  m_exclusive = exclusive;
}

void Command::setExecute(const bool execute)
{
  m_execute = execute;
}

void Command::setCancel(const bool cancel)
{
  m_cancel = cancel;
}


bool Command::isOk() const
{
  return m_error.isOk();
}

bool Command::isError() const
{
  return m_error.isError();
}

bool Command::isOld() const
{
  return m_old;
}


Error Command::error() const
{
  return m_error;
}

void Command::setError(const Error& error)
{
  m_error = error;
}


bool Command::checkDublicate() const
{
  return false;
}


bool Command::isDublicate(const Command* const other) const
{
  return false;
}


void Command::onStart()
{
  if (m_startCallback)
    m_startCallback();
}


void Command::onSucceed()
{
  if (m_succeedCallback)
    m_succeedCallback();
}


void Command::onError(const Error& error)
{
  if (m_errorCallback)
    m_errorCallback(error);
}


void Command::onReject()
{
  if (m_rejectCallback)
    m_rejectCallback();
}


void Command::onTimeout()
{
  if (m_timeoutCallback)
    m_timeoutCallback();
}


void Command::onDublicate()
{
  if (m_dublicateCallback)
    m_dublicateCallback();
}


void Command::onDone(const bool status)
{
  if (m_doneCallback)
    m_doneCallback(status);
}


void Command::setStartCallback(std::function<void()>&& callback)
{
  m_startCallback = std::move(callback);
}


void Command::setSucceedCallback(std::function<void()>&& callback)
{
  m_succeedCallback = std::move(callback);
}


void Command::setErrorCallback(std::function<void(const Error& error)>&& callback)
{
  m_errorCallback = std::move(callback);
}


void Command::setRejectCallback(std::function<void()>&& callback)
{
  m_rejectCallback = std::move(callback);
}


void Command::setTimeoutCallback(std::function<void()>&& callback, const int timeout)
{
  m_timeoutCallback = std::move(callback);
  m_timeout = timeout;
}


void Command::setDublicateCallback(std::function<void()>&& callback)
{
  m_dublicateCallback = std::move(callback);
}


void Command::setDoneCallback(std::function<void(bool)>&& callback)
{
  m_doneCallback = std::move(callback);
}
