#include "Form.hpp"

int main()
{
    Form test("test", 100, 150);
    std::cout   << "=======getter test=======" << std::endl;
    std::cout   << "getName: " << test.getName() << '\n'
                << "getIsSigned: " << test.getIsSigned() << '\n'
                << "getGradeToSign: " << test.getGradeToSign() << '\n'
                << "getGradeToExecute: " << test.getGradeToExecute() << std::endl;
    std::cout   << test << std::endl;
    std::cout   << std::endl;

    std::cout   << "=======Form besigned test=======" << std::endl;
    Bureaucrat min("min", 150);
    std::cout   << min << std::endl;
    try
    {
        test.beSigned(min);
        std::cout   << "try Success" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout   << std::endl;

    Bureaucrat max("max", 1);
    std::cout   << max << std::endl;
    try
    {
        test.beSigned(max);
        std::cout   << "try Success" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout   << std::endl;

    std::cout   << "=======Bureaucrat signForm test=======" << std::endl;
    try
    {
        min.signForm(test);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout   << std::endl;

    try
    {
        max.signForm(test);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout   << std::endl;

    std::cout   << "=======Form constructor test=======" << std::endl;
    try
	{
		Form test1("test1", 0, 1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
    std::cout   << std::endl;

	try
	{
		Form test2("test2", 151, 1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
    std::cout   << std::endl;

	try
	{
		Form test3("test3", 1, 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
    std::cout   << std::endl;

	try
	{
		Form test4("test4", 1, 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
    std::cout   << std::endl;

    std::cout   << "=======Destructor=======" << std::endl;
    return 0;
}