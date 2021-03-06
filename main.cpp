#include <iostream>
#include "list.hpp"
#include <list>

#define NC "\e[0m"
#define WHITE '\e[1;37m'
#define BLACK '\e[0;30m'
#define BLUE "\e[0;34m"
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
void printList(std::list<T> &list, std::string method) {

	std::cout << BLUE << "Original List " << NC << " --->>> ";
	for (typename std::list<T>::iterator it = list.begin();  it != list.end() ; it++) {
		std::cout << " | " << GREEN << *it << NC;
	}
	std::cout << " |\n";
}

template<typename T>
void printList(ft::list<T> &list, std::string method) {

	std::cout << YELLOW << "My List " << NC << " --------->>> ";
	for (typename ft::list<T>::iterator it = list.begin();  it != list.end() ; it++) {
		std::cout << " | " << GREEN << *it << NC;
	}
	std::cout << " |\n";
}

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

int main() {
	ft::list<int> copy;
	std::list<int> original;

	printMethod("EMPTY");
	emptyLists(original, copy);
	sizeLists(original, copy);

	printMethod("PUSH BACK");
	for (int i = 0; i < 10; i += 2) {
		original.push_back(i + 2);
		copy.push_back(i + 2);
	}
	emptyLists(original, copy);
	sizeLists(original, copy);
	printList(original, "Push back");
	printList(copy, "Push back");

	printMethod("POP BACK");

	original.pop_back();
	original.pop_back();
	copy.pop_back();
	copy.pop_back();

	emptyLists(original, copy);
	sizeLists(original, copy);
	printList(original, "Pop back");
	printList(copy, "Pop back");


	return (0);
}
