#include "Map.hpp"
#include <map>

int main() {

	std::map<int, std::string> original;
	ft::map<int, std::string> copy;

    original.insert(std::make_pair(1, "string"));
    copy.insert(std::make_pair(1, "string"));


    original.insert(std::make_pair(2, "sstring"));
    copy.insert(std::make_pair(2, "sstring"));

	original.insert(std::make_pair(3, "ssstring"));
	copy.insert(std::make_pair(3, "ssstring"));

	original.insert(std::make_pair(0, "tring"));
	copy.insert(std::make_pair(0, "tring"));

    std::cout << "Original size = " << original.size() << "; Copy size = " << copy.size() << std::endl;


	std::map<int, std::string>::iterator min = original.begin();
	std::map<int, std::string>::iterator max = --original.end();

	std::cout << "Min first = " << min->first << "; Min second = " << min->second << std::endl;
	std::cout << "Max first = " << max->first << "; Max second = " << max->second << std::endl;


	ft::map<int, std::string>::iterator myMin = copy.getMin();
	ft::map<int, std::string>::iterator myMax = copy.getMax();

	std::cout << " My Min first = " << myMin->first << "; My Min second = " << myMin->second << std::endl;
	std::cout << "My Max first = " << myMax->first << "; My Max second = " << myMax->second << std::endl;

	myMin = copy.begin();
	++myMin;


	std::cout << myMin->first << std::endl;
	return (0);
}