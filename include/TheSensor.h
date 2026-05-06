#ifndef __TheSensor_h__
#define __TheSensor_h__

namespace jb
{

class TheSensor
{
public:
    virtual ~TheSensor() = default; 
    virtual unsigned int getEnergyCost() const = 0;

private:
};

} // jb

#endif