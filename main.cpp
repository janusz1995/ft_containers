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

	sizeLists(first1, my1);
	sizeLists(second, my2);
	printTwoLists(first1, second, my1, my2);

	my1.merge(my2);
	first1.merge(second);

	sizeLists(first1, my1);
	sizeLists(second, my2);
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


	printMethod("TEST TEST TEST TEST TEST TEST TEST");

	ft::list<int> mylist1, mylist2;
	ft::list<int>::iterator it1;

	for (int i=1; i<=4; ++i)
		mylist1.push_back(i);      // mylist1: 1 2 3 4

	for (int i=1; i<=3; ++i)
		mylist2.push_back(i*10);   // mylist2: 10 20 30

	it1 = mylist1.begin();
	it1++;
	mylist1.splice ( mylist1.begin(), mylist1, it1, mylist1.end());

	printTwoLists(mylist1, mylist2);

//	std::list<int> mylist1, mylist2;
//	std::list<int>::iterator it1;
//
//	// set some initial values:
//	for (int i=1; i<=4; ++i)
//		mylist1.push_back(i);      // mylist1: 1 2 3 4
//
//	for (int i=1; i<=3; ++i)
//		mylist2.push_back(i*10);   // mylist2: 10 20 30
//
//	std::cout << "mylist1 contains:";
//	for (it1=mylist1.begin(); it1!=mylist1.end(); ++it1)
//		std::cout << ' ' << *it1;
//	std::cout << '\n';
//
//	std::cout << "mylist2 contains:";
//	for (it1=mylist2.begin(); it1!=mylist2.end(); ++it1)
//		std::cout << ' ' << *it1;
//	std::cout << '\n';
////
////
//	it1 = mylist1.begin();
//	++it1;                         // points to 2
//
//	mylist1.splice ( mylist1.begin(), mylist1, it1, mylist1.end());
//	// mylist1: 30 3 4 1 10 20
//
//	std::cout << "mylist1 contains:";
//	for (it1=mylist1.begin(); it1!=mylist1.end(); ++it1)
//		std::cout << ' ' << *it1;
//	std::cout << '\n';
//
//	std::cout << "mylist2 contains:";
//	for (it1=mylist2.begin(); it1!=mylist2.end(); ++it1)
//		std::cout << ' ' << *it1;
//	std::cout << '\n';






	return (0);
}
