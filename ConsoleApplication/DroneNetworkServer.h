#ifndef __DroneNetworkServer_h__
#define __DroneNetworkServer_h__

#include "NetworkHandler.h"

namespace jb
{
class DroneNetworkServer : public whytsoft::NetworkHandler
{
public:
    DroneNetworkServer(unsigned short port);

private:
    virtual void onNewConnection(size_t socketId) const override;
    virtual void onConnectionClosed(size_t socketId) const override;
};

} // jb

#endif