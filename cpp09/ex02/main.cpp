#include "PmergeMe.hpp"
#include <iostream>
#include <sys/time.h>

template<typename Container>
void	printContainer(Container &container, const std::string &start){
	std::cout << start << std::endl;
	for (size_t i = 0; i < container.size(); i++){
		std::cout << container[i] << " ";
	}
}

template<typename Container>
double timeSort(const Container& container, Container &sorted)
{
	struct timeval start;
	struct timeval end;

	gettimeofday(&start, NULL);
	sorted = PmergeMe<Container>::fordJohnsonSort(container);
	gettimeofday(&end, NULL);

	double start_us = start.tv_sec * 1e6 + start.tv_usec;
	double end_us = end.tv_sec * 1e6 + end.tv_usec;
	return (end_us - start_us);
}

int main(int argc, char **argv)
{
	if (argc < 2){
		std::cerr << "Usage: " << argv[0] << " [integers > 0...]" << std::endl;
		return (1);
	}
	std::vector<int>	vec;
	std::deque<int>		deq;
	for (int i = 1; i < argc; i++){
		int num = std::atoi(argv[i]);
		if (num <= 0) {
			std::cerr << "Error: Only integers > 0 allowed" << std::endl;
			return (1);
		}
		vec.push_back(num);
		deq.push_back(num);
	}
	printContainer(vec, "Before: ");
	double time1 = timeSort(vec, vec);
	double time2 = timeSort(deq, deq);
	printContainer(vec, "\nAfter:  ");

	std::cout << "\nTime to process a range of " << vec.size() 
				<< " elements with std::vector<int>: " << time1 << " us" << std::endl;
	std::cout << "Time to process a range of " << deq.size() 
				<< " elements with std::deque<int>: " << time2 << " us" << std::endl;
	
}
