#pragma once

#include <map>
#include <QString>


class ErrorList
{
public:
  ErrorList() = default;
  ~ErrorList() = default;

  enum Module {
    OrganizationalUnit
  };

  enum Type {
    Database,
    Data
  };

  enum Subject {
    Login,
    User,
    Email
  };

public:
  struct ErrorDescription
  {
    Module module;
    Type type;
    Subject subject;

    QString ruText;
    QString ruFullText;

    QString enText;
    QString enFullText;
  };

public:
  ErrorDescription description(const int code);

private:
  std::map<int, const ErrorDescription> m_data = {
    {1, {OrganizationalUnit, Database, Login, "ruText", "ruFullText", "enText", "enFullText"}},
    {2, {OrganizationalUnit, Database, User, "ruText", "ruFullText", "enText", "enFullText"}},
    {3, {OrganizationalUnit,Data, Email, "ruText", "ruFullText", "enText", "enFullText"}}
  };
};
