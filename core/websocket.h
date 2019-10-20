#ifndef WEBSOCKET_H
#define WEBSOCKET_H

#include <QObject>
#include <QWebSocket>


class WebSocket : public QObject
{
  Q_OBJECT

private:
  static WebSocket* m_instance;
  explicit WebSocket();
  ~WebSocket() override;

public:
  static WebSocket* getInstance();

  void open(const QUrl& url);
  void stop();

signals:
  void connectionError(const QString& error);


private slots:
  void onError(QAbstractSocket::SocketError error);
  void onSslErrors(const QList<QSslError>& errors);
  void onConnected();
  void onDisconnected();
  void testStateChanged(QAbstractSocket::SocketState socketState);
  void testTextFrameReceived(const QString &frame, bool isLastFrame);
  void testTextMessageReceived(const QString &message);
  void testBinaryFrameReceived(const QByteArray &frame, bool isLastFrame);
  void testBinaryMessageReceived(const QByteArray &message);
  void restartKillConnectionTimer();

  void onTextMessageReceived(const QString& message);

private:
  QByteArray createSession();

  void initWebSocket();

private:
  QWebSocket* m_socket;
};

#endif // WEBSOCKET_H
