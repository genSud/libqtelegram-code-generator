// This file generated by libqtelegram-code-generator.
// You can download it from: https://github.com/Aseman-Land/libqtelegram-code-generator
// DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN

#ifndef TELEGRAMAPI_H
#define TELEGRAMAPI_H

#include "core/abstractapi.h"
#include "core/session.h"
#include "telegram/types/types.h"
#include "secret/secretchat.h"

class TelegramApi : public AbstractApi
{
    Q_OBJECT
    friend class FileHandler;

public:
    explicit TelegramApi(Session *session, Settings *settings, CryptoUtils *crypto, QObject *parent = 0);
    virtual ~TelegramApi();

/*! === methods === !*/
Q_SIGNALS:
/*! === signals === !*/
    void error(qint64 msgId, qint32 errorCode, const QString &errorText, const QString &functionName);
    void errorRetry(qint64 msgId, qint32 errorCode, const QString &errorText);

private:
    qint64 uploadSaveFilePart(Session *session, qint64 fileId, qint32 filePart, const QByteArray &bytes);
    qint64 uploadSaveBigFilePart(Session *session, qint64 fileId, qint32 filePart, qint32 fileTotalParts, const QByteArray &bytes);
    qint64 uploadGetFile(Session *session, const InputFileLocation &location, qint32 offset = 0, qint32 limit = BLOCK);

private:
    Settings *mSettings;
    CryptoUtils *mCrypto;

/*! === privates === !*/
    void onError(Query *q, qint32 errorCode, const QString &errorText);
    void onErrorRetry(Query *q, qint32 errorCode, const QString &errorText);
};

#endif // TELEGRAMAPI_H
