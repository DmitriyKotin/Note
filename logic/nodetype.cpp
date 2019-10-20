#include "nodetype.h"


namespace logic {

  Type::Type(const NodeType type)
    : m_type(type)
  {
  }


  bool Type::isFolder() const
  {
    return m_type == NodeType::Folder;
  }


  QUrl Type::page() const
  {
    switch (m_type) {
    case Folder: return QUrl("qrc:/qml/Note/FolderPage.qml");
    case Memo: return QUrl("qrc:/qml/Note/MemoPage.qml");
    case Account: return QUrl("qrc:/qml/Note/AccountPage.qml");
    case Contact: return QUrl("qrc:/qml/Note/ContactPage.qml");
    case BankCard: return QUrl("qrc:/qml/Note/BankCardPage.qml");
    case File: return QUrl("qrc:/qml/Note/FilePage.qml");
    default: return QUrl();
    }
  }


  QUrl Type::smallIcon() const
  {
    switch (m_type) {
    case Folder: return QUrl("qrc:/style/newStyle/pics/note/folder_small.png");
    case Memo: return QUrl("qrc:/style/newStyle/pics/note/memo_small.png");
    case Account: return QUrl("qrc:/style/newStyle/pics/note/account_small.png");
    case Contact: return QUrl("qrc:/style/newStyle/pics/note/contact_small.png");
    case BankCard: return QUrl("qrc:/style/newStyle/pics/note/bankcard_small.png");
    case File: return QUrl("qrc:/style/newStyle/pics/note/file_small.png");
    default: return QUrl();
    }
  }


  QUrl Type::bigIcon() const
  {
    switch (m_type) {
    case Folder: return QUrl("qrc:/style/newStyle/pics/note/folder_big.png");
    case Memo: return QUrl("qrc:/style/newStyle/pics/note/memo_big.png");
    case Account: return QUrl("qrc:/style/newStyle/pics/note/account_big.png");
    case Contact: return QUrl("qrc:/style/newStyle/pics/note/contact_big.png");
    case BankCard: return QUrl("qrc:/style/newStyle/pics/note/bankcard_big.png");
    case File: return QUrl("qrc:/style/newStyle/pics/note/file_big.png");
    default: return QUrl();
    }
  }


  void Type::fromJson(const QJsonValue& json)
  {
    if (json.isDouble())
    {
      const int type = json.toInt(-1);
      if (type > NodeType::File && type < NodeType::Unknow)
        m_type = NodeType::Unknow;
      else
        m_type = static_cast<NodeType>(type);
    }
    else {
      m_type = NodeType::Unknow;
    }
  }


  QJsonValue Type::toJson() const
  {
    return m_type;
  }

} // namespace logic
