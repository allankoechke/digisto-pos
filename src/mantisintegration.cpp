#include "mantisintegration.h"
#include <mantis/mantis.h>

MantisIntegration::MantisIntegration(QObject *parent)
    : QObject{parent},
{}

MantisIntegration::~MantisIntegration()
{
    // Shut down MantisApp instance
    mApp.close(); // No worry of any thrown error
}

void MantisIntegration::run()
{
    mApp.run();
}
