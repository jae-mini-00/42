#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main(void)
{
    std::vector<int> container;
    container.push_back(10);
    container.push_back(20);
    container.push_back(30);
    container.push_back(40);
    container.push_back(42);
    int target = 43;
    std::vector<int>::iterator it = easyfind(container, target); 
    
    if (it != container.end())
        std::cout   <<  *it << std::endl;
    else
        std::cout   <<  target << ": Not found" << std::endl;
}