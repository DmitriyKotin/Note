#include "notejsonconvertor.h"
#include "notejsonerror.h"
#include "account.h"
#include "bankcard.h"
#include "contact.h"
#include "file.h"
#include "folder.h"
#include "memo.h"


namespace logic {

  Node* JsonConvertor::createNode(const QJsonValue& json, QObject* parent)
  {
    if (json.isObject()) {
      QJsonObject object = json.toObject();
      Node* node = nullptr;

      try {
        Key key(object);
        DisplayInfo info(object["display_info"], key);

        node = createNode(info.type(), parent);
        node->m_id = object["id"].toInt();
        node->m_folder = object["parent_id"].toInt();

        node->m_key = std::move(key);
        node->m_info = std::move(info);
        return node;
      }
      catch(const JsonError& error) {
        if (node != nullptr)
          delete node;
        qCritical() << "bad json, " << error.what();
      }
    }
    return nullptr;
  }


  QJsonValue JsonConvertor::createJson(const Node* const node)
  {
    QJsonObject json;
    json["id"] = node->m_id;
    json["parent_id"] = node->m_folder->id();
    node->m_key.toJson(json);
    json["display_info"] = node->m_info.toJson();
    json["value"] = node->value();
    return json;
  }


  Node* JsonConvertor::createNode(const DisplayInfo::Type type, QObject* parent)
  {
    switch(type) {
    case Type::Folder:
      return new Folder(parent);
    case Type::Memo:
      return new Memo(parent);
    case Type::Account:
      return new Account(parent);
    case Type::Contact:
      return new Contact(parent);
    case Type::BankCard:
      return new BankCard(parent);
    case Type::File:
      return new File(parent);
    }
    return nullptr;
  }

} // namespace logic
