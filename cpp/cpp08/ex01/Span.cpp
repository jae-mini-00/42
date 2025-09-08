#include "Span.hpp"

Span::Span() : max_size(0)
{
    std::cout   << "Span default constructor called" << std::endl;
}

Span::Span(unsigned int N) : max_size(N)
{
    std::cout   << "Span constructor called" << std::endl;
}

Span::Span(const Span& other) : max_size(other.max_size), container(other.container)
{
    std::cout   << "Span copy constructor called" << std::endl;
}

Span& Span::operator=(const Span& other)
{
    std::cout   << "Span copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->max_size = other.max_size;
        this->container = other.container;
    }
    return (*this);
}

Span::~Span()
{
    std::cout << "Span destructor called" << std::endl;
}

void Span::addNumber(int number)
{
    try {
        if (container.size() >= max_size)
            throw (std::runtime_error("Capacity exceeded."));
        container.push_back(number);
    } catch (std::exception &e) {
        std::cout   << e.what() << std::endl;
    }
}

void Span::addNumber(int number[], int len)
{
    try {
        if (container.size() + len > max_size)
            throw (std::runtime_error("Capacity exceeded."));
        container.insert(container.end(), number, number + len);
    } catch (std::exception &e) {
        std::cout   << e.what() << std::endl;
    }
}

int Span::shortestSpan() const
{
    if (container.size() < 2)
        throw (std::runtime_error("Not enough elements in the container to compute a span."));
    
    std::vector<int> sort(container);
    std::sort(sort.begin(), sort.end());
    int shortspan = sort[1] - sort[0];
    int temp;
    for (unsigned int i = 0; i < sort.size() - 1 ; i++)
    {
        temp = sort[i + 1] - sort[i];
        if (temp < shortspan)
            shortspan = temp;
    }
    return (shortspan);
}

int Span::longestSpan() const
{
    if (container.size() < 2)
        throw (std::runtime_error("Not enough elements in the container to compute a span."));
    std::vector<int>::const_iterator min = std::min_element(container.begin(), container.end());
    std::vector<int>::const_iterator max = std::max_element(container.begin(), container.end());
    return (*max - *min);
}