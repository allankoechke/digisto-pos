#ifndef MANTISBASEIMPL_H
#define MANTISBASEIMPL_H

#include <mantisbase/mantisbase.h>

#include <QObject>
#include <QThread>

class MantisBaseImpl : public QThread
{
    Q_OBJECT
public:
    Q_PROPERTY(bool isServerRunning READ isServerRunning NOTIFY isServerRunningChanged FINAL)

    explicit MantisBaseImpl(mb::json config = {});
    ~MantisBaseImpl();

    void run() override;

    bool isServerRunning() const;

signals:
    void isServerRunningChanged();

private:
    mb::MantisBase& mApp;
};

#endif // MANTISBASEIMPL_H
