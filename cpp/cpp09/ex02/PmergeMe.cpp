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

	for (int i = 2; i < ac; ++i)
	{
		one_line +=  ' ';
		one_line +=  av[i];
	}

	std::istringstream iss(one_line);
	std::string token;
	int num;

	while (iss >> token)
	{
        for (size_t i = 0; i < token.size(); ++i)
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


std::vector<std::pair<int, int> > PmergeMe::vec_makePairs()
{
	std::vector<std::pair<int, int> > vec_pair;
	size_t i = 0, n = vec_sort.size();
	vec_pair.reserve(n / 2);

	while (i + 1 < n)
	{
        if (vec_sort[i] < vec_sort[i + 1])
            vec_pair.push_back(std::make_pair(vec_sort[i], vec_sort[i + 1]));
        else
            vec_pair.push_back(std::make_pair(vec_sort[i + 1], vec_sort[i]));
		i += 2;
	}
	leftover = -1;
    if (i < n)
		leftover = vec_sort[i];
	return (vec_pair);
}

void PmergeMe::vec_insertionSort(std::vector<std::pair<int, int> >& vec_pair, \
								int left, int right)
{
	for (int i = left + 1; i <= right; ++i)
	{
        std::pair<int, int> key = vec_pair[i];
        int j = i - 1;
        while (j >= left && vec_pair[j].first > key.first)
		{
            vec_pair[j + 1] = vec_pair[j];
            --j;
        }
        vec_pair[j + 1] = key;
    }
}

void PmergeMe::vec_merge(std::vector<std::pair<int, int> >& vec_pair, \
							int left, int right, int mid) 
{
    int total_size = right - left + 1;
    if (vec_merge_buffer.size() < (size_t)total_size)
        vec_merge_buffer.resize(total_size);
    int i = left;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= right)
    {
        if (vec_pair[i].first < vec_pair[j].first) 
            vec_merge_buffer[k++] = vec_pair[i++];
        else
            vec_merge_buffer[k++] = vec_pair[j++];
    }
    while (i <= mid)
        vec_merge_buffer[k++] = vec_pair[i++];
    while (j <= right)
        vec_merge_buffer[k++] = vec_pair[j++];

    for (int idx = 0; idx < k; ++idx)
        vec_pair[left + idx] = vec_merge_buffer[idx];
}

void PmergeMe::vec_merge_sort(std::vector<std::pair<int, int> >& vec_pair, \
							int left, int right)
{
    if (right - left <= 48)
    {
        vec_insertionSort(vec_pair, left, right);
        return ;
    }
	if (left < right)
    {
        int mid = left + (right - left) / 2;

        vec_merge_sort(vec_pair, left, mid);
        vec_merge_sort(vec_pair, mid + 1, right);
        vec_merge(vec_pair, left, right, mid);
    }
}

std::vector<int> PmergeMe::vec_getJacobsthalInsertionOrder(size_t size)
{
	std::vector<int> jacob;
	jacob.reserve(size);

	if (size < 2)
		return (jacob.push_back(0), jacob);
	jacob.push_back(1);
	jacob.push_back(1);
    while (true)
    { 
        size_t next = jacob.back() + 2 * jacob[jacob.size() - 2];
		if (next >= size)
            break;
        jacob.push_back(next);
    }
	jacob[0] = 0;
	std::reverse(jacob.begin(), jacob.end());
    std::vector<bool> seen(size, false);
	for (size_t i = 0; i < jacob.size(); ++i)
	{
	    int idx = jacob[i];
	    seen[idx] = true;
	}
    for (size_t i = 2; i < size; ++i)
    {
        if (!seen[i])
        {
            jacob.push_back(i);
            seen[i] = true;
        }
    }
	return (jacob);
}

void PmergeMe::fordJohnsonSortVector(void)
{
	if (vec_sort.size() == 1)
		return ;
	std::vector<std::pair<int, int> > vec_pair = vec_makePairs();
	vec_merge_sort(vec_pair, 0, vec_pair.size() - 1);
	std::vector<int> jacob = vec_getJacobsthalInsertionOrder(vec_pair.size());
	std::vector<int>::iterator pos;

	vec_sort.clear();
	vec_sort.reserve(vec_pair.size() * 2 + 1);
    for (size_t i = 0; i < vec_pair.size(); ++i)
	{
        vec_sort.push_back(vec_pair[i].first);
	}
	for (size_t i = 0; i < jacob.size(); ++i)
	{
		int val = vec_pair[jacob[i]].second;
		pos = std::lower_bound(vec_sort.begin(), vec_sort.end(), val);
		vec_sort.insert(pos, val);
	}
	if (leftover != -1)
	{
		pos = std::lower_bound(vec_sort.begin(), vec_sort.end(), leftover);
		vec_sort.insert(pos, leftover);
	}
}
















// std::vector<std::pair<int, int> > PmergeMe::makePairs()
// {
// 	std::vector<std::pair<int, int> > vec_pair;
// 	size_t i = 0, n = vec_sort.size();
// 	vec_pair.reserve(n / 2);

// 	while (i + 1 < n)
// 	{
//         if (vec_sort[i] > vec_sort[i + 1])
//             vec_pair.push_back(std::make_pair(vec_sort[i], vec_sort[i + 1]));
//         else
//             vec_pair.push_back(std::make_pair(vec_sort[i + 1], vec_sort[i]));
// 		i += 2;
// 	}
// 	leftover = -1;
//     if (i < n)
// 		leftover = vec_sort[i];
// 	return (vec_pair);
// }

// void PmergeMe::vec_insertionSort(std::vector<std::pair<int, int> >& vec_pair, \
// 								int left, int right)
// {
// 	for (int i = left + 1; i <= right; ++i)
// 	{
//         std::pair<int, int> key = vec_pair[i];
//         int j = i - 1;
//         while (j >= left && vec_pair[j].first > key.first)
// 		{
//             vec_pair[j + 1] = vec_pair[j];
//             --j;
//         }
//         vec_pair[j + 1] = key;
//     }
// }

// void PmergeMe::vec_merge(std::vector<std::pair<int, int> >& vec_pair, \
// 							int left, int right, int mid) 
// {
//     int total_size = right - left + 1;
//     if (merge_buffer.size() < (size_t)total_size)
//         merge_buffer.resize(total_size);
//     int i = left;
//     int j = mid + 1;
//     int k = 0;
//     while (i <= mid && j <= right)
//     {
//         if (vec_pair[i].first < vec_pair[j].first) 
//             merge_buffer[k++] = vec_pair[i++];
//         else
//             merge_buffer[k++] = vec_pair[j++];
//     }
//     while (i <= mid)
//         merge_buffer[k++] = vec_pair[i++];
//     while (j <= right)
//         merge_buffer[k++] = vec_pair[j++];

//     for (int idx = 0; idx < k; ++idx)
//         vec_pair[left + idx] = merge_buffer[idx];
// }

// void PmergeMe::vec_merge_sort(std::vector<std::pair<int, int> >& vec_pair, \
// 							int left, int right)
// {
//     if (right - left <= 48)
//     {
//         vec_insertionSort(vec_pair, left, right);
//         return ;
//     }
// 	if (left < right)
//     {
//         int mid = left + (right - left) / 2;

//         vec_merge_sort(vec_pair, left, mid);
//         vec_merge_sort(vec_pair, mid + 1, right);
//         vec_merge(vec_pair, left, right, mid);
//     }
// }

// std::vector<int> PmergeMe::getJacobsthalInsertionOrder(size_t size)
// {
// 	std::vector<int> jacob;
// 	jacob.reserve(size);

