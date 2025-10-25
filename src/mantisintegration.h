#ifndef MANTISINTEGRATION_H
#define MANTISINTEGRATION_H

#include <QObject>
#include <QThread>

class MantisApp;

class MantisIntegration : public QThread // Make use of the run() method
{
    Q_OBJECT
public:
    explicit MantisIntegration(QObject *parent = nullptr);
    ~MantisIntegration();

    /**
     * @brief
     */
    void run();

signals:

private:
    MantisApp& mApp; // Hold ref
};

#endif // MANTISINTEGRATION_H
