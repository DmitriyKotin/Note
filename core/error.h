#pragma once

#include <QString>
#include "errorlist.h"


class Error
{
public:
  explicit Error(const int code);

public:
  bool isOk() const;
  bool isError() const;

public:
  int code() const;

  ErrorList::Module module() const;
  ErrorList::Type type() const;
  ErrorList::Subject subject() const;

  QString text() const;
  QString fullText() const;

private:
  int m_code;
  ErrorList::ErrorDescription m_description;
  static QString language;
};
