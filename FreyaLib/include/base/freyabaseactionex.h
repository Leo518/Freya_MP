#ifndef FREYABASEACTIONEX_H
#define FREYABASEACTIONEX_H

#include "freyalib_global.h"
#include "freyabasecontrol.h"
#include "freyabaseaction.h"
#include <QThread>

class FREYALIBSHARED_EXPORT FreyaBaseActionEx : public QObject, public FreyaBaseAction
{
    Q_OBJECT
public:
    explicit FreyaBaseActionEx(FreyaBaseControl *pControl = NULL, const char *objectName = NULL);
    virtual ~FreyaBaseActionEx();

protected:
    void Execute(const quint64 &command);
    void Execute(FreyaBaseData *pData);

protected slots:
    virtual void OnExecuteEx(const quint64 &command) = 0;
    virtual void OnExecuteEx(FreyaBaseData *pData) = 0;

signals:
    void ToExecute(const quint64 &command);
    void ToExecute(FreyaBaseData *pData);

protected:
    FreyaBaseControl *m_FreyaBaseControl;

private:
    QThread             *m_thread;
};

#endif // FREYABASEACTIONEX_H