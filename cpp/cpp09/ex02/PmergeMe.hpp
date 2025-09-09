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

		//vector algoritm
		std::vector<std::pair<int, int> > makePairs();
		void vec_insertionSort(std::vector<std::pair<int, int> >& vec_pair, \
									int left, int right);
		void vec_merge(std::vector<std::pair<int, int> >& vec_pair, \
							int left, int right, int mid);
		void vec_merge_sort(std::vector<std::pair<int, int> >& vec_pair, \
							int left, int right);
		std::vector<size_t> getJacobsthalInsertionOrder(size_t size);

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