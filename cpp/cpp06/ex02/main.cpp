#include "Base.hpp"
#include <iostream>

int main(void)
{
    Base* test = generate();
    
    std::cout   << "identify(*p): ";
    identify(test);
    std::cout   << "identify(&p): ";
    identify(*test);
    delete test;
}