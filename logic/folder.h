#pragma once

#include "node.h"
#include "nodelist.h"


namespace logic {

  class Folder : public Node
  {
    Q_OBJECT

    Q_PROPERTY(QString key READ key WRITE setKey NOTIFY keyChanged)

  public:
    explicit Folder(QObject* parent = nullptr);
    ~Folder() override = default;

  public:
    Q_INVOKABLE bool isFolder() const override {return true;}

    //      void fromJson(const QJsonValue& json);
    void fromOldJson(const QJsonValue& json);
    QJsonValue toJson() const;

  public:
    void clear();

  public:
    int count() const;
    Node* value(const int index) const;
    int indexOf(Node* node) const;

    bool exist(const Node* node) const;
    void append(Node* node);
    void remove(Node* node);

  public slots:
    QString key() const;

  public:
    void setKey(const QString& key);

  signals:
    void keyChanged(const QString&);

  public:
    QUrl qmlPage() const override {return QUrl("qrc:/qml/FolderPage.qml");}
    QUrl smallIcon() const override {return QUrl("qrc:/qml/image/folder_small.png");}
    QUrl bigIcon() const override {return QUrl("qrc:/qml/image/folder_big.png");}

  private:
    void valueFromJson(const QJsonObject& json) override;

  private:
    QString m_key; // из версии 1.0

  private:
    NodeList m_children;
  };

} // namespace logic
