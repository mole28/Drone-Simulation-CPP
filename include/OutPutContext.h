#ifndef __OutPutContext_h__
#define __OutPutContext_h__

#include "NetworkHandler.h"

#include <string>

namespace jb
{

class OutPutContext
{
public:
    OutPutContext(whytsoft::NetworkHandler& _nh, size_t _socketId)
        : m_nh(_nh), m_socketId(_socketId) 
    {
    }

    void output(const std::string& str) const;

private:
    whytsoft::NetworkHandler& m_nh;
    size_t m_socketId;
};

}

#endif