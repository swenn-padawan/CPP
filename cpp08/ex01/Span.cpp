#include "Span.hpp"
#include <algorithm>
#include <stdexcept>
#include <iostream>

Span::Span() {
	_size = 0;
}

Span::Span(unsigned int n) {
	_size = n;
}

Span::~Span() {}

Span::Span(const Span& src) {
	*this = src;
}

Span &Span::operator=(const Span& src) {
	if (this != &src) {
		_data = src._data;
		_size = src._size;
	}
	return *this;
}

uint64_t Span::getSize() const {
	return _size;
}

std::vector<int> Span::getData() const {
	return _data;
}

void Span::addNumber(int nb) {
	if (_data.size() >= _size)
		throw std::runtime_error("Span is full");
	_data.push_back(nb);
}

void Span::addNumber(std::vector<int>::const_iterator start,
		std::vector<int>::const_iterator end)
{
    if (std::distance(start, end) + _data.size() > _size)
        throw std::runtime_error("no slot left");
    _data.insert(_data.end(), start, end);
}

std::ostream &operator<<(std::ostream &os, const Span& toPrint) {
	std::vector<int> data = toPrint.getData();
	for (std::vector<int>::size_type i = 0; i < data.size(); ++i) {
		os << data[i] << ' ';
	}
	return os;
}

int Span::shortestSpan() {
	if (_data.size() < 2)
		throw std::runtime_error("Not enough elements");

	std::vector<int> tmp = _data;
	std::sort(tmp.begin(), tmp.end());

	int min = tmp[1] - tmp[0];
	for (std::vector<int>::size_type i = 1; i < tmp.size() - 1; ++i) {
		int diff = tmp[i + 1] - tmp[i];
		if (diff < min)
			min = diff;
	}
	return min;
}

int Span::longestSpan() {
	if (_data.size() < 2)
		throw std::runtime_error("Not enough elements");

	int min = *std::min_element(_data.begin(), _data.end());
	int max = *std::max_element(_data.begin(), _data.end());

	return max - min;
}
