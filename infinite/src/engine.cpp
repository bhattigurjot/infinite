#include "engine.h"
#include <iostream>
#include "sdl2/SDL.h"

namespace infinite
{
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

    bool Initialize()
    {
        bool ret = true;
        
        if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        {
            std::cout << "Error initializing SDL2: " << SDL_GetError() << std::endl; 
            ret = false;
        }
        else 
        {
            SDL_version version;
            SDL_VERSION(&version);
            std::cout << "SDL: " << (int32_t)version.major << "." << (int32_t)version.minor << "." << (int32_t)version.patch << std::endl; 
        }

        return ret;
    }

    void Shutdown()
    {
        SDL_Quit();
    }
}