#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <list>

class PmergeMe
{
	private :
		int leftover;
		std::vector<int> vec_sort;

		std::vector<std::pair<int, int>> makePairs();
		std::vector<int> big_vector(std::vector<std::pair<int, int>> vec_pair);
	public :
 		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		bool vec_format(int ac, char **av);
		std::vector<int> fordJohnsonSortVector(void);
		void print(void);
};

#endif