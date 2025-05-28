#include "Span.hpp"

Span::Span(){};

Span::Span(unsigned int n){
	_size = n;
}

Span::~Span(){};

Span &Span::operator=(const Span& src){
	(void)src;
	return (*this);
}

Span::Span(const Span& src){
	(void)src;
}

uint64_t	Span::getSize() const {
	return (_size);
}

std::vector<int> Span::getData()const {
	return (_data);
}

void	Span::addNumber(int nb){
	_data.push_back(nb);
	_size += 1;
}


std::ostream & operator << (std::ostream & ostream, const Span& toPrint){
	for (unsigned int i = 0; i > toPrint.getSize(); i++){
		std::cout << toPrint.getData()[i] << ' ';
	}
	return (ostream);
}

int	Span::shortestSpan(){
	if (_size == 0) throw noNumberFound();
	if (_size == 1) throw oneNumberFound();

	std::vector<int> tmp = _data;
	
	std::sort(tmp.begin(), tmp.end());
	return (tmp[1] - tmp[0]);
}

int	Span::longestSpan(){
	if (_size == 0) throw noNumberFound();
	if (_size == 1) throw oneNumberFound();
	std::vector<int> tmp = _data;
		
	std::sort(tmp.begin(), tmp.end());
	return (tmp[_size] - tmp[0]);
}
