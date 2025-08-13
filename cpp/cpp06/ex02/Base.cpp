#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base::~Base() {};

Base* generate(void)
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    int random = std::rand() % 3;

    switch (random)
    {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return NULL;
    }
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Class A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Class B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Class C" << std::endl;
}

void identify(Base &p)
{
	try
    {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "Class A" << std::endl;
        return ;
    } catch (...) {}
    try
    {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "Class B" << std::endl;
        return ;
    } catch (...) {}    
    try
    {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "Class C" << std::endl;
        return ;
    } catch (...) {}       
}