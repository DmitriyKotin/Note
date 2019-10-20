#include "notefactory.h"
#include "account.h"
#include "bankcard.h"
#include "contact.h"
#include "memo.h"
#include "folder.h"
#include "file.h"


namespace logic {

  Folder* Factory::createRoot(QObject* parent)
  {
    Folder* root = new Folder(parent);
    root->m_id = 0;
    root->setName("root");
    return root;
  }

} // namespace logic
