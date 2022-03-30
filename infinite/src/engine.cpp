#include "engine.h"
#include <iostream>
#include "sdl2/SDL.h"

namespace infinite
{
    // Public Section
    Engine& Engine::Instance()
    {
        if (!mInstance)
        {
            mInstance = new Engine();
        }
        return *mInstance;
    }

    void Engine::Run()
    {
        if (Initialize())
        {
            //loop
            while(mIsRunning)
            {
                mWindow.PollEvents();
            }

            Shutdown();
        }
    }

    // Private Section
    bool Engine::Initialize()
    {
        bool ret = false;
        
        if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        {
            std::cout << "Error initializing SDL2: " << SDL_GetError() << std::endl; 
        }
        else 
        {
            SDL_version version;
            SDL_VERSION(&version);
            std::cout << "SDL: " << (int32_t)version.major << "." << (int32_t)version.minor << "." << (int32_t)version.patch << std::endl; 

            if (mWindow.Create())
            {
                ret = true;
                mIsRunning = true;
            }
        }

        if (!ret)
        {
            std::cout << "Engine initialization failed. Shutting down." << std::endl;
            Shutdown();
        }

        return ret;
    }

    void Engine::Shutdown()
    {
        mIsRunning = false;
        mWindow.Shutdown();
        SDL_Quit();
    }
    
    Engine* Engine::mInstance = nullptr;

    Engine::Engine()
        :mIsRunning(false)
    {
        GetInfo();
    }

    void Engine::GetInfo()
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