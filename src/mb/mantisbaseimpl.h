#ifndef MANTISBASEIMPL_H
#define MANTISBASEIMPL_H

#include <QObject>

class MantisBaseImpl : public QObject
{
    Q_OBJECT
public:
    explicit MantisBaseImpl(QObject *parent = nullptr);

signals:
};

#endif // MANTISBASEIMPL_H
