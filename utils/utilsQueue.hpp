#ifndef UTILSQUEUE_HPP
#define UTILSQUEUE_HPP
#include "../Queue/Queue.hpp"
#include "utils.hpp"
#include <queue>

template<typename T>
void emptyQueue(std::queue<T> &original, ft::queue<T> &copy) {
    isEmpty("Original Queue is Empty: ", original.empty(), ORIGINAL);
    isEmpty("My Queue is Empty:       ", copy.empty(), MYCOLOR);
}

template<typename T>
void sizeQueue(std::queue<T> &original, ft::queue<T> &copy) {
    printSize("Original Queue Size: ", original.size(), ORIGINAL);
    printSize("My Queue Size:       ", copy.size(), MYCOLOR);
}


#endif
