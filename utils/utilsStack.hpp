#ifndef UTILSSTACK_CUH
#define UTILSSTACK_CUH
#include "utils.hpp"
#include "../Stack/Stack.hpp"

template<typename T>
void emptyStack(std::stack<T> &original, ft::stack<T> &copy) {
    isEmpty("Original Stack is Empty: ", original.empty(), ORIGINAL);
    isEmpty("My Queue is Empty:       ", copy.empty(), MYCOLOR);
}

template<typename T>
void sizeStack(std::stack<T> &original, ft::stack<T> &copy) {
    printSize("Original Stack Size: ", original.size(), ORIGINAL);
    printSize("My Stack Size:       ", copy.size(), MYCOLOR);
}

#endif
