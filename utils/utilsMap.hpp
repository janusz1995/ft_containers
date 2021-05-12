#ifndef UTILSMAP_HPP
#define UTILSMAP_HPP
#include "utils.hpp"
#include "../Map/Map.hpp"
#include <map>

template<class Key, class Value>
void printMaps(std::map<Key, Value> &original, ft::map<Key, Value> &my) {

	std::cout << BLUE << "Original Map " << NC << " --->>> ";
	for (typename std::map<Key, Value>::iterator it = original.begin();  it != original.end() ; it++) {
		std::cout << " | " << GREEN << it->first << NC << " : " << GREEN << it->second << NC;
	}
	std::cout << " |\n";

	std::cout << YELLOW << "My Map " << NC << " --------->>> ";
	for (typename ft::map<Key, Value>::iterator it = my.begin();  it != my.end() ; it++) {
		std::cout << " | " << GREEN << it->first << NC << " : " << GREEN << it->second << NC;
	}
	std::cout << " |\n";
}

template<class Key, class Value>
void emptyMaps(std::map<Key, Value> &original, ft::map<Key, Value> &copy) {
	isEmpty("Original Map is Empty: ", original.empty(), ORIGINAL);
	isEmpty("My Map is Empty:       ", copy.empty(), MYCOLOR);
}

template<class Key, class Value>
void sizeMaps(std::map<Key, Value> &original, ft::map<Key, Value> &copy) {
	printSize("Original Map Size: ", original.size(), ORIGINAL);
	printSize("My Map Size:       ", copy.size(), MYCOLOR);
}

#endif
