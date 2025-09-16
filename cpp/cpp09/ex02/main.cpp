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
	double vec_elapsed;
	double deque_elapsed;
	{	std::cout	<< "Before: ";
		sort.vec_print();
		clock_t start = clock();
		sort.fordJohnsonSortVector();
		clock_t end = clock();
		vec_elapsed = static_cast<double>(end - start);
	}
	{
		clock_t start = clock();
		sort.fordJohnsonSortDeque();
		clock_t end = clock();
		deque_elapsed = static_cast<double>(end - start);
	}
	sort.is_sort();
	sort.timer_print(vec_elapsed, deque_elapsed);
	return (0);
}