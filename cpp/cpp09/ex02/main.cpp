#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac <= 1)
	{
		std::cerr	<< "Error: invalid argument" << std::endl;
		return (1);
	}

	PmergeMe sort;

	if (!sort.vec_format(ac, av))
	{
		std::cerr	<< "Error: invalid argument" << std::endl;
		return (1);
	}
	std::cout	<< "Before: ";
	sort.print();
	sort.fordJohnsonSortVector();

	return (0);
}