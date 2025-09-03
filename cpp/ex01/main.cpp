#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr	<< "Error: invalid argument" << std::endl;
		return (1);
	}
	RPN test;
	if (!test.eval(av[1]))
		return (1);
	return (0);
}