#include "engine.h"
#include <iostream>

namespace infinite
{
    int Add(int a, int b)
    {
        return a + b;
    }

    void GetInfo()
    {
        std::cout << "Infinite!" << std::endl;
#ifdef INFINITE_CONFIG_DEBUG
        std::cout << "Configuration: DEBUG" << std::endl;
#endif
#ifdef INFINITE_CONFIG_RELEASE
        std::cout << "Configuration: RELEASE" << std::endl;
#endif
#ifdef INFINITE_PLATFORM_WINDOWS
        std::cout << "Platform: WINDOWS" << std::endl;
#endif
#ifdef INFINITE_PLATFORM_LINUX
        std::cout << "Platform: LINUX" << std::endl;
#endif
#ifdef INFINITE_PLATFORM_MAC
        std::cout << "Platform: MAC" << std::endl;
#endif
    }
}