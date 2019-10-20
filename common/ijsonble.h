#pragma once
#ifndef IJSONBLE_H
#define IJSONBLE_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QObject>


// Интерфейс сериализуемых объетов в json файлы
class IJsonble
{
public:
  IJsonble() = default;
  virtual ~IJsonble() = default;

public:
  virtual void fromJson(const QJsonValue& json) = 0;
  virtual QJsonValue toJson() const = 0;

public:
  static QList<int> idList(const QJsonValue& json)
  {
    QList<int> list;
    if (json.isArray()) {
      QJsonArray array = json.toArray();

      for (const auto& value: array) {        
        if (value.isObject()) {
          const QJsonObject& object = value.toObject();
          if (object.isEmpty())
            continue;
          list.push_back(object["id"].toInt(0));
        }
        else if (value.isDouble()) {
          list.push_back(value.toInt(0));
        }
      }
    }
    return list;
  }

};

#endif // IJSONBLE_H
