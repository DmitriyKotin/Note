#include "webclient.h"


WebClient::WebClient(QObject* parent)
  : QObject(parent)
{

}


void WebClient::open(const QUrl& url)
{
  m_connection.open(url);
}


void WebClient::close()
{
  m_connection.close();
}
