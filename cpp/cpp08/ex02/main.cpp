#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main(void)
{
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << "stack cur_top: " << mstack.top() << std::endl;
        mstack.pop();
        std::cout << "stack cur_size: " << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        std::cout << "*it: " << *it << std::endl;
        std::cout << "++*it: " << ++(*it) << std::endl;
        std::cout << "*ite: " << *ite << std::endl;
        std::cout << "--*ite: " << --(*ite) << std::endl;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }
    std::cout   << std::endl;
    {
        std::list<int> mstack;
        mstack.push_back(5);
        mstack.push_back(17);
        std::cout << "list cur_top: " << mstack.back() << std::endl;
        mstack.pop_back();
        std::cout << "list cur_size: " << mstack.size() << std::endl;
        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);
        mstack.push_back(0);
        std::list<int>::iterator it = mstack.begin();
        std::list<int>::iterator ite = mstack.end();
        std::cout << "*it: " << *it << std::endl;
        std::cout << "++*it: " << ++(*it) << std::endl;
        std::cout << "*ite: " << *ite << std::endl;
        std::cout << "--*ite: " << --(*ite) << std::endl;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }
    std::cout   << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << "stack cur_top: " << mstack.top() << std::endl;
        mstack.pop();
        std::cout << "stack cur_size: " << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        MutantStack<int>::const_iterator it = mstack.begin();
        MutantStack<int>::const_iterator ite = mstack.end();
        std::cout << "*it: " << *it << std::endl;
        std::cout << "*ite: " << *ite << std::endl;
        int i = 0;
        while (it + i != ite)
        {
            std::cout << *(it + i) << std::endl;
            ++i;
        }
        std::stack<int> s(mstack);
    }
    return (0);
}