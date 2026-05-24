#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <QObject>
#include <QNetworkReply>

class HttpClient : public QObject
{
    Q_OBJECT
public:
    explicit HttpClient(QObject *parent = nullptr);

    void get(const QString& url);

signals:
    void responseReceived(const QString& body);
    void errorOccured(const QString& error);

private:
    QNetworkAccessManager* manager;


signals:
};

#endif // HTTPCLIENT_H
