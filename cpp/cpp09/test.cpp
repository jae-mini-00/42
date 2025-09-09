#include <vector>

void insertionSort(std::vector<int>& vec, int left, int right)
{
    for (int i = left + 1; i <= right; ++i) {
        int key = vec[i];
        int j = i - 1;
        while (j >= left && vec[j] > key) {
            vec[j + 1] = vec[j];
            --j;
        }
        vec[j + 1] = key;
    }
}

void merge(std::vector<int>& vec, int left, int mid, int right) 
{
    std::vector<int> leftPart(vec.begin() + left, vec.begin() + mid + 1);
    std::vector<int> rightPart(vec.begin() + mid + 1, vec.begin() + right + 1);

    int i = 0, j = 0, k = left;

    while (i < leftPart.size() && j < rightPart.size()) {
        if (leftPart[i] <= rightPart[j]) {
            vec[k++] = leftPart[i++];
        } else {
            vec[k++] = rightPart[j++];
        }
    }

    while (i < leftPart.size()) {
        vec[k++] = leftPart[i++];
    }

    while (j < rightPart.size()) {
        vec[k++] = rightPart[j++];
    }
}

#include <iostream>

int main ()
{
    std::vector<int> a;

    a.push_back(10);
    a.push_back(1);
    a.push_back(110);
    a.push_back(150);
    a.push_back(13);
    a.push_back(5);
    a.push_back(12);
    a.push_back(19);
    for (int i = 0; i < a.size(); i++)
        std::cout   << a[i] << ' ';
    std::cout   << std::endl;

    insertionSort(a, 0, a.size() - 1);

    for (int i = 0; i < a.size(); i++)
        std::cout   << a[i] << ' ';
    std::cout   << std::endl;
}