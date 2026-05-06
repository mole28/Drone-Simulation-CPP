#include "DroneNetworkServer.h"

#include <sstream>

namespace jb
{

DroneNetworkServer::DroneNetworkServer(unsigned short port)
    : whytsoft::NetworkHandler(port)
{
}

void DroneNetworkServer::onNewConnection(size_t socketId) const 
{
    std::stringstream os;
    os << "New Connection SocketId: " << socketId << "\n";
}

void DroneNetworkServer::onConnectionClosed(size_t socketId) const 
{
    std::stringstream os;
    os << "Connection Closed SocketId: " << socketId << "\n";
}

} // jb