#pragma once

#include <QObject>
#include "nodelist.h"
#include "node.h"
#include "folder.h"


namespace logic {

  class Storage : public QObject
  {
    Q_OBJECT

  public:
    explicit Storage(QObject* parent = nullptr);

  public:
    void clear();
    Folder* root() const;

    void setList(NodeList& list);

  public:
    bool canAppend(Node* node, Folder* folder) const;
    bool canRemove(Node* node, Folder* folder) const;
    bool canChange(Node* node) const;
    bool canMove(Node* node, Folder* folder) const;

    void append(Node* node, Folder* folder);
    void remove(Node* node, Folder* folder);
    void change(Node* node);
    void move(Node* node, Folder* folder);

  signals:
    void beginAppend(Node*, Folder*);
    void endAppend(Node*, Folder*);

    void beginRemove(Node*, Folder*);
    void endRemove(Node*, Folder*);

    void beginChange(Node*);
    void endChange(Node*);

    void beginMove(Node*, Folder*);
    void endMove(Node*, Folder*);

  private:
    void createTree();    
    logic::Folder* find(const int id) const;

  public:
    void createFakeData();

  private:
    NodeList m_list;
    Folder* m_root = nullptr;
  };

} // namespace logic
