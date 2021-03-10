#include <iostream>
#include "list.hpp"
#include <list>

#define NC "\e[0m"
#define WHITE '\e[1;37m'
#define BLACK '\e[0;30m'
#define BLUE "\e[0;34m"
//#define BLUE "\e[1;38;5;208m"
#define LIGHT_BLUE "\e[1;34m"
#define GREEN "\e[0;32m"
#define LIGHT_GREEN '\e[1;32m'
#define CYAN "\e[0;36m"
#define LIGHT_CYAN '\e[1;36m'
#define RED "\e[0;31m"
#define LIGHT_RED '\e[1;31m'
#define PURPLE "\e[0;35m"
#define LIGHT_PURPLE '\e[1;35m'
#define BROWN '\e[0;33m'
#define YELLOW "\e[1;33m"
#define GRAY '\e[0;30m'
#define LIGHT_GRAY '\e[0;37m'
#define ORIGINAL "\e[0;34m"
#define MYLIST "\e[1;33m"

void printMethod(std::string method) {
	std::cout << RED <<  "<-<-<-<-<-<-<-<-<-<- " <<  CYAN <<  method << RED << " ->->->->->->->->->->\n" << NC;
}

template<typename T>
void printLists(std::list<T> &list, ft::list<T> &myList) {

	std::cout << BLUE << "Original List " << NC << " --->>> ";
	for (typename std::list<T>::iterator it = list.begin();  it != list.end() ; it++) {
		std::cout << " | " << GREEN << *it << NC;
	}
	std::cout << " |\n";

	std::cout << YELLOW << "My List " << NC << " --------->>> ";
	for (typename ft::list<T>::iterator it = myList.begin();  it != myList.end() ; it++) {
		std::cout << " | " << GREEN << *it << NC;
	}
	std::cout << " |\n";
}

//template<typename T>
//void printList(ft::list<T> &list) {
//
//	std::cout << YELLOW << "My List " << NC << " --------->>> ";
//	for (typename ft::list<T>::iterator it = list.begin();  it != list.end() ; it++) {
//		std::cout << " | " << GREEN << *it << NC;
//	}
//	std::cout << " |\n";
//}

void isEmpty(std::string str, bool empty, std::string color) {
	std::cout << color << str << (!empty ? RED : GREEN) << empty << "\n" << NC;
}

void printSize(std::string str, size_t size, std::string color) {
	std::cout << color << str << PURPLE << size << "\n" << NC;
}

template<typename T>
void emptyLists(std::list<T> &original, ft::list<T> &copy) {
	isEmpty("Original List is Empty: ", original.empty(), ORIGINAL);
	isEmpty("My List is Empty:       ", copy.empty(), MYLIST);
}

template<typename T>
void sizeLists(std::list<T> &original, ft::list<T> &copy) {
	printSize("Original List Size: ", original.size(), ORIGINAL);
	printSize("My List Size:       ", copy.size(), MYLIST);
}






// empty +
// push back +
// pop back +
// insert +-
// erase +
// push front +
// pop front +
// clear +
// operator= +
//



int main() {
	ft::list<int> copy;
	std::list<int> original;

	printMethod("EMPTY");

	emptyLists(original, copy);
	sizeLists(original, copy);


	printMethod("PUSH BACK");
	for (int i = 0; i < 14; i += 2) {
		original.push_back(i + 2);
		copy.push_back(i + 2);
	}

	emptyLists(original, copy);
	sizeLists(original, copy);
	printLists(original, copy);


	printMethod("POP BACK");
	original.pop_back();
	original.pop_back();
	copy.pop_back();
	copy.pop_back();

	emptyLists(original, copy);
	sizeLists(original, copy);
	printLists(original, copy);


	printMethod("INSERT");
	std::list<int>::iterator it = original.begin();
	it++;
	ft::list<int>::iterator myIt = copy.begin();
	myIt++;
	original.insert(it++, 200);
	copy.insert(myIt++, 200);

	sizeLists(original, copy);
	printLists(original, copy);

	original.insert(it, 3, 777);
	copy.insert(myIt, 3, 777);

	sizeLists(original, copy);
	printLists(original, copy);

	printMethod("ERASE");
	original.erase(original.begin());
	copy.erase(copy.begin());
	original.erase(it++);
	copy.erase(myIt++);

	sizeLists(original, copy);
	printLists(original, copy);


	printMethod("PUSH FRONT");
	original.push_front(600);
	copy.push_front(600);
	original.push_front(700);
	copy.push_front(700);

	sizeLists(original, copy);
	printLists(original, copy);


	printMethod("POP FRONT");
	original.pop_front();
	copy.pop_front();

	sizeLists(original, copy);
	printLists(original, copy);


	printMethod("CLEAR");
	original.clear();
	copy.clear();

	emptyLists(original, copy);
	sizeLists(original, copy);
	printLists(original, copy);


	printMethod("TEST   TEST   TEST   TEST   TEST");
//	std::list<double> first, second;
//
//	first.push_back (3.1);
//	first.push_back (2.2);
//	first.push_back (2.9);
//
//	second.push_back (3.7);
//	second.push_back (7.1);
//	second.push_back (1.4);
//
//	first.sort();
//	second.sort();
//
//	first.merge(second);

//	second.push_back (2.1);

//	std::cout << "first contains:";
//	for(std::list<double>::iterator it = first.begin(); it!=first.end(); ++it)
//		std::cout << ' ' << *it;
//	std::cout << '\n';

	int myints[]= {17,89,7,14, 89};
	std::list<int> mylist (myints,myints+4);

	mylist.remove(89);

	std::cout << "mylist contains:";
	for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';


	return (0);
}
