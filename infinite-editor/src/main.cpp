#include <iostream>
#include "infinite/engine.h"

int main()
{
    infinite::GetInfo();
    infinite::Initialize();
    infinite::Shutdown();

// #ifdef INFINITE_PLATFORM_WINDOWS
//     system("pause");
// #endif
    std::cout << "Press ENTER to continue.." << std::endl;
    std::cin.ignore();
    return 0;
}