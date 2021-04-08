#include <iostream>
#include "list.hpp"
#include <list>
//#include <chrono>

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
#define LIGHT_PURPLE "\e[1;35m"
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
void printTwoLists(ft::list<T> &myList, ft::list<T> &myList2) {
	std::cout << YELLOW << "My List 1 " << NC << " --------->>> ";
	for (typename ft::list<T>::iterator it = myList.begin();  it != myList.end() ; it++) {
		std::cout << " | " << GREEN << *it << NC;
	}
	std::cout << " |\n";

	std::cout << YELLOW << "My List 2 " << NC << " --------->>> ";
	for (typename ft::list<T>::iterator it = myList2.begin();  it != myList2.end() ; it++) {
		std::cout << " | " << GREEN << *it << NC;
	}
	std::cout << " |\n";
}

template<typename T>
void printListsReverse(std::list<T> &list, ft::list<T> &myList) {

	std::cout << BLUE << "Original List " << NC << " --->>> ";
	for (typename std::list<T>::reverse_iterator it = list.rbegin();  it != list.rend() ; it++) {
		std::cout << " | " << GREEN << *it << NC;
	}
	std::cout << " |\n";

	std::cout << YELLOW << "My List " << NC << " --------->>> ";
	for (typename ft::list<T>::reverse_iterator it = myList.rbegin();  it != myList.rend() ; it++) {
		std::cout << " | " << GREEN << *it << NC;
	}
	std::cout << " |\n";
}

template<typename T>
void printListsConstReverse(std::list<T> &list, ft::list<T> &myList) {

	std::cout << BLUE << "Original List " << NC << " --->>> ";
	for (typename std::list<T>::const_reverse_iterator it = list.rbegin();  it != list.rend() ; it++) {
		std::cout << " | " << GREEN << *it << NC;
	}
	std::cout << " |\n";

	std::cout << YELLOW << "My List " << NC << " --------->>> ";
	for (typename ft::list<T>::const_reverse_iterator it = myList.rbegin();  it != myList.rend() ; it++) {
		std::cout << " | " << GREEN << *it << NC;
	}
	std::cout << " |\n";
}

template<typename T>
void printListsConst(std::list<T> &list, ft::list<T> &myList) {

	std::cout << BLUE << "Original List " << NC << " --->>> ";
	for (typename std::list<T>::const_iterator it = list.begin();  it != list.end() ; it++) {
		std::cout << " | " << GREEN << *it << NC;
	}
	std::cout << " |\n";

	std::cout << YELLOW << "My List " << NC << " --------->>> ";
	for (typename ft::list<T>::const_iterator it = myList.begin();  it != myList.end() ; it++) {
		std::cout << " | " << GREEN << *it << NC;
	}
	std::cout << " |\n";
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

void isEmpty(std::string str, bool empty, std::string color) {
	std::cout << color << str << (!empty ? RED : GREEN) << empty << "\n" << NC;
}

void printSize(std::string str, size_t size, std::string color) {
	std::cout << color << str << PURPLE << size << "\n" << NC;
}

template<typename T>
void printTwoLists(std::list<T> &list, std::list<T> &list2, ft::list<T> &myList, ft::list<T> &myList2) {

	std::cout << BLUE << "Original List 1 " << NC << " --->>> ";
	for (typename std::list<T>::iterator it = list.begin();  it != list.end() ; it++) {
		std::cout << " | " << GREEN << *it << NC;
	}
	std::cout << " |\n";

	std::cout << BLUE << "Original List 2 " << NC << " --->>> ";
	for (typename std::list<T>::iterator it = list2.begin();  it != list2.end() ; it++) {
		std::cout << " | " << GREEN << *it << NC;
	}
	std::cout << " |\n";

	printSize("Original List 1 Size: ", list.size(), ORIGINAL);
	printSize("Original List 2 Size: ", list2.size(), ORIGINAL);


	std::cout << YELLOW << "My List 1 " << NC << " --------->>> ";
	for (typename ft::list<T>::iterator it = myList.begin();  it != myList.end() ; it++) {
		std::cout << " | " << GREEN << *it << NC;
	}
	std::cout << " |\n";

	std::cout << YELLOW << "My List 2 " << NC << " --------->>> ";
	for (typename ft::list<T>::iterator it = myList2.begin();  it != myList2.end() ; it++) {
		std::cout << " | " << GREEN << *it << NC;
	}
	std::cout << " |\n";

	printSize("My List 1 Size:       ", myList.size(), MYLIST);
	printSize("My List 2 Size:       ", myList2.size(), MYLIST);
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
// insert +
// erase +
// push front +
// pop front +
// clear +
// operator= +
//



int main() {

	ft::list<int> copy(5, 2);
	std::list<int> original(5, 2);


	printMethod("EMPTY");

	emptyLists(original, copy);
	sizeLists(original, copy);


	printMethod("PUSH BACK");
	original.push_back(4);
	copy.push_back(4);

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
	ft::list<int>::iterator myIt = copy.begin();
	it++;
	myIt++;

	original.insert(it++, 200);
	copy.insert(myIt++, 200);

	sizeLists(original, copy);
	printLists(original, copy);

	original.insert(it, 3, 777);
	copy.insert(myIt, 3, 777);

	emptyLists(original, copy);
	sizeLists(original, copy);
	printLists(original, copy);

	std::list<int> first(2, 300);
	ft::list<int> myFirst(2, 300);

	for (int i = 1; i < 8; ++i) {
		first.push_back(i * 10);
		myFirst.push_back(i * 10);
	}

	std::list<int>::iterator fit = first.begin();
	ft::list<int>::iterator myFit = myFirst.begin();
	fit++;
	myFit++;

	original.insert(--it, ++fit, first.end());
	copy.insert(--myIt, ++myFit, myFirst.end());

	emptyLists(original, copy);
	sizeLists(original, copy);
	printLists(original, copy);


	printMethod("ERASE");
	original.erase(original.begin());
	copy.erase(copy.begin());
	original.erase(it++);
	copy.erase(myIt++);

	emptyLists(original, copy);
	sizeLists(original, copy);
	printLists(original, copy);


	printMethod("PUSH FRONT");
	original.push_front(666);
	copy.push_front(666);
	original.push_front(700);
	copy.push_front(700);

	emptyLists(original, copy);
	sizeLists(original, copy);
	printLists(original, copy);


	printMethod("POP FRONT");
	original.pop_front();
	copy.pop_front();

	emptyLists(original, copy);
	sizeLists(original, copy);
	printLists(original, copy);


	printMethod("REMOVE");
	original.remove(777);
	copy.remove(777);

	emptyLists(original, copy);
	sizeLists(original, copy);
	printLists(original, copy);


	printMethod("RESIZE");
	original.resize(4);
	copy.resize(4);

	emptyLists(original, copy);
	sizeLists(original, copy);
	printLists(original, copy);

	original.resize(6, 100);
	copy.resize(6, 100);

	emptyLists(original, copy);
	sizeLists(original, copy);
	printLists(original, copy);

	original.resize(10);
	copy.resize(10);

	emptyLists(original, copy);
	sizeLists(original, copy);
	printLists(original, copy);


	printMethod("CLEAR");
	original.clear();
	copy.clear();

	emptyLists(original, copy);
	sizeLists(original, copy);
	printLists(original, copy);


	printMethod("SWAP");

	std::list<int> F (10, 100);
	std::list<int> S (6, 500);

	ft::list<int> myF (10, 100);
	ft::list<int> myS (6, 500);

	printTwoLists(F, S, myF, myS);

	F.swap(S);
	myF.swap(myS);

	printTwoLists(F, S, myF, myS);


	printMethod("MERGE");

	std::list<double> first1, second;
	ft::list<double> my1, my2;

	my1.push_back (3.8);
	my1.push_back (2.2);
	my1.push_back (2.9);

	my2.push_back (3.7);
	my2.push_back (7.1);
	my2.push_back (1.4);

	first1.push_back (3.8);
	first1.push_back (2.2);
	first1.push_back (2.9);

	second.push_back (3.7);
	second.push_back (7.1);
	second.push_back (1.4);

	printTwoLists(first1, second, my1, my2);

	my1.merge(my2);
	first1.merge(second);

	printTwoLists(first1, second, my1, my2);


	printMethod("REVERSE");

	emptyLists(first1, my1);
	sizeLists(first1, my1);
	printLists(first1, my1);

	first1.reverse();
	my1.reverse();

	emptyLists(first1, my1);
	sizeLists(first1, my1);
	printLists(first1, my1);


	printMethod("SPLICE");

	std::list<int> list1, list2;
	std::list<int>::iterator it1;

	ft::list<int> mylist1, mylist2;
	ft::list<int>::iterator myIt1;

	for (int i=1; i<=4; ++i) {
		mylist1.push_back(i);
		list1.push_back(i);
	}

	for (int i=1; i<=6; ++i) {
		mylist2.push_back(i*10);
		list2.push_back(i*10);
	}

	myIt1 = mylist1.begin();
	++myIt1;

	it1 = list1.begin();
	++it1;

	printTwoLists(list1, list2, mylist1, mylist2);

	list1.splice(++it1, list2);
	mylist1.splice(++myIt1, mylist2);

	printTwoLists(list1, list2, mylist1, mylist2);

	for (int i=1; i<=4; ++i) {
		mylist2.push_back(i*100);
		list2.push_back(i*100);
	}

	printTwoLists(list1, list2, mylist1, mylist2);

	std::list<int>::iterator it2 = list1.begin();
	ft::list<int>::iterator myIt2 = mylist1.begin();

	for (int i = 0; i < 4; ++i) {
		it2++;
		myIt2++;
	}

	it1 = list2.begin();
	++it1;
	myIt1 = mylist2.begin();
	++myIt1;

	list2.splice(it1, list1, it2);
	mylist2.splice(myIt1, mylist1, myIt2);

	printTwoLists(list1, list2, mylist1, mylist2);

	list2.splice(++it1, list1, ++list1.begin(), --list1.end());
	mylist2.splice(++myIt1, mylist1,  ++mylist1.begin(), --mylist1.end());

	printTwoLists(list1, list2, mylist1, mylist2);


	printMethod("BACK AND FRONT");

	for (int i = 0; i < 5; ++i) {
		list2.back() -= list2.front();
		mylist2.back() -= mylist2.front();
	}

	emptyLists(list2, mylist2);
	sizeLists(list2, mylist2);
	printLists(list2, mylist2);


	printMethod("REVERSE ITERATOR");

	emptyLists(list2, mylist2);
	sizeLists(list2, mylist2);
	printListsReverse(list2, mylist2);


	printMethod("SORT");

	printLists(list2, mylist2);

	list2.sort();
	mylist2.sort();
//	std::cout << *it1 << " " << *myIt1 << std::endl;

	sizeLists(list2, mylist2);
	printLists(list2, mylist2);


	printMethod("CONST ITERATOR");

	emptyLists(list2, mylist2);
	sizeLists(list2, mylist2);
	printListsConst(list2, mylist2);


	printMethod("CONST REVERSE ITERATOR");

	emptyLists(list2, mylist2);
	sizeLists(list2, mylist2);
	printListsConstReverse(list2, mylist2);

	// ------------- try it -------------
//	std::list<int>::const_iterator itConst1 = list2.begin();
//	ft::list<int>::const_iterator myConstIt1 = mylist2.begin();

//	*it = 50; // can
//	*myIt = 50; // can
//	*itConst1 = 50; // can`t
//	*myConstIt1 = 50; // can`t


	printMethod("ASSIGN");

	printTwoLists(list1, list2, mylist1, mylist2);

	list1.assign(5, 50);
	mylist1.assign(5, 50);

	printTwoLists(list1, list2, mylist1, mylist2);

	it1 = list2.begin();
	myIt1 = mylist2.begin();
	for (int i = 0; i < 3; ++i) {
		it1++;
		myIt1++;
	}

	list1.assign(it1, --list2.end());
	mylist1.assign(myIt1, --mylist2.end());

//	list1.assign(list2.rbegin(), list2.rend());
//	mylist1.assign(mylist2.rbegin(), mylist2.rend());

	printTwoLists(list1, list2, mylist1, mylist2);


	printMethod("MAX SIZE");
	std::cout << BLUE << "Original List " << NC << " --->>> " << LIGHT_PURPLE << list1.max_size() << "\n" << NC;
	std::cout << YELLOW << "My List " << NC << " --------->>> " << LIGHT_PURPLE << mylist1.max_size() << "\n" << NC;
//	std::cout <<  list1.max_size();
//	mylist1.max_size();

	printMethod("OPERATOR =");

	printTwoLists(list1, list2, mylist1, mylist2);

	list1 = list2;
	mylist1 = mylist2;

	printTwoLists(list1, list2, mylist1, mylist2);

	printMethod("TEST TEST TEST TEST TEST TEST TEST");

//	while (itConst1 != list2.end()) {
//		std::cout << *itConst1 << "\n";
//		std::cout << *myConstIt1 << "\n";
//		itConst1++;
//		myConstIt1++;
//	}

//
//	ft::list<int> largeList;
//	for (int i = 1000000; i > 0; --i) {
//		largeList.push_back(i);
//	}
//	largeList.sort();
//	printLists(list2, largeList);

	return (0);
}
