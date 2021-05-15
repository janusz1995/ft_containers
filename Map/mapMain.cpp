#include "Map.hpp"
#include <map>
#include "../utils/utilsMap.hpp"

template <class Key, class Value>
void printMapAndColor(ft::map<Key, Value> &my) {
    std::cout << YELLOW << "My Map " << NC << " --------->>> ";
    for (typename ft::map<Key, Value>::iterator it = my.begin();  it != my.end() ; it++) {
        std::cout << " | " << GREEN << it->first << NC;
        std::cout << " : " << GREEN << it->second << NC;
        std::cout << "; Color = " << (it.getColor() ? "BLACK" : "RED");
    }
    std::cout << " |\n";
}

int main() {

    std::map<int, char> original;
    ft::map<int, char> copy;

    for (int i = 0; i < 5; ++i) {
        original.insert(std::make_pair(i, i + 97));
        copy.insert(std::make_pair(i, i + 97));

    }



    printMethod("MAP(first, last)");

    std::map<int, char> original1(original.begin(), original.end());
    ft::map<int, char> copy1(copy.begin(), copy.end());

    emptyMaps(original, copy);
    sizeMaps(original1, copy1);
    printMaps(original1, copy1);



	printMethod("EMPTY");

	emptyMaps(original, copy);
	sizeMaps(original, copy);



    printMethod("MAX SIZE");

    std::cout << BLUE << "Original Map " << NC << " --->>> " << LIGHT_PURPLE << original.max_size() << "\n" << NC;
    std::cout << YELLOW << "My Map " << NC << " --------->>> " << LIGHT_PURPLE << copy.max_size() << "\n" << NC;



	printMethod("SIZE");

    emptyMaps(original, copy);
	sizeMaps(original, copy);
	printMaps(original, copy);



    printMethod("ERASE");

    original.erase(original.begin());
    copy.erase(copy.begin());

    emptyMaps(original, copy);
    sizeMaps(original, copy);
    printMaps(original, copy);



	printMethod("INSERT");


    for (int i = 5; i < 10; ++i) {
        original.insert(std::make_pair(i, i + 97));
        copy.insert(std::make_pair(i, i + 97));
    }
    emptyMaps(original, copy);
    sizeMaps(original, copy);
    printMaps(original, copy);



    printMethod("FIND");

    emptyMaps(original, copy);
    sizeMaps(original, copy);
    printMaps(original, copy);


    std::map<int, char>::iterator it = original.find(4);
    ft::map<int, char>::iterator myIt = copy.find(4);

    std::map<int, char>::iterator it1 = original.find(4);
    ft::map<int, char>::iterator myIt1 = copy.find(4);

    std::map<int, char>::iterator it2 = original.find(7);
    ft::map<int, char>::iterator myIt2 = copy.find(7);

    std::cout << BLUE << "Original Map " << NC << " --->>> ";
    while (it != original.end()) {
        std::cout << " | " << GREEN << it->first << NC << " : " << GREEN << it->second << NC;
        it++;
    }
    std::cout << " |\n";

    std::cout << YELLOW << "My Map " << NC << " --------->>> ";
    while (myIt != copy.end()) {
        std::cout << " | " << GREEN << myIt->first << NC << " : " << GREEN << myIt->second << NC;
        myIt++;
    }
    std::cout << " |\n";



    printMethod("ERASE");

    original.erase(it1, it2);
    copy.erase(myIt1, myIt2);
//    original.erase(it1,original.end());
//    copy.erase(myIt1, copy.end());
    emptyMaps(original, copy);
    sizeMaps(original, copy);
    printMaps(original, copy);

    original.erase(3);
    copy.erase(3);

    emptyMaps(original, copy);
    sizeMaps(original, copy);
    printMaps(original, copy);

    original.erase(original.begin());
    copy.erase(copy.begin());

    emptyMaps(original, copy);
    sizeMaps(original, copy);
    printMaps(original, copy);



    printMethod("LOWER BOUND");

	it1 = original.lower_bound(5);
	myIt1 = copy.lower_bound(5);

    std::cout << BLUE <<  "Original lower bound (Key = 5) points to: " << GREEN << it1->first << NC << " => " << GREEN << it1->second << NC << "\n";
    std::cout << YELLOW << "My lower bound (Key = 5) points to:       " << GREEN << myIt1->first << NC << " => " << GREEN << myIt1->second << NC << "\n";
    emptyMaps(original, copy);
    sizeMaps(original, copy);
    printMaps(original, copy);



	printMethod("UPPER BOUND");

	it1 = original.upper_bound(2);
	myIt1 = copy.upper_bound(2);

	std::cout << BLUE <<  "Original upper bound (Key = 2) points to: " << GREEN << it1->first << NC << " => " << GREEN << it1->second << NC << "\n";
	std::cout << YELLOW << "My upper bound (Key = 2) points to:       " << GREEN << myIt1->first << NC << " => " << GREEN << myIt1->second << NC << "\n";
    emptyMaps(original, copy);
	sizeMaps(original, copy);
	printMaps(original, copy);



	printMethod("EQUAL RANGE");

	std::pair<std::map<int, char>::iterator,std::map<int, char>::iterator> pair = original.equal_range(7);
	std::pair<ft::map<int, char>::iterator, ft::map<int, char>::iterator> myPair = copy.equal_range(7);

    std::cout << BLUE <<  "Original lower bound (Key = 7) points to: " << GREEN << pair.first->first << NC << " => " << GREEN << pair.first->second << NC << "\n";
    std::cout << BLUE <<  "Original upper bound (Key = 7) points to: " << GREEN << pair.second->first << NC << " => " << GREEN << pair.second->second << NC << "\n";
    std::cout << YELLOW << "My lower bound (Key = 7) points to:       " << GREEN << myPair.first->first << NC << " => " << GREEN << myPair.first->second << NC << "\n";
    std::cout << YELLOW << "My upper bound (Key = 7) points to:       " << GREEN << myPair.second->first << NC << " => " << GREEN << myPair.second->second << NC << "\n";



    printMethod("COUNT (KEY: 7 AND 1)");

    std::cout << BLUE <<  "Original count (Key = 7): " << GREEN << original.count(7) << NC << "\n";
    std::cout << YELLOW << "My count (Key = 7):       " << GREEN << copy.count(7) << NC << "\n";

    std::cout << BLUE <<  "Original count (Key = 1): " << GREEN << original.count(1) << NC << "\n";
    std::cout << YELLOW << "My count (Key = 1):       " << GREEN << copy.count(1) << NC << "\n";



    printMethod("OPERATOR[] (KEY: 7 AND 1)");

    std::cout << BLUE <<  "Original count (Key = 7): " << GREEN << original[7] << NC << "\n";
    std::cout << YELLOW << "My count (Key = 7):       " << GREEN << copy[7] << NC << "\n";

    std::cout << BLUE <<  "Original count (Key = 1): " << GREEN << original[1] << NC << "\n";
    std::cout << YELLOW << "My count (Key = 1):       " << GREEN << copy[1] << NC << "\n";



    printMethod("REVERSE ITERATOR");

    emptyMaps(original, copy);
    sizeMaps(original, copy);
    reversePrintMaps(original, copy);



    printMethod("CONST REVERSE ITERATOR");

    emptyMaps(original, copy);
    sizeMaps(original, copy);
    constPrintMaps(original, copy);



    printMethod("CONST ITERATOR");

    emptyMaps(original, copy);
    sizeMaps(original, copy);
    constReversePrintMaps(original, copy);



    printMethod("RELATIONAL OPERATORS");

    ft::map<int, char> copy2(copy);

    std::cout << RED << "*****" << CYAN << " Operator == " << RED << "*****\n";
    if (copy == copy2)
        std::cout << PURPLE << "Maps EQUALS\n";


    std::cout << RED << "*****" << CYAN << " Operator <= " << RED << "*****\n";
    if (copy2 <= copy)
        std::cout << PURPLE << "Map 1 more or EQUAL Map 2\n";

    std::cout << RED << "*****" << CYAN << " Operator >= " << RED << "*****\n";
    if (copy2 >= copy)
        std::cout << PURPLE << "Map 2 more or EQUAL Map 1\n";

    copy2.erase(1);

    std::cout << RED << "*****" << CYAN << " Operator != " << RED << "*****\n";
    if (copy2 != copy)
        std::cout << PURPLE << "Map NOT EQUALS\n";

    std::cout << RED << "*****" << CYAN << " Operator < " << RED << "*****\n";
    if (copy2 < copy)
        std::cout << PURPLE << "Map 1 more than Map 2\n";

    copy.erase(1);
    copy.erase(2);

    std::cout << RED << "*****" << CYAN << " Operator > " << RED << "*****\n";
    if (copy2 > copy)
        std::cout << PURPLE << "Map 2 more than Map 1\n";



    printMethod("SWAP");

    printTwoMaps(copy, copy2);
    copy.swap(copy2);
    printTwoMaps(copy, copy2);



    printMethod("CLEAR");

	original.clear();
	copy.clear();

    emptyMaps(original, copy);
	sizeMaps(original, copy);
    printMaps(original, copy);

	return (0);
}
