#pragma once

#include <deque>
#include <vector>
#include <algorithm>
#include <numeric>

template<typename Container> class PmergeMe{
	public:
	static Container sort(const Container& container) {
		return fordJohnsonSort(container);
	}
	static Container fordJohnsonSort(const Container& input) {
		// Algo
		return input;
	}
	private:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &src);
		PmergeMe &operator=(const PmergeMe &src);
};
