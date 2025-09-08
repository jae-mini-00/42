#include "Span.hpp"

int main(void)
{
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    std::cout   << std::endl;
    {
        Span sp;

        sp.addNumber(1);

        try {
            std::cout   << "shortestSpan: " << sp.shortestSpan() << std::endl;
        } catch (std::exception &e) {
            std::cerr   << e.what() << std::endl; 
        }
        try {
            std::cout   << "longestSpan: " << sp.longestSpan() << std::endl;
        } catch (std::exception &e) {
            std::cerr   << e.what() << std::endl; 
        }
    }
    std::cout   << std::endl;
    {
        Span sp(5);
        int temp[] = {1, 43, 10, 5, 20};

        sp.addNumber(temp, 5);
        try {
            std::cout   << "shortestSpan: " << sp.shortestSpan() << std::endl;
        } catch (std::exception &e) {
            std::cerr   << e.what() << std::endl; 
        }
        try {
            std::cout   << "longestSpan: " << sp.longestSpan() << std::endl;
        } catch (std::exception &e) {
            std::cerr   << e.what() << std::endl; 
        }
    }
    std::cout   << std::endl;
    {
        Span sp(5);
        int temp[] = {1, 22, 10, 5, -20};

        sp.addNumber(temp, 5);
        try {
            std::cout   << "shortestSpan: " << sp.shortestSpan() << std::endl;
        } catch (std::exception &e) {
            std::cerr   << e.what() << std::endl; 
        }
        try {
            std::cout   << "longestSpan: " << sp.longestSpan() << std::endl;
        } catch (std::exception &e) {
            std::cerr   << e.what() << std::endl; 
        }
    }
    std::cout   << std::endl;
    {
        Span sp(10000);

        std::srand(std::time(NULL));
        for (int i = 0; i < 10000; ++i)
            sp.addNumber(std::rand());

        try {
            std::cout   << "shortestSpan: " << sp.shortestSpan() << std::endl;
        } catch (const std::exception& e) {
            std::cerr   << e.what() << std::endl;
        }
        try {
            std::cout   << "longestSpan: " << sp.longestSpan() << std::endl;
        } catch (const std::exception& e) {
            std::cerr   << e.what() << std::endl;
        }
    }
    std::cout   << std::endl;
}