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

	ft::map<int, std::string>::iterator min = copy.getMin();
	ft::map<int, std::string>::iterator max = copy.getMax();

	std::cout << "Min first = " << min->first << "; Min second = " << min->second << std::endl;
	std::cout << "Max first = " << max->first << "; Max second = " << max->second << std::endl;

	return (0);
}