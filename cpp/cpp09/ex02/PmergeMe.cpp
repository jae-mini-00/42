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



std::vector<std::pair<int, int> > PmergeMe::makePairs()
{
	std::vector<std::pair<int, int> > vec_pair;
	int a;
	int b;
	int i = 0;

	while (i + 1 < static_cast<int>(vec_sort.size()))
	{
		a = vec_sort[i];
		b = vec_sort[i + 1];
        if (a > b)
            vec_pair.push_back(std::make_pair(a, b));
        else
            vec_pair.push_back(std::make_pair(b, a));
		i += 2;
	}
	leftover = -1;
    if (i < static_cast<int>(vec_sort.size()))
		leftover = vec_sort[i];
	return (vec_pair);
}

void PmergeMe::vec_insertionSort(std::vector<std::pair<int, int> >& vec_pair, \
								int left, int right)
{
	for (int i = left + 1; i <= right; ++i)
	{
        std::pair<int, int> key = vec_pair[i];
		int key_first = key.first;
        int j = i - 1;
        while (j >= left && vec_pair[j].first > key_first) {
            vec_pair[j + 1] = vec_pair[j];
            --j;
        }
        vec_pair[j + 1] = key;
    }
}

void PmergeMe::vec_merge(std::vector<std::pair<int, int> >& vec_pair, \
							int left, int right, int mid) 
{
    std::vector<std::pair<int, int> > rightPart(vec_pair.begin() + mid + 1, vec_pair.begin() + right + 1);
    std::vector<std::pair<int, int> > leftPart(vec_pair.begin() + left, vec_pair.begin() + mid + 1);
	
    size_t i = 0, j = 0, k = left;

    while (i < leftPart.size() && j < rightPart.size()) 
	{
        if (leftPart[i].first < rightPart[j].first)
            vec_pair[k++] = leftPart[i++];
		else
            vec_pair[k++] = rightPart[j++];
	}
	while (i < leftPart.size())
        vec_pair[k++] = leftPart[i++];
    while (j < rightPart.size())
		vec_pair[k++] = rightPart[j++];
}

void PmergeMe::vec_merge_sort(std::vector<std::pair<int, int> >& vec_pair, \
							int left, int right)
{
    const int flag = 10;
    if (right - left <= flag)
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
#include <set>

std::vector<size_t> PmergeMe::getJacobsthalInsertionOrder(size_t size) //볼부분
{
    std::vector<size_t> order;
    std::set<size_t> seen;

    std::vector<size_t> jacob;
    size_t j0 = 0, j1 = 1;
    jacob.push_back(j1);

    while (j1 < size)
	{
        size_t j2 = j1 + 2 * j0;
        if (j2 >= size)
            break;
        jacob.push_back(j2);
        j0 = j1;
        j1 = j2;
    }
    for (size_t i = jacob.size(); i-- > 0;)
	{
        size_t idx = jacob[i];
        if (idx < size && seen.find(idx) == seen.end()) {
            order.push_back(idx);
            seen.insert(idx);
        }
    }
    for (size_t i = 0; i < size; ++i)
	{
        if (seen.find(i) == seen.end()) {
            order.push_back(i);
            seen.insert(i);
        }
    }

    return order;
}

std::vector<int> PmergeMe::fordJohnsonSortVector(void) // 볼부분
{
	std::vector<std::pair<int, int> > vec_pair = makePairs();
	vec_merge_sort(vec_pair, 0, vec_pair.size() - 1);
	
	std::vector<int> result;
    for (size_t i = 0; i < vec_pair.size(); ++i)
        result.push_back(vec_pair[i].first);
    std::vector<size_t> insertOrder = getJacobsthalInsertionOrder(vec_pair.size());

	for (size_t i = 0; i < insertOrder.size(); ++i)
	{
    	size_t idx = insertOrder[i];
    	if (idx >= vec_pair.size())
	        continue;

	    int small = vec_pair[idx].second;

	    std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), small);
	    result.insert(pos, small);
	}
	if (leftover != -1)
	{
    	std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), leftover);
    	result.insert(pos, leftover);
	}
	vec_sort = result;
	std::cout	<< "After: ";
	print();
	return (vec_sort);
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