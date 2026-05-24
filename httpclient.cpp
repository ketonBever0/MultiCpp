#include "httpclient.h"

#include <QCoreApplication>

HttpClient::HttpClient(QObject *parent)
    : QObject{parent}, manager(new QNetworkAccessManager(this))
{
    connect(manager, &QNetworkAccessManager::finished, this, [this](QNetworkReply* reply) {
        if (reply->error() == QNetworkReply::NoError) {
            QString body = reply->readAll();
            emit responseReceived(body);
        } else {
            emit errorOccured(reply->errorString());
        }
        reply->deleteLater();
    });
}

void HttpClient::get(const QString& url) {
    manager->get(QNetworkRequest(QUrl(url)));
}


