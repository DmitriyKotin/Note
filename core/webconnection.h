#pragma once

#include <QObject>
#include <QWebSocket>


class WebConnection : public QObject
{
  Q_OBJECT

public:
  WebConnection(QObject* parent = nullptr);
  ~WebConnection() override = default;

public:
  void open(const QUrl& url);
  void close();

private slots:
  void onConnected();
  void onDisconnected();

  void onTextMessageReceived(const QString& message);

  void onSslErrors(const QList<QSslError>& errors);
  void onError(QAbstractSocket::SocketError error);

private:
  QWebSocket m_socket;
};
