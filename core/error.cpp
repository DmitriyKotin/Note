#include "error.h"
#include "errorlist.h"

QString Error::language = "ru";


Error::Error(const int code)
{
  static ErrorList list;
  m_code = code;
  m_description = list.description(code);
}


bool Error::isOk() const
{
  return m_code == 0;
}


bool Error::isError() const
{
  return m_code != 0;
}


int Error::code() const
{
  return m_code;
}


ErrorList::Module Error::module() const
{
  return m_description.module;
}


ErrorList::Type Error::type() const
{
  return m_description.type;
}


ErrorList::Subject Error::subject() const
{
  return m_description.subject;
}


QString Error::text() const
{
  if (language == "ru")
    return m_description.ruText;
  return m_description.enText;
}


QString Error::fullText() const
{
  if (language == "ru")
    return m_description.ruFullText;
  return m_description.enFullText;
}
