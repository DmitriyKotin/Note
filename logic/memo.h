#pragma once

#include "Node.h"


namespace logic {

  class Memo : public Node
  {
    Q_OBJECT

  public:
    explicit Memo(QObject* parent = nullptr);
    ~Memo() override = default;

  public:
    Q_INVOKABLE bool isFolder() const override {return false;}

    //      void fromJson(const QJsonValue& json);
    void fromOldJson(const QJsonValue& json);
    QJsonValue toJson() const;

  public:
    QUrl qmlPage() const override {return QUrl("qrc:/qml/MemoPage.qml");}
    QUrl smallIcon() const override {return QUrl("qrc:/qml/image/memo_small.png");}
    QUrl bigIcon() const override {return QUrl("qrc:/qml/image/memo_big.png");}

  private:
    void valueFromJson(const QJsonObject& json) override;

  };

} // namespace logic