// 	if (size < 2)
// 		return (jacob.push_back(0), jacob);
// 	jacob.push_back(1);
// 	jacob.push_back(1);
//     while (true)
//     { 
//         size_t next = jacob.back() + 2 * jacob[jacob.size() - 2];
// 		if (next >= size)
//             break;
//         jacob.push_back(next);
//     }
// 	jacob[0] = 0;
// 	std::reverse(jacob.begin(), jacob.end());
//     std::vector<bool> seen(size, false);
// 	for (size_t i = 0; i < jacob.size(); ++i)
// 	{
// 	    int idx = jacob[i];
// 	    seen[idx] = true;
// 	}
//     for (size_t i = 2; i < size; ++i)
//     {
//         if (!seen[i])
//         {
//             jacob.push_back(i);
//             seen[i] = true;
//         }
//     }
// 	return (jacob);
// }

// void PmergeMe::fordJohnsonSortVector(void)
// {
// 	if (vec_sort.size() == 1)
// 		return ;
// 	std::vector<std::pair<int, int> > vec_pair = makePairs();
// 	vec_merge_sort(vec_pair, 0, vec_pair.size() - 1);
// 	std::vector<int> jacob = getJacobsthalInsertionOrder(vec_pair.size());
// 	std::vector<int>::iterator pos;
// 	vec_sort.clear();
// 	vec_sort.reserve(vec_pair.size() * 2 + 1);
//     for (size_t i = 0; i < vec_pair.size(); ++i)
// 	{
//         vec_sort.push_back(vec_pair[i].first);
// 	}
// 	for (size_t i = 0; i < jacob.size(); ++i)
// 	{
// 		int val = vec_pair[jacob[i]].second;
// 		pos = std::lower_bound(vec_sort.begin(), vec_sort.end(), val);
// 		vec_sort.insert(pos, val);
// 	}
// 	if (leftover != -1)
// 	{
// 		pos = std::lower_bound(vec_sort.begin(), vec_sort.end(), leftover);
// 		vec_sort.insert(pos, leftover);
// 	}
// }






std::deque<std::pair<int, int> > PmergeMe::deque_makePairs()
{
	std::deque<std::pair<int, int> > deque_pair;
	size_t i = 0, n = vec_sort.size();

	while (i + 1 < n)
	{
		if (vec_sort[i] < vec_sort[i + 1])
			deque_pair.push_back(std::make_pair(vec_sort[i], vec_sort[i + 1]));
		else
			deque_pair.push_back(std::make_pair(vec_sort[i + 1], vec_sort[i]));
		i += 2;
	}
	leftover = -1;
	if (i < n)
		leftover = vec_sort[i];
	return (deque_pair);
}

void PmergeMe::deque_insertionSort(std::deque<std::pair<int, int> >& deque_pair, \
								int left, int right)
{
	for (int i = left + 1; i <= right; ++i)
	{
		std::pair<int, int> key = deque_pair[i];
		int j = i - 1;
		while (j >= left && deque_pair[j].first > key.first)
		{
			deque_pair[j + 1] = deque_pair[j];
			--j;
		}
		deque_pair[j + 1] = key;
	}
}

void PmergeMe::deque_merge(std::deque<std::pair<int, int> >& deque_pair, \
						int left, int right, int mid)
{
	int total_size = right - left + 1;
	if (deque_merge_buffer.size() < (size_t)total_size)
		deque_merge_buffer.resize(total_size);

	int i = left, j = mid + 1, k = 0;
	while (i <= mid && j <= right)
	{
		if (deque_pair[i].first < deque_pair[j].first)
			deque_merge_buffer[k++] = deque_pair[i++];
		else
			deque_merge_buffer[k++] = deque_pair[j++];
	}
	while (i <= mid)
		deque_merge_buffer[k++] = deque_pair[i++];
	while (j <= right)
		deque_merge_buffer[k++] = deque_pair[j++];

	for (int idx = 0; idx < k; ++idx)
		deque_pair[left + idx] = deque_merge_buffer[idx];
}

