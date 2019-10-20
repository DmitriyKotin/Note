#include "webconnection.h"


WebConnection::WebConnection(QObject* parent)
  : QObject(parent)
{
  connect(&m_socket, &QWebSocket::connected, this, &WebConnection::onConnected);
  connect(&m_socket, &QWebSocket::disconnected, this, &WebConnection::onDisconnected);
  connect(&m_socket, &QWebSocket::sslErrors, this, &WebConnection::onSslErrors);
  connect(&m_socket, qOverload<QAbstractSocket::SocketError>(&QWebSocket::error), this, &WebConnection::onError);

}


void WebConnection::open(const QUrl& url)
{
  m_socket.open(url);
}


void WebConnection::close()
{
  m_socket.close();
}



void WebConnection::onConnected()
{
  connect(&m_socket, &QWebSocket::textMessageReceived, this, &WebConnection::onTextMessageReceived);

  //  m_webSocket.sendTextMessage(QStringLiteral("Hello, world!"))
}

void WebConnection::onDisconnected()
{
  disconnect(&m_socket, &QWebSocket::textMessageReceived, this, &WebConnection::onTextMessageReceived);

}


void WebConnection::onTextMessageReceived(const QString& message)
{
  qDebug() << "Message received:" << message;
}


void WebConnection::onSslErrors(const QList<QSslError>& errors)
{
  for(const QSslError& error : qAsConst(errors))
    qDebug() << Q_FUNC_INFO << error.errorString() << endl;

  m_socket.ignoreSslErrors();
}


void WebConnection::onError(QAbstractSocket::SocketError error)
{

}
