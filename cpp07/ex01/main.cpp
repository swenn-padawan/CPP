#include <iostream>
#include <string>
#include "iter.hpp"

// Pour les int
void increment(int &x) { x += 1; }
void print_int(const int &x) { std::cout << x << " "; }
void copy_print_int(int x) { std::cout << "(" << x << ") "; }

// Pour les strings
void append_exclam(std::string &s) { s += "!"; }
void print_str(const std::string &s) { std::cout << s << " "; }
void copy_print_str(std::string s) { std::cout << "(" << s << ") "; }

// Pour un type personnalisé
struct Point {
	int x, y;
};
void move_right(Point &p) { p.x += 1; }
void print_point(const Point &p) { std::cout << "(" << p.x << ", " << p.y << ") "; }
void copy_print_point(Point p) { std::cout << "[" << p.x << "," << p.y << "] "; }

int main() {
	std::cout << "=== Test 1 : Tableau d'int ===\n";
	int nums[] = {1, 2, 3, 4, 5};
	iter(nums, 5, print_int);
	std::cout << "\n-> Après increment : ";
	iter(nums, 5, increment);
	iter(nums, 5, print_int);
	std::cout << "\n-> En copie : ";
	iter(nums, 5, copy_print_int);
	std::cout << "\n\n";

	std::cout << "=== Test 2 : Tableau vide ===\n";
	int empty[] = {};
	iter(empty, 0, print_int); // Ne doit rien faire
	std::cout << "\n\n";

	std::cout << "=== Test 3 : Un seul élément ===\n";
	int solo[] = {42};
	iter(solo, 1, print_int);
	std::cout << " -> Après ++ : ";
	iter(solo, 1, increment);
	iter(solo, 1, print_int);
	std::cout << "\n\n";

	std::cout << "=== Test 4 : std::string ===\n";
	std::string words[] = {"hello", "world"};
	iter(words, 2, print_str);
	std::cout << "\n-> Avec modification : ";
	iter(words, 2, append_exclam);
	iter(words, 2, print_str);
	std::cout << "\n-> En copie : ";
	iter(words, 2, copy_print_str);
	std::cout << "\n\n";

	std::cout << "=== Test 5 : Struct perso ===\n";
	Point points[] = {{1,2}, {3,4}, {5,6}};
	iter(points, 3, print_point);
	std::cout << "\n-> Move right : ";
	iter(points, 3, move_right);
	iter(points, 3, print_point);
	std::cout << "\n-> En copie : ";
	iter(points, 3, copy_print_point);
	std::cout << "\n";

	return 0;
}
