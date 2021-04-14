#ifndef UTILSVECTOR_HPP
#define UTILSVECTOR_HPP
#include "../Vector/vector.hpp"
#include "utils.hpp"

template<typename T>
void printTwoVectors(ft::vector<T> &my, ft::vector<T> &my2) {
    std::cout << YELLOW << "My vector 1 " << NC << " --------->>> ";
    for (typename ft::vector<T>::iterator it = my.begin();  it != my.end() ; it++) {
        std::cout << " | " << GREEN << *it << NC;
    }
    std::cout << " |\n";

    std::cout << YELLOW << "My vector 2 " << NC << " --------->>> ";
    for (typename ft::vector<T>::iterator it = my2.begin();  it != my2.end() ; it++) {
        std::cout << " | " << GREEN << *it << NC;
    }
    std::cout << " |\n";
}

//template<typename T>
//void printListsReverse(std::list<T> &list, ft::list<T> &myList) {
//
//    std::cout << BLUE << "Original List " << NC << " --->>> ";
//    for (typename std::list<T>::reverse_iterator it = list.rbegin();  it != list.rend() ; it++) {
//        std::cout << " | " << GREEN << *it << NC;
//    }
//    std::cout << " |\n";
//
//    std::cout << YELLOW << "My List " << NC << " --------->>> ";
//    for (typename ft::list<T>::reverse_iterator it = myList.rbegin();  it != myList.rend() ; it++) {
//        std::cout << " | " << GREEN << *it << NC;
//    }
//    std::cout << " |\n";
//}
//
//template<typename T>
//void printListsConstReverse(std::list<T> &list, ft::list<T> &myList) {
//
//    std::cout << BLUE << "Original List " << NC << " --->>> ";
//    for (typename std::list<T>::const_reverse_iterator it = list.rbegin();  it != list.rend() ; it++) {
//        std::cout << " | " << GREEN << *it << NC;
//    }
//    std::cout << " |\n";
//
//    std::cout << YELLOW << "My List " << NC << " --------->>> ";
//    for (typename ft::list<T>::const_reverse_iterator it = myList.rbegin();  it != myList.rend() ; it++) {
//        std::cout << " | " << GREEN << *it << NC;
//    }
//    std::cout << " |\n";
//}
//
//template<typename T>
//void printListsConst(std::list<T> &list, ft::list<T> &myList) {
//
//    std::cout << BLUE << "Original List " << NC << " --->>> ";
//    for (typename std::list<T>::const_iterator it = list.begin();  it != list.end() ; it++) {
//        std::cout << " | " << GREEN << *it << NC;
//    }
//    std::cout << " |\n";
//
//    std::cout << YELLOW << "My List " << NC << " --------->>> ";
//    for (typename ft::list<T>::const_iterator it = myList.begin();  it != myList.end() ; it++) {
//        std::cout << " | " << GREEN << *it << NC;
//    }
//    std::cout << " |\n";
//}

template<typename T>
void printVectors(std::vector<T> &original, ft::vector<T> &my) {

    std::cout << BLUE << "Original Vector " << NC << " --->>> ";
    for (typename std::vector<T>::iterator it = original.begin();  it != original.end() ; it++) {
        std::cout << " | " << GREEN << *it << NC;
    }
    std::cout << " |\n";

    std::cout << YELLOW << "My Vector " << NC << " --------->>> ";
    for (typename ft::vector<T>::iterator it = my.begin();  it != my.end() ; it++) {
        std::cout << " | " << GREEN << *it << NC;
    }
    std::cout << " |\n";
}

//void isEmpty(std::string str, bool empty, std::string color) {
//    std::cout << color << str << (!empty ? RED : GREEN) << empty << "\n" << NC;
//}
//
//void printSize(std::string str, size_t size, std::string color) {
//    std::cout << color << str << PURPLE << size << "\n" << NC;
//}
//
//template<typename T>
//void printTwoLists(std::list<T> &list, std::list<T> &list2, ft::list<T> &myList, ft::list<T> &myList2) {
//
//    std::cout << BLUE << "Original List 1 " << NC << " --->>> ";
//    for (typename std::list<T>::iterator it = list.begin();  it != list.end() ; it++) {
//        std::cout << " | " << GREEN << *it << NC;
//    }
//    std::cout << " |\n";
//
//    std::cout << BLUE << "Original List 2 " << NC << " --->>> ";
//    for (typename std::list<T>::iterator it = list2.begin();  it != list2.end() ; it++) {
//        std::cout << " | " << GREEN << *it << NC;
//    }
//    std::cout << " |\n";
//
//    printSize("Original List 1 Size: ", list.size(), ORIGINAL);
//    printSize("Original List 2 Size: ", list2.size(), ORIGINAL);
//
//
//    std::cout << YELLOW << "My List 1 " << NC << " --------->>> ";
//    for (typename ft::list<T>::iterator it = myList.begin();  it != myList.end() ; it++) {
//        std::cout << " | " << GREEN << *it << NC;
//    }
//    std::cout << " |\n";
//
//    std::cout << YELLOW << "My List 2 " << NC << " --------->>> ";
//    for (typename ft::list<T>::iterator it = myList2.begin();  it != myList2.end() ; it++) {
//        std::cout << " | " << GREEN << *it << NC;
//    }
//    std::cout << " |\n";
//
//    printSize("My List 1 Size:       ", myList.size(), MYCOLOR);
//    printSize("My List 2 Size:       ", myList2.size(), MYCOLOR);
//}

template<typename T>
void capacityVectors(std::vector<T> &original, ft::vector<T> &copy) {
    printSize("Original Vector Capacity: ", original.capacity(), ORIGINAL);
    printSize("My Vector Capacity:       ", copy.capacity(), MYCOLOR);
}

template<typename T>
void emptyVectors(std::vector<T> &original, ft::vector<T> &copy) {
    isEmpty("Original Vector is Empty: ", original.empty(), ORIGINAL);
    isEmpty("My Vector is Empty:       ", copy.empty(), MYCOLOR);
}

template<typename T>
void sizeVectors(std::vector<T> &original, ft::vector<T> &copy) {
    printSize("Original Vector Size: ", original.size(), ORIGINAL);
    printSize("My Vector Size:       ", copy.size(), MYCOLOR);
}


#endif
