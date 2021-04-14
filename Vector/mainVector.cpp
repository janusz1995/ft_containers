#include "vector.hpp"
#include <vector>

int main() {

    std::vector<int> vec;
//    ft::vector<int> myvec();
//    std::vector<int> vec1(5, 100);
    ft::vector<int> myvec(5, 100);
    for (int i = 0; i < 5; ++i) {
        vec.push_back(i + 1);
    }
//    std::cout << myvec[1];
//    std::vector<int>::iterator it = vec1.begin();

    ft::vector<int>::iterator myit = myvec.begin();
    for (ft::vector<int>::iterator myit = myvec.begin(); myit != myvec.end() ; ++myit) {
        std::cout << *myit << " ";
    }

    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return (0);
}

