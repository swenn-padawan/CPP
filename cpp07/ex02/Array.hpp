#pragma once
#include <cstring>
#include <stdexcept>
#include <stdlib.h>
#include <iostream>

template<typename T>
class Array{
	public:
		Array();
		Array(unsigned int n);
		Array(const Array<T> &copy);

		Array<T> &		operator=(const Array &src);
		const T&		operator[](unsigned int index) const;
		T&				operator[](unsigned int index);
		size_t			size() const;
		
		~Array();
	private:
		T		*array;		
		size_t	_size;
		
		
};
template <typename T>
std::ostream & operator << (std::ostream & ostream, const Array<T> & array);

# define EXCEPTION(n, m)	class n:public std::exception { inline const char *what() const throw() { return (m) ; } ; }

EXCEPTION(OutofRangeException, "You are trying to reach an out of range index");

#include "Array.tpp"
