#include "DroneSimulation.h"

#include <iostream>

int main()
{
    try
    {
        jb::DroneSimulation simulation;
        simulation.run();
    }
    catch (const std::exception& err)
    {
        std::cerr << "A critical error occurred: " << err.what() << std::endl;
        return 1;
    }
    catch (...)
    {
        std::cerr << "An unknown error occurred." << std::endl;
        return 1;
    }

    return 0;
}