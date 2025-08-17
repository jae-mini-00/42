#ifndef  ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>


template <typename T>
class Array
{
    private :
        unsigned int total_index;
        T* array;

        T* new_array(unsigned int n) const;
    public :
        // 생성자, 소멸자
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        ~Array();
        // 매서드
        unsigned int size() const;
        // 연산자 오버로드
        Array& operator=(const Array& other);
        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;

};

// 생성자, 소멸자 구현

template <typename T>
Array<T>::Array() : total_index(0), array(NULL) { std::cout	<< "Array default constructor called" << std::endl; }

template <typename T>
Array<T>::Array(unsigned int n) : total_index(n)
{
    std::cout   << "Array constructor called" << std::endl;
    array = new_array(n);
}

template <typename T>
Array<T>::Array(const Array& other)
{
	std::cout   << "Array copy constructor called" << std::endl;
	this->array = new_array(other.size());
	for (unsigned int i = 0; i < other.size(); i++)
		this->array[i] = other.array[i];
	this->total_index = other.size();
}

template <typename T>
Array<T>::~Array()
{
	std::cout << "Array destructor called" << std::endl;
	delete[]  (array);
}

// 오퍼레이터 연산자 구현

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
	std::cout   << "Array copy assignment operator called" << std::endl;
	if (this != &other)
	{
		delete[] (this->array);
		this->array = new_array(other.size());
		for (unsigned int i = 0; i < other.size(); i++)
			this->array[i] = other.array[i];
		this->total_index = other.size();
	}
	return (*this);
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= total_index)
        throw std::out_of_range("Index out of bounds");
    return array[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
    if (index >= total_index)
        throw std::out_of_range("Index out of bounds");
    return array[index];
}

// 매서드 구현

template <typename T>
unsigned int Array<T>::size() const
{
	return (this->total_index);
}

template <typename T>
T* Array<T>::new_array(unsigned int n) const
{
    return (new T[n]());
}
#endif