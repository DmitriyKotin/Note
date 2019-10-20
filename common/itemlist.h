#pragma once

#include <QList>
#include <QtAlgorithms>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QDebug>


template<class T>
class ItemList
{
public:
  using Item = T;

public:
  void fromJson(const QJsonValue& json, QObject* parent)
  {
    m_list.clear();
    if (json.isArray()) {
      QJsonArray array = json.toArray();
      for(const auto& value : array) {
        const QJsonObject& object = value.toObject();
        if (object.isEmpty())
          continue;

        Item* item = new Item(parent);
        item->fromJson(object);
        if (item->isValid())
          m_list.append(item);
        else
          delete item;
      }
    }
  }


public:
  void deleteAll() {qDeleteAll(m_list);}
  void clear() {m_list.clear();}
  bool empty() const {return m_list.empty();}
  int count() const {return m_list.size();}
  bool exist(const Item* item) const {return findIterator(item->id()) != m_list.end();}

  void reserve(const int alloc) {m_list.reserve(alloc);}

  int indexOf(Item* item) const {return m_list.indexOf(item);}
  Item* value(const int index) const {return m_list.value(index, nullptr);}


  Item* find(const int id) const {
    auto iter = findIterator(id);
    if (iter == m_list.end())
      return nullptr;
    return *iter;
  }


  Item* find(const QString& name) const {
    auto iter = findIterator(name);
    if (iter == m_list.end())
      return nullptr;
    return *iter;
  }


  void append(Item* item)
  {
    if (!exist(item))
      m_list.push_back(item);
    else
      qDebug() << Q_FUNC_INFO << "item exist " << item->name();
  }


  void remove(Item* item)
  {
    auto iter = findIterator(item->id());
    if (iter != m_list.end())
      m_list.erase(iter);
    else
      qDebug() << Q_FUNC_INFO << "unit findn't " << item->name();
  }


  void removeAt(const int index)
  {
    m_list.removeAt(index);
  }

private:
  using List = QList<Item*>;

  typename List::iterator findIterator(const int id) {
    return std::find_if(m_list.begin(), m_list.end(), [id](const Item* item){return item->id() == id;});
  }

  typename List::const_iterator findIterator(const int id) const {
    return std::find_if(m_list.begin(), m_list.end(), [id](const Item* item){return item->id() == id;});
  }

  typename List::iterator findIterator(const QString& name) {
    return std::find_if(m_list.begin(), m_list.end(), [&name](const Item* item){return item->name() == name;});
  }

  typename List::const_iterator findIterator(const QString& name) const {
    return std::find_if(m_list.begin(), m_list.end(), [&name](const Item* item){return item->name() == name;});
  }

public:
  typename List::iterator begin() {return m_list.begin();}
  typename List::iterator end() {return m_list.end();}
  typename List::const_iterator begin() const {return m_list.begin();}
  typename List::const_iterator end() const {return m_list.end();}

protected:
  List m_list;
};
