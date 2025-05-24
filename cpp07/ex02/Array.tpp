#pragma once
#include "Array.hpp"

template<typename T>
Array<T>::Array(void) {
	
}

template<typename T>
Array<T>::Array(unsigned int n) {
}

template<typename T>
Array<T>::Array(const Array &src) {
  if (this != &src)
    *this = src;
}

template<typename T>
Array<T>::~Array(void) {
}

template<typename T>
Array<T> &Array<T>::operator=(Array const &src) {
  if (this == &src)
    return (*this);
  return (*this);
}
