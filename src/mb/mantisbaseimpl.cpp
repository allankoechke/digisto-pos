#include "mantisbaseimpl.h"
#include <QDebug>

MantisBaseImpl::MantisBaseImpl(mb::json config)
    : mApp(mb::MantisBase::create(config))
{

}

MantisBaseImpl::~MantisBaseImpl()
{
    if(isServerRunning())
        mApp.close();
}

void MantisBaseImpl::run()
{
    try{
        if(auto res = mApp.run(); res != 0) {
            qDebug() << "Failed to start HTTP Server, error: " << res;
        }
    } catch(const std::exception& e) {
        qDebug() << "Server Crashed: " << e.what();
        emit
    }
}

bool MantisBaseImpl::isServerRunning() const
{
    return mApp.router().server().is_running();
}
