#pragma once

#include <stdint.h>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <algorithm>

class Span{
	public:
		Span();
		Span(unsigned int n);
		~Span();
		Span &operator=(const Span& copy);
		Span(const Span& src);
		void	addNumber(int nb);
		void addNumber(std::vector<int>::const_iterator begin,
			std::vector<int>::const_iterator end);
		uint64_t	getSize() const;
		std::vector<int>	getData() const;
		int 	shortestSpan();
		int 	longestSpan();
	private:
		uint64_t			_size;
		std::vector<int>	_data;
};

std::ostream & operator << (std::ostream & ostream, const Span& toPrint);

