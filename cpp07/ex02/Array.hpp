#pragma once

template<typename T>
class Array{
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &copy);
		Array &operator=(const Array &src);
		~Array();
	private:
		T	*array;		
		
		
};

#include "Array.tpp"
