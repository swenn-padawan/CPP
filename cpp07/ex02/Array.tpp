#pragma once
#include "Array.hpp"

template<typename T>
Array<T>::Array(void): data(NULL), size(0){}

template<typename T>
Array<T>::Array(unsigned int n): data(NULL), size(0){
	if (n == 0)
		return;
	data = new T[n]();
	size = n;
	for (int i = 0; i < n; i++)
		data[i] = 0;
}

template<typename T>
Array<T>::Array(const Array &src) {
  if (this != &src)
    *this = src;
}

template<typename T>
Array<T>::~Array(void) {
	delete[] data;
}

template<typename T>
Array<T> &Array<T>::operator=(Array const &src) {
  if (this == &src)
    return (*this);
  return (*this);
}
