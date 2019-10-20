#pragma once

#include <type_traits>
#include <QPointer>


template<class T>
class db_ptr : public QPointer<T>
{
  static_assert(!std::is_pointer<T>::value, "db_ptr template type must not be a pointer type");

public:
  db_ptr()
    : QPointer<T>()
  {
  }

  explicit db_ptr(const int id)
    : QPointer<T>(),
      m_id(id)
  {
  }

  explicit db_ptr(T* ptr)
    : QPointer<T>(ptr),
      m_id(ptr->id())
  {
  }

public:
  inline void swap(db_ptr& other)
  {
    QPointer<T>::swap(other);
    std::swap(m_id, other.id);
  }

  inline db_ptr<T>& operator=(const int id)
  {
    QPointer<T>::clear();
    m_id = id;
    return *this;
  }

  inline db_ptr<T>& operator=(T* ptr)
  {
    QPointer<T>::operator=(ptr);
    if (ptr != nullptr)
      m_id = ptr->id();
    else
      m_id = -1;
    return *this;
  }

public:
  int id() const
  {
    if (! QPointer<T>::isNull())
      return QPointer<T>::data()->id();
    return m_id;
  }

private:
  int m_id = -1;
};

template <class T> Q_DECLARE_TYPEINFO_BODY(db_ptr<T>, Q_MOVABLE_TYPE);

template <class T>
inline bool operator==(const T* lhs, const db_ptr<T>& rhs)
{
  if (lhs != nullptr)
    return lhs->id() == rhs.id();
  return rhs.isNull();
}

template<class T>
inline bool operator==(const db_ptr<T>& lhs, const T* rhs)
{
  if (rhs != nullptr)
    return rhs->id() == lhs.id();
  return lhs.isNull();
}

template <class T>
inline bool operator==(T* lhs, const db_ptr<T>& rhs)
{
  if (lhs != nullptr)
    return lhs->id() == rhs.id();
  return rhs.isNull();
}

template<class T>
inline bool operator==(const db_ptr<T>& lhs, T* rhs)
{
  if (rhs != nullptr)
    return rhs->id() == lhs.id();
  return lhs.isNull();
}

template<class T>
inline bool operator==(const db_ptr<T>& lhs, const db_ptr<T>& rhs)
{
  return lhs.id() == rhs.id();
}

template <class T>
inline bool operator!=(const T* lhs, const db_ptr<T>& rhs)
{
  if (lhs != nullptr)
    return lhs->id() != rhs.id();
  return !rhs.isNull();
}

template<class T>
inline bool operator!= (const db_ptr<T>& lhs, const T* rhs)
{
  if (rhs != nullptr)
    return rhs->id() != lhs.id();
  return !lhs.isNull();
}

template <class T>
inline bool operator!=(T* lhs, const db_ptr<T>& rhs)
{
  if (lhs != nullptr)
    return lhs->id() != rhs.id();
  return !rhs.isNull();
}

template<class T>
inline bool operator!= (const db_ptr<T>& lhs, T* rhs)
{
  if (rhs != nullptr)
    return rhs->id() != lhs.id();
  return !lhs.isNull();
}

template<class T>
inline bool operator!= (const db_ptr<T>& lhs, const db_ptr<T>& rhs)
{
  return lhs.id() != rhs.id();
}
