#pragma once

#include "core/window.h"

namespace infinite
{
    class Engine
    {
    public:
        static Engine &Instance();
        ~Engine() {};

        void Run();
        inline void Quit() { mIsRunning = false; }

    private:
        Engine();
        static Engine *mInstance;
        core::Window mWindow;
        bool mIsRunning;

        void GetInfo();
        [[nodiscard]] bool Initialize();
        void Shutdown();
    };
}