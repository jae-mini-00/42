#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <deque>
#include <ctime>
#include <iomanip>
#include <sys/time.h>


class PmergeMe
{
	private :
		int leftover;
		//vecter member
		std::vector<int> vec_sort;
		std::vector<std::pair<int,int> > vec_merge_buffer;
		//deque member
		std::deque<int> deque_sort;
		std::deque<std::pair<int, int> > deque_merge_buffer;

		//vector algoritm
		std::vector<std::pair<int, int> > vec_makePairs();
		void vec_insertionSort(std::vector<std::pair<int, int> >& vec_pair, \
									int left, int right);
		void vec_merge(std::vector<std::pair<int, int> >& vec_pair, \
							int left, int right, int mid);
		void vec_merge_sort(std::vector<std::pair<int, int> >& vec_pair, \
							int left, int right);
		std::vector<int> vec_getJacobsthalInsertionOrder(size_t size);
		//deque algoritm
		std::deque<std::pair<int, int> > deque_makePairs();
		void deque_insertionSort(std::deque<std::pair<int, int> >& deque_pair, \
									int left, int right);
		void deque_merge(std::deque<std::pair<int, int> >& deque_pair, \
									int left, int right, int mid);
		void deque_merge_sort(std::deque<std::pair<int, int> >& deque_pair, \
									int left, int right);
		std::deque<int> deque_getJacobsthalInsertionOrder(size_t size);
		
	public :
 		PmergeMe(); // 멤버변수 정리 해야함
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		//method
		void is_sort(void);
		void timer_print(double vec_elapsed, double deque_elapsed);

		bool vec_format(int ac, char **av);
		void fordJohnsonSortVector(void);
		void vec_print(void);
		void fordJohnsonSortDeque();
};

#endif