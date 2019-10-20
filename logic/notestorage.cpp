#include "notestorage.h"
#include "notefactory.h"


// for fake data
#include "logic/account.h"
#include "logic/bankcard.h"
#include "logic/contact.h"
#include "logic/file.h"
#include "logic/folder.h"
#include "logic/memo.h"
// for fake data


namespace logic {

  Storage::Storage(QObject* parent)
    : QObject(parent)
  {
    m_root = Factory::createRoot(this);
  }


  void Storage::clear()
  {

  }


  Folder* Storage::root() const
  {
    return m_root;
  }


  void Storage::setList(NodeList& list)
  {
    m_list.deleteAll();
    m_list.clear();
    m_list = std::move(list);

    createTree();
  }


  bool Storage::canAppend(Node* node, Folder* folder) const
  {
    return !folder->exist(node);
  }

  bool Storage::canRemove(Node* node, Folder* folder) const
  {
    return folder->exist(node);
  }

  bool Storage::canChange(Node* node) const
  {
    Q_UNUSED(node)

    return false;
  }

  bool Storage::canMove(Node* node, Folder* folder) const
  {
    Q_UNUSED(node)
    Q_UNUSED(folder)

    return false;
  }


  void Storage::append(Node* node, Folder* folder)
  {
    emit beginAppend(node, folder);
    folder->append(node);
    emit endAppend(node, folder);
  }

  void Storage::remove(Node* node, Folder* folder)
  {
    emit beginRemove(node, folder);
    folder->remove(node);
    emit endRemove(node, folder);
  }

  void Storage::change(Node* node)
  {
    emit beginChange(node);

    emit endChange(node);
  }

  void Storage::move(Node* node, Folder* folder)
  {
    emit beginMove(node, folder);

    emit endMove(node, folder);
  }


  void Storage::createTree()
  {
    for (logic::Node* node : m_list) {
      int folder_id = node->folder().id();
      Folder* folder = find(folder_id);
      if (folder != nullptr) {
        node->setFolder(folder);
        folder->append(node);
      }
    }
  }


  logic::Folder* Storage::find(const int id) const
  {
    if (id == 0 && m_root)
      return m_root;

    for (logic::Node* node : m_list) {
      if (node->id() == id)
        return qobject_cast<logic::Folder*>(node);
    }
    return nullptr;
  }


  void Storage::createFakeData()
  {
    logic::Account* ac1 = new logic::Account(this);
    ac1->setId(1);
    ac1->setName("ac1");
    ac1->setFolder(0);
    m_list.append(ac1);

    logic::Contact* c1 = new logic::Contact(this);
    c1->setId(2);
    c1->setName("c1");
    c1->setFolder(0);
    m_list.append(c1);

    logic::BankCard* bc1 = new logic::BankCard(this);
    bc1->setId(3);
    bc1->setName("bc1");
    bc1->setFolder(0);
    m_list.append(bc1);

    logic::Folder* f1 = new logic::Folder(this);
    f1->setId(4);
    f1->setName("f1");
    f1->setFolder(0);
    m_list.append(f1);

    logic::Account* ac2 = new logic::Account(this);
    ac2->setId(5);
    ac2->setName("ac2");
    ac2->setFolder(4);
    m_list.append(ac2);

    logic::Contact* c2 = new logic::Contact(this);
    c2->setId(6);
    c2->setName("c2");
    c2->setFolder(4);
    m_list.append(c2);

    logic::Account* ac10 = new logic::Account(this);
    ac10->setId(7);
    ac10->setName("ac10");
    ac10->setFolder(0);
    m_list.append(ac10);

    logic::Account* ac3 = new logic::Account(this);
    ac3->setId(8);
    ac3->setName("ac3");
    ac3->setFolder(0);
    m_list.append(ac3);

    logic::Account* ac4 = new logic::Account(this);
    ac4->setId(9);
    ac4->setName("ac4");
    ac4->setFolder(0);
    m_list.append(ac4);

    logic::Account* ac5 = new logic::Account(this);
    ac5->setId(10);
    ac5->setName("ac5");
    ac5->setFolder(0);
    m_list.append(ac5);

    logic::Account* ac6 = new logic::Account(this);
    ac6->setId(11);
    ac6->setName("ac6");
    ac6->setFolder(0);
    m_list.append(ac6);

    logic::Account* ac7 = new logic::Account(this);
    ac7->setId(12);
    ac7->setName("ac7");
    ac7->setFolder(0);
    m_list.append(ac7);

//    logic::Account* ac8 = new logic::Account(this);
//    ac8->setId(13);
//    ac8->setName("ac8");
//    ac8->setFolder(0);
//    m_list.append(ac8);

//    logic::Account* ac9 = new logic::Account(this);
//    ac9->setId(14);
//    ac9->setName("ac9");
//    ac9->setFolder(0);
//    m_list.append(ac9);

//    logic::Contact* c3 = new logic::Contact(this);
//    c3->setId(15);
//    c3->setName("c3");
//    c3->setFolder(0);
//    m_list.append(c3);

//    logic::Contact* c4 = new logic::Contact(this);
//    c4->setId(16);
//    c4->setName("c4");
//    c4->setFolder(0);
//    m_list.append(c4);


    createTree();
  }

} // namespace logic
