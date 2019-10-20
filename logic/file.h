#pragma once

#include "Node.h"


namespace logic {

  class File : public Node
  {
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString key READ key WRITE setKey NOTIFY keyChanged)

  public:
    explicit File(QObject* parent = nullptr);
    ~File() override = default;

  public:
    Q_INVOKABLE bool isFolder() const override {return false;}

    //      void fromJson(const QJsonValue& json);
    void fromOldJson(const QJsonValue& json);
    QJsonValue toJson() const;

  public:
    QString name() const;
    QString key() const;

    void setName(const QString& name);
    void setKey(const QString& key);

  signals:
    void nameChanged(const QString&);
    void keyChanged(const QString&);

  public:
    QUrl qmlPage() const override {return QUrl("qrc:/qml/FilePage.qml");}
    QUrl smallIcon() const override {return QUrl("qrc:/qml/image/file_small.png");}
    QUrl bigIcon() const override {return QUrl("qrc:/qml/image/file_big.png");}

  private:
    void valueFromJson(const QJsonObject& json) override;

  private:
    QString m_name;
    QString m_key;
  };

} // namespace logic
