#include "Map.hpp"
#include <map>

int main() {

	std::map<int, std::string> original;
	ft::map<int, std::string> copy;

    original.insert(std::make_pair(1, "string"));
    copy.insert(std::make_pair(1, "string"));


    original.insert(std::make_pair(2, "sstring"));
    copy.insert(std::make_pair(2, "sstring"));

    std::cout << "Original size = " << original.size() << "; Copy size = " << copy.size() << std::endl;

	return (0);
}