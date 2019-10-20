#include "websocket.h"
#include <QRandomGenerator>
#include <QDebug>


WebSocket* WebSocket::m_instance = nullptr;

WebSocket *WebSocket::getInstance()
{
  if(m_instance == nullptr) {
    m_instance = new WebSocket();
  }
  return m_instance;
}

void WebSocket::open(const QUrl &url)
{
  if(!url.isValid()) {
    emit connectionError(tr("Невалидный адрес сервера"));
    return;
  }

  initWebSocket();
#ifdef Q_OS_WIN
  QByteArray os = "Win";
#elif defined Q_OS_LINUX
  QByteArray os = "Linux";
#elif defined Q_OS_MAC
  QByteArray os = "MacOS";
#endif

  QNetworkRequest req = m_socket->request();
  req.setUrl(url);
  req.setRawHeader("session", createSession());
  req.setRawHeader("version", "Test QWebSocket app");
  req.setRawHeader("os", os);
  req.setRawHeader("instantDisconnect", "1");

  m_socket->open(req);
}

void WebSocket::stop()
{
  qDebug() << Q_FUNC_INFO << endl;

  //    pingTimer.stop();
  //    killConnectionTimer.stop();

  if(!m_socket)
    return;

  if(m_socket->state() != QAbstractSocket::UnconnectedState)
    m_socket->close();

  m_socket->deleteLater();
  m_socket = Q_NULLPTR;
}

void WebSocket::onError(QAbstractSocket::SocketError error)
{
  qDebug() << Q_FUNC_INFO << error << endl;
}

void WebSocket::onSslErrors(const QList<QSslError> &errors)
{
  for(const QSslError& error : errors)
    qDebug() << Q_FUNC_INFO << error.errorString() << endl;
}

void WebSocket::onConnected()
{
  qDebug() << Q_FUNC_INFO << endl;
}

void WebSocket::onDisconnected()
{
  qDebug() << Q_FUNC_INFO << endl;
}

void WebSocket::testStateChanged(QAbstractSocket::SocketState socketState)
{
  qDebug() << Q_FUNC_INFO << socketState << endl;
}

void WebSocket::testTextFrameReceived(const QString &frame, bool isLastFrame)
{
  qDebug() << Q_FUNC_INFO << isLastFrame << frame << endl;
}

void WebSocket::testTextMessageReceived(const QString &message)
{
  qDebug() << Q_FUNC_INFO << message << endl;
}

void WebSocket::testBinaryFrameReceived(const QByteArray &frame, bool isLastFrame)
{
  qDebug() << Q_FUNC_INFO << isLastFrame << frame << endl;
}

void WebSocket::testBinaryMessageReceived(const QByteArray &message)
{
  qDebug() << Q_FUNC_INFO << message << endl;
}

void WebSocket::restartKillConnectionTimer()
{
  qDebug() << Q_FUNC_INFO << endl;
}

void WebSocket::onTextMessageReceived(const QString &message)
{
  qDebug() << Q_FUNC_INFO << message << endl;
}

QByteArray WebSocket::createSession()
{
  const int length = 64;
  const QByteArray data("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");

  QByteArray session(length, char());
  std::generate(session.begin(), session.end(), [&length, &data](){return data[QRandomGenerator::global()->bounded(length)];});
  return session;
}


void WebSocket::initWebSocket()
{
  if(m_socket) {
    m_socket->close();
    m_socket->deleteLater();
    m_socket = nullptr;
  }

  m_socket = new QWebSocket();
  m_socket->setParent(this);

  using ErrorCallback = void(QWebSocket::*)(QAbstractSocket::SocketError);
  connect(m_socket, static_cast<ErrorCallback>(&QWebSocket::error), this,   &WebSocket::onError);
  connect(m_socket, &QWebSocket::sslErrors,                         this,   &WebSocket::onSslErrors);
  connect(m_socket, &QWebSocket::connected,                         this,   &WebSocket::onConnected);
  connect(m_socket, &QWebSocket::disconnected,                      this,   &WebSocket::onDisconnected);
  connect(m_socket, &QWebSocket::textFrameReceived,                 this,   &WebSocket::restartKillConnectionTimer);
  connect(m_socket, &QWebSocket::textMessageReceived,               this,   &WebSocket::restartKillConnectionTimer);
  connect(m_socket, &QWebSocket::binaryFrameReceived,               this,   &WebSocket::restartKillConnectionTimer);
  connect(m_socket, &QWebSocket::binaryMessageReceived,             this,   &WebSocket::restartKillConnectionTimer);
  connect(m_socket, &QWebSocket::stateChanged,                      this,   &WebSocket::testStateChanged);
  connect(m_socket, &QWebSocket::textFrameReceived,                 this,   &WebSocket::testTextFrameReceived);
  connect(m_socket, &QWebSocket::textMessageReceived,               this,   &WebSocket::testTextMessageReceived);
  connect(m_socket, &QWebSocket::binaryFrameReceived,               this,   &WebSocket::testBinaryFrameReceived);
  connect(m_socket, &QWebSocket::binaryMessageReceived,             this,   &WebSocket::testBinaryMessageReceived);
  connect(m_socket, &QWebSocket::pong,                              this,   &WebSocket::restartKillConnectionTimer);
  connect(m_socket, &QWebSocket::textMessageReceived,               this,   &WebSocket::onTextMessageReceived);
}

WebSocket::WebSocket()
  : m_socket(nullptr)
{
  qsrand(static_cast<uint>(QTime::currentTime().msecsSinceStartOfDay()));
}

WebSocket::~WebSocket()
{

}
