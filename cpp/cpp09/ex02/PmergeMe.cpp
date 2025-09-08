#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : leftover(-1) {}

PmergeMe::PmergeMe(const PmergeMe& other) : leftover(other.leftover), vec_sort(other.vec_sort) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		leftover = other.leftover;
		vec_sort = other.vec_sort;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::vec_format(int ac, char **av)
{
	std::string one_line = av[1];

	for (int i = 2; i < ac; i++)
	{
		one_line +=  ' ';
		one_line +=  av[i];
	}

	std::istringstream iss(one_line);
	std::string token;
	int num;

	while (iss >> token)
	{
        for (size_t i = 0; i < token.size(); i++)
        {
            if (!std::isdigit(token[i]))
                return (false);
        }

		std::istringstream conv(token);
		if (!(conv >> num))
			return (false);
		else if (num <= 0)
			return (false);
		else
			vec_sort.push_back(num);
	}
	return (true);
}

(1 5) (4 3)

-> (5 1) (4 3)

-> (4 3) (5 1) (10 8) (7 6)

-> (3 4) (1 5) 
std::vector<std::pair<int, int>> PmergeMe::makePairs()
{
	std::vector<std::pair<int, int>> vec_pair;
	int a;
	int b;
	int i = 0;

	while (i + 1 < static_cast<int>(vec_sort.size()))
	{
		a = vec_sort[i++];
		b = vec_sort[i++];
        if (a > b)
            vec_pair.push_back(std::make_pair(a, b));
        else
            vec_pair.push_back(std::make_pair(b, a));
	}
	leftover = -1;
    if (i < static_cast<int>(vec_sort.size()))
        leftover = vec_sort[i];
	return (vec_pair);
}

std::vector<int> PmergeMe::big_vector(std::vector<std::pair<int, int>> vec_pair)
{
	std::vector<int> big;

	for (size_t i = 0; i < vec_pair.size(); i++)
		big.push_back(vec_pair[i].first);
	std::sort(big.begin(), big.end());
	return (big);
}

std::vector<int> PmergeMe::fordJohnsonSortVector(void)
{
	std::vector<std::pair<int, int>> vec_pair = makePairs();
	std::vector<int> big = big_vector(vec_pair);

	return ;
}

void PmergeMe::print(void)
{
	std::vector<int>::iterator begin = vec_sort.begin();
	std::vector<int>::iterator end = vec_sort.end();

	for (; begin + 1 != end; begin++)
		std::cout	<< *begin << ' ';
	std::cout	<< *begin << std::endl;
	return ;
}