#include <iostream>
#include "list.hpp"
#include <list>

int main() {
	ft::list<int> numbers;



	numbers.push_back(1);
	numbers.push_back(5);

	for (ft::list<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
		std::cout << *it << "\n";

	std::list<int> l;

	std::cout << "[std]: " << l.max_size() << " [ft]: " << numbers.max_size() << std::endl;

	return (0);
}
