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


//    original.insert(std::make_pair(2, "sstring"));
//    copy.insert(std::make_pair(2, "sstring"));
//
//    original.insert(std::make_pair(3, "ssstring"));
//    copy.insert(std::make_pair(3, "ssstring"));
//
//    original.insert(std::make_pair(0, "tring"));
//    copy.insert(std::make_pair(0, "tring"));


//    std::map<int, std::string> original;
//    ft::map<int, std::string> copy;
//
//    original.insert(std::make_pair(1, "string"));
//    copy.insert(std::make_pair(1, "string"));
//
//
//    original.insert(std::make_pair(2, "sstring"));
//    copy.insert(std::make_pair(2, "sstring"));
//
//	original.insert(std::make_pair(3, "ssstring"));
//	copy.insert(std::make_pair(3, "ssstring"));
//
//	original.insert(std::make_pair(0, "tring"));
//	copy.insert(std::make_pair(0, "tring"));

    std::cout << "Original size = " << original.size() << "; Copy size = " << copy.size() << std::endl;

    std::map<int, char>::iterator min = original.begin();
    std::map<int, char>::iterator max = --original.end();
//	std::map<int, std::string>::iterator min = original.begin();
//	std::map<int, std::string>::iterator max = --original.end();

	std::cout << "Min first = " << min->first << "; Min second = " << min->second << std::endl;
	std::cout << "Max first = " << max->first << "; Max second = " << max->second << std::endl;

    ft::map<int, char>::iterator myMin = copy.getMin();
    ft::map<int, char>::iterator myMax = copy.getMax();
//	ft::map<int, std::string>::iterator myMin = copy.getMin();
//	ft::map<int, std::string>::iterator myMax = copy.getMax();

	std::cout << " My Min first = " << myMin->first << "; My Min second = " << myMin->second << std::endl;
	std::cout << "My Max first = " << myMax->first << "; My Max second = " << myMax->second << std::endl;

	myMin = copy.begin();
	++myMin;

	std::cout << myMin->first << std::endl;


	printMethod("EMPTY");

	emptyMaps(original, copy);
	sizeMaps(original, copy);



	printMethod("SIZE");

	sizeMaps(original, copy);
	printMaps(original, copy);
    printMapAndColor(copy);



    printMethod("ERASE");

    original.erase(original.begin());
    copy.erase(copy.begin());
    sizeMaps(original, copy);
    printMaps(original, copy);



	printMethod("INSERT");


    for (int i = 5; i < 10; ++i) {
        original.insert(std::make_pair(i, i + 97));
        copy.insert(std::make_pair(i, i + 97));
    }
    sizeMaps(original, copy);
    printMaps(original, copy);
    printMapAndColor(copy);



    printMethod("FIND");

    sizeMaps(original, copy);
    printMaps(original, copy);


    std::map<int, char>::iterator it = original.find(4);
    ft::map<int, char>::iterator myIt = copy.find(4);

    std::map<int, char>::iterator it1 = original.find(4);
    ft::map<int, char>::iterator myIt1 = copy.find(4);

    std::map<int, char>::iterator it2 = original.find(7);
    ft::map<int, char>::iterator myIt2 = copy.find(7);
//    std::map<int, std::string>::iterator it = original.find(2);
//    ft::map<int, std::string>::iterator myIt = copy.find(2);

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
    sizeMaps(original, copy);
    printMaps(original, copy);

//    original.insert(it1, 10);



    printMethod("LOWER BOUND");
//    original.insert(++original.begin(), std::make_pair(10, 10 + 97));

	it1 = original.lower_bound(5);
	myIt1 = copy.lower_bound(5);

	std::cout << " | " << GREEN << it1->first << NC << " : " << GREEN << it1->second << NC << "\n";
	std::cout << " | " << GREEN << myIt1->first << NC << " : " << GREEN << myIt1->second << NC << "\n";
    sizeMaps(original, copy);
    printMaps(original, copy);



	printMethod("UPPER BOUND");

	it1 = original.upper_bound(2);
	myIt1 = copy.upper_bound(2);

	std::cout << " | " << GREEN << it1->first << NC << " : " << GREEN << it1->second << NC << "\n";
	std::cout << " | " << GREEN << myIt1->first << NC << " : " << GREEN << myIt1->second << NC << "\n";
	sizeMaps(original, copy);
	printMaps(original, copy);



	printMethod("EQUAL RANGE");

	std::pair<std::map<int, char>::iterator,std::map<int, char>::iterator> pair = original.equal_range(3);
	std::pair<ft::map<int, char>::iterator, ft::map<int, char>::iterator> myPair = copy.equal_range(3);

	std::cout << "Original lower bound points to: ";
	std::cout << pair.first->first << " => " << pair.first->second << '\n';

	std::cout << "Original upper bound points to: ";
	std::cout << pair.second->first << " => " << pair.second->second << '\n';


	std::cout << "My lower bound points to: ";
	std::cout << myPair.first->first << " => " << myPair.first->second << '\n';

	std::cout << "My upper bound points to: ";
	std::cout << myPair.second->first << " => " << myPair.second->second << '\n';

	printMethod("TEST TEST TEST TEST TEST TEST TEST");
//    printMethod("CLEAR");
//	original.clear();
//	copy.clear();
//
//	sizeMaps(original, copy);

//	std::cout << "Copy Size" << copy.size() << std::endl;
	return (0);
}
