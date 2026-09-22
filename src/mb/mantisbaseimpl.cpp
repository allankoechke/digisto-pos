#include "mantisbaseimpl.h"

// wolfSSL ships legacy compat macros (Md5, Sha, ...) that collide with
// QCryptographicHash::Md5 / ::Sha512 etc. Disable them before any
// wolfSSL header gets pulled in via mantisbase.
#ifndef NO_OLD_WC_NAMES
#define NO_OLD_WC_NAMES
#endif
#ifndef NO_OLD_MD5_NAME
#define NO_OLD_MD5_NAME
#endif

#include <QDebug>

#include <mantisbase/mantisbase.h>
#include <mantisbase/core/router.h>


MantisBaseImpl::MantisBaseImpl(mb::json config)
    : mApp(mb::MantisBase::create(config))
{

}

MantisBaseImpl::~MantisBaseImpl()
{
    if(isServerRunning())
        mApp->close();
}

void MantisBaseImpl::run()
{
    try{
        if(auto res = mApp->run(); res != 0) {
            qDebug() << "Failed to start HTTP Server, error: " << res;
        }
    } catch(const std::exception& e) {
        qDebug() << "Server Crashed: " << e.what();
    }
}

bool MantisBaseImpl::isServerRunning() const
{
    return mApp && mApp->router().isRunning();
}


