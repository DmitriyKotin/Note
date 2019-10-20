#pragma once

#include "nodekey.h"
#include "displayinfo.h"
#include "common/db_ptr.h"
#include "logic/nodelist.h"


namespace logic {

  class JsonConvertor;
  class Factory;
  class Folder;

  class Node : public QObject
  {
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)

//    Q_PROPERTY(Folder* folder READ folder CONSTANT)
    Q_PROPERTY(int user READ user WRITE setUser NOTIFY userChanged)
    Q_PROPERTY(int version READ version WRITE setVersion NOTIFY versionChanged)
    Q_PROPERTY(QString comment READ comment WRITE setComment NOTIFY commentChanged)

    Q_PROPERTY(QUrl qmlPage READ qmlPage CONSTANT)
    Q_PROPERTY(QUrl smallIcon READ smallIcon CONSTANT)
    Q_PROPERTY(QUrl bigIcon READ bigIcon CONSTANT)

    friend class JsonConvertor;
    friend class Factory;

  public:
    explicit Node(QObject* parent = nullptr);
    ~Node() override = default;

  public:
    Q_INVOKABLE virtual bool isFolder() const = 0;
    Q_INVOKABLE QString toString() const;
    Q_INVOKABLE bool isLoaded() const {return m_isLoaded;}
    Q_INVOKABLE QString fullPath() const;

  public:
    int id() const;
    QString name() const;
    db_ptr<Folder> folder() const;
    int user() const;
    int version() const;
    QString value() const;
    QString comment() const;

  public:
    virtual QUrl qmlPage() const = 0;
    virtual QUrl smallIcon() const = 0;
    virtual QUrl bigIcon() const = 0;

  public slots:
    void setId(const int id);
    void setName(const QString& name);
    void setUser(const int user);
    void setVersion(const int version);
    void setValue(const QString& value);
    void setComment(const QString& comment);

    // for fake data
    void setFolder(const int id);
    void setFolder(Folder* folder);

  signals:
    void nameChanged(const QString&);
    void createChanged(const QDateTime&);
    void changeChanged(const QDateTime&);

    void userChanged(const int);
    void versionChanged(const int);
    void valueChanged();
    void commentChanged(const QString&);

  private:
    virtual void valueFromJson(const QJsonObject& json) = 0;

  protected:
    int m_id;
    Key m_key;
    DisplayInfo m_info;
    db_ptr<Folder> m_folder;

    int m_user = -1;
    int m_version = -1;

    bool m_isLoaded = false;
    QString m_comment;
  };

} // namespace logic