void PmergeMe::deque_merge_sort(std::deque<std::pair<int, int> >& deque_pair, \
							int left, int right)
{
	if (right - left <= 48) {
		deque_insertionSort(deque_pair, left, right);
		return;
	}
	if (left < right) {
		int mid = left + (right - left) / 2;
		deque_merge_sort(deque_pair, left, mid);
		deque_merge_sort(deque_pair, mid + 1, right);
		deque_merge(deque_pair, left, right, mid);
	}
}

std::deque<int> PmergeMe::deque_getJacobsthalInsertionOrder(size_t size)
{
	std::deque<int> jacob;

	if (size < 2)
		return (jacob.push_back(0), jacob);
	jacob.push_back(1);
	jacob.push_back(1);
	while (true)
	{
		size_t next = jacob.back() + 2 * jacob[jacob.size() - 2];
		if (next >= size)
			break;
		jacob.push_back(next);
	}
	jacob[0] = 0;
	std::reverse(jacob.begin(), jacob.end());
	std::vector<bool> seen(size, false);
	for (size_t i = 0; i < jacob.size(); ++i)
		seen[jacob[i]] = true;
	for (size_t i = 2; i < size; ++i)
	{
		if (!seen[i])
		{
			jacob.push_back(i);
			seen[i] = true;
		}
	}
	return (jacob);
}

void PmergeMe::fordJohnsonSortDeque()
{
	if (deque_sort.size() == 1)
		return;
	std::deque<std::pair<int, int> > deque_pair = deque_makePairs();
	deque_merge_sort(deque_pair, 0, deque_pair.size() - 1);
	std::deque<int> jacob = deque_getJacobsthalInsertionOrder(deque_pair.size());

	deque_sort.clear();
	for (size_t i = 0; i < deque_pair.size(); i++)
		deque_sort.push_back(deque_pair[i].first);

	for (size_t i = 0; i < jacob.size(); i++)
	{
		int val = deque_pair[jacob[i]].second;
		std::deque<int>::iterator pos = std::lower_bound(deque_sort.begin(), deque_sort.end(), val);
		deque_sort.insert(pos, val);
	}
	if (leftover != -1)
	{
		std::deque<int>::iterator pos = std::lower_bound(deque_sort.begin(), deque_sort.end(), leftover);
		deque_sort.insert(pos, leftover);
	}
}
























void PmergeMe::vec_print(void)
{
	std::vector<int>::iterator begin = vec_sort.begin();
	std::vector<int>::iterator end = vec_sort.end();

	if (vec_sort.size() < 10)
	{
		for (; begin + 1 != end; begin++)
			std::cout	<< *begin << ' ';
		std::cout	<< *begin << std::endl;
	}
	else
	{
		for (int i = 0; i < 10; i++)
			std::cout	<< *(begin + i) << ' ';
		std::cout	<< "[...]" << std::endl;
	}
	return ;
}

void PmergeMe::is_sort(void)
{
	for (size_t i = 1; i < deque_sort.size(); ++i)
	{
		if (deque_sort[i] < deque_sort[i - 1])
		{
			std::cout << "DequePmergeMe fail" << std::endl;
			return;
		}
	}
    for (size_t i = 1; i < vec_sort.size(); ++i)
	{
        if (vec_sort[i] < vec_sort[i - 1])
		{
            std::cout	<< "VecPmergeMe fail" << std::endl;
			return ;
        }
    }
	std::cout	<< "After: ";
	vec_print(); 
}

void PmergeMe::timer_print(double vec_elapsed, double deque_elapsed)
{
	std::cout << std::fixed << std::setprecision(5);
	std::cout	<< "Time to process a range of "
          		<< vec_sort.size()
          		<< " elements with std::vector : "
          		<< vec_elapsed << " us" << std::endl;
	std::cout	<< "Time to process a range of "
          		<< deque_sort.size()
          		<< " elements with std::deque : "
          		<< deque_elapsed << " us" << std::endl;
	return ;
}