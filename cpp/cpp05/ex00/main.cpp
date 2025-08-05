#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat test1("test1", 1);
    } 
    catch (std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout   << std::endl;
    try
    {
        Bureaucrat test2("test2", 150);
    } 
    catch (std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout   << std::endl;
    try
    {
        Bureaucrat test3("test3", 0);
    } 
    catch (std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    std::cout   << std::endl;

    try
    {
        Bureaucrat test4("test4", 151);
    } 
    catch (std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    std::cout   << std::endl;

    Bureaucrat max("max", 1);
    std::cout   << max << std::endl;
    Bureaucrat min("min", 150);
    std::cout   << min << '\n' << std::endl;
    
    try
    {
        max.IncrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    std::cout   << std::endl;

    try
    {
        min.DecrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    std::cout   << std::endl;

    // try
    // {
    //     Bureaucrat min("min", 151);
    //     try
    //     {
    //         min.DecrementGrade();
    //     }
    //     catch(const std::exception& e)
    //     {
    //         std::cerr << e.what() << '\n';
    //     }
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << "Caught exception: " << e.what() << std::endl;
    // }
    return 0;
}