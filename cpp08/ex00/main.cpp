#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

// Couleurs ANSI (fonctionne dans la plupart des terminaux)
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

template <typename T>
void testEasyFind(const std::string& name, T &container, int value) {
	std::cout << CYAN << "Testing in " << name << " for value " << value << ": " << RESET;
	typename T::iterator it = easyfind(container, value);
	if (it != container.end())
		std::cout << GREEN << "Found -> " << *it << RESET << std::endl;
	else
		std::cout << RED << "Not found" << RESET << std::endl;
}

int main() {
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);
	lst.push_back(50);

	std::deque<int> deq;
	deq.push_back(100);
	deq.push_back(200);
	deq.push_back(300);

	std::vector<int> emptyVec;

	std::cout << YELLOW << "--- VECTOR TESTS ---" << RESET << std::endl;
	testEasyFind("vector", vec, 1);   // début
	testEasyFind("vector", vec, 3);   // milieu
	testEasyFind("vector", vec, 5);   // fin
	testEasyFind("vector", vec, 42);  // absent

	std::cout << YELLOW << "\n--- LIST TESTS ---" << RESET << std::endl;
	testEasyFind("list", lst, 10);    // début
	testEasyFind("list", lst, 30);    // milieu
	testEasyFind("list", lst, 50);    // fin
	testEasyFind("list", lst, 99);    // absent

	std::cout << YELLOW << "\n--- DEQUE TESTS ---" << RESET << std::endl;
	testEasyFind("deque", deq, 100);  // début
	testEasyFind("deque", deq, 200);  // milieu
	testEasyFind("deque", deq, 300);  // fin
	testEasyFind("deque", deq, -1);   // absent

	std::cout << YELLOW << "\n--- EMPTY VECTOR TEST ---" << RESET << std::endl;
	testEasyFind("empty vector", emptyVec, 1);  // vide

	return 0;
}
