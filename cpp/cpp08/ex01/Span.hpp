#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <ctime>

class Span
{
    private :
        unsigned int max_size;
        std::vector<int> container;

    public :
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span(); 

        void addNumber(int number);
        void addNumber(int number[], int len);
        int shortestSpan() const;
        int longestSpan() const;
};

#endif