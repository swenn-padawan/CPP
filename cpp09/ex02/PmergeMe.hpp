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
	private:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &src);
		PmergeMe &operator=(const PmergeMe &src);

		static Container fordJohnsonSort(const Container& input);

		static std::vector<size_t> generateJacobsthalIndices(size_t n) {
		std::vector<size_t> sequence;
		std::vector<bool> seen(n, false);
		size_t j0 = 0, j1 = 1;
		while (j1 < n) {
			if (!seen[j1]) {
				sequence.push_back(j1);
				seen[j1] = true;
			}
			size_t jn = j1 + 2 * j0;
			j0 = j1;
			j1 = jn;
		}
		for (size_t i = 0; i < n; ++i) {
			if (!seen[i])
				sequence.push_back(i);
		}
		return sequence;
	}

	static void binaryInsert(Container& sorted, const typename Container::value_type& val) {
		typename Container::iterator it = std::lower_bound(sorted.begin(), sorted.end(), val);
		sorted.insert(it, val);
	}
};

template<typename Container>
Container PmergeMe<Container>::fordJohnsonSort(const Container& input) {
	if (input.size() <= 1)
		return input;

	Container smalls;
	Container bigs;
	typename Container::value_type pending;
	bool hasPending = (input.size() % 2 != 0);

	// Step 1: Split into pairs
	for (size_t i = 0; i + 1 < input.size(); i += 2) {
		if (input[i] < input[i + 1]) {
			smalls.push_back(input[i]);
			bigs.push_back(input[i + 1]);
		} else {
			smalls.push_back(input[i + 1]);
			bigs.push_back(input[i]);
		}
	}
	if (hasPending)
		pending = input.back();

	// Step 2: Recursively sort the bigs
	Container sorted = fordJohnsonSort(bigs);

	// Step 3: Insert smalls according to Jacobsthal
	std::vector<size_t> insertOrder = generateJacobsthalIndices(smalls.size());
	for (size_t i = 0; i < insertOrder.size(); ++i) {
		if (insertOrder[i] < smalls.size()) {
			binaryInsert(sorted, smalls[insertOrder[i]]);
		}
	}

	// Step 4: Insert pending if necessary
	if (hasPending)
		binaryInsert(sorted, pending);

	return sorted;
}
