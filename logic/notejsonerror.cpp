#include "notejsonerror.h"


namespace logic {

  JsonError::JsonError(const QString& message)
    : std::runtime_error(message.toStdString())
  {
  }

} // namespace logic
