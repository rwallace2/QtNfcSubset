/*!
 * @copyright
 * Copyright Research In Motion Limited, 2012-2012
 * Research In Motion Limited. All rights reserved.
 */

#ifndef QNDEFNFCSMARTPOSTERRECORD_H
#define QNDEFNFCSMARTPOSTERRECORD_H

#include "nfc_ndef_global.h"
#include "qndefrecord.h"
#include "qndefnfctextrecord.h"

class QUrl;

namespace QtMobilitySubset {

class NFC_NDEFSHARED_EXPORT QNdefNfcSmartPosterRecord : public QNdefRecord
{
public:
    enum ActionValue {
        Unset = -1,
        Do = 0,
        Save = 1,
        Open = 2
    };

    Q_DECLARE_NDEF_RECORD(QNdefNfcSmartPosterRecord, QNdefRecord::NfcRtd, "Sp", QByteArray(0, char(0)))

    bool hasTitle(const QString& locale) const;
    bool hasAction() const;
    bool hasIcon(const QByteArray& mimetype) const;
    bool hasSize() const;
    bool hasTypeInfo() const;

    QString title(const QString& locale) const;
    QString titleLocale(const QString& locale) const;
    QNdefNfcTextRecord::Encoding titleEncoding(const QString& locale) const;

    bool addTitle(const QString& text, const QString& locale, QNdefNfcTextRecord::Encoding encoding);

    QUrl uri() const;
    bool setUri(const QUrl& url);

    ActionValue action() const;
    bool setAction(ActionValue act);

    QByteArray icon(const QByteArray& mimetype) const;
    QByteArray iconType(const QByteArray& mimetype) const;

    QByteArray icon(int index) const;
    QByteArray iconType(int index) const;
    quint32 iconCount() const;

    void addIcon(const QByteArray& type, const QByteArray& data);

    quint32 size() const;
    bool setSize(quint32 size);

    QByteArray typeInfo() const;
    bool setTypeInfo(const QByteArray& type);
};

} // namespace QtMobilitySubset

#endif // QNDEFNFCSMARTPOSTERRECORD_H
