#pragma once

#include <stdexcept>
#include <QString>


namespace logic {

  class JsonError : public std::runtime_error
  {
  public:
    JsonError(const QString& message);
  };

} // namespace logic
