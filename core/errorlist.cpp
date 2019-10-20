#include "errorlist.h"


ErrorList::ErrorDescription ErrorList::description(const int code)
{
  if (m_data.find(code) == m_data.end())
    return ErrorDescription();
  return m_data[code];
}
