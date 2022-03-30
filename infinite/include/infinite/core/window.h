#pragma once

struct SDL_Window;
namespace infinite::core
{
    class Window
    {
    public:
        Window();
        ~Window();

        bool Create();
        void Shutdown();
        void PollEvents();

    private:
        SDL_Window *mWindow;
    };
}