#include <iostream>
#include "infinite/engine.h"

int main()
{
    std::cout << "Infinite!" << std::endl;
    std::cout << infinite::Add(1,2) << std::endl;
    std::cout << infinite::Sub(3,2) << std::endl;
    return 0;
}