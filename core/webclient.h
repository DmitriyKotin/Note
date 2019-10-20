#pragma once

#include <QObject>
#include "webconnection.h"


class WebClient : public QObject
{
  Q_OBJECT

public:
  explicit WebClient(QObject* parent = nullptr);
  ~WebClient() override = default;

public:
  void open(const QUrl& url);
  void close();

private:
  QUrl m_url;
  WebConnection m_connection;
};
