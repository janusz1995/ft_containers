#include "vector.hpp"
#include <vector>
#include "../utils/utilsVector.hpp"


int main() {

    std::vector<int> vec;
    ft::vector<int> myvec;
//    std::vector<int> vec1(5, 100);
//    ft::vector<int> myvec(5, 100);
//    for (int i = 0; i < 5; ++i) {
//        myvec.push_back(i + 1);
//        vec.push_back(i + 1);
//    }
//    std::cout << myvec[1];
//    std::vector<int>::iterator it = vec1.begin();

//    for (ft::vector<int>::iterator myit = myvec.begin(); myit != myvec.end() ; ++myit) {
//        std::cout << *myit << " ";
//    }
//    std::cout << std::endl;
//
//    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
//        std::cout << *it << " ";
//    }
//    std::cout << std::endl;



    printMethod("EMPTY");

    emptyVectors(vec, myvec);
    sizeVectors(vec, myvec);
    printVectors(vec, myvec);



    printMethod("MAX SIZE");

    std::cout << BLUE << "Original Vector " << NC << " --->>> " << LIGHT_PURPLE << vec.max_size() << "\n" << NC;
    std::cout << YELLOW << "My Vector " << NC << " --------->>> " << LIGHT_PURPLE << myvec.max_size() << "\n" << NC;



    printMethod("PUSH BACK");

    for (int i = 0; i < 5; ++i) {
        myvec.push_back(i + 1);
        vec.push_back(i + 1);
    }

    emptyVectors(vec, myvec);
    sizeVectors(vec, myvec);
    printVectors(vec, myvec);



    printMethod("POP BACK");

    for (int i = 0; i < 3; ++i) {
        vec.pop_back();
        myvec.pop_back();
    }

    emptyVectors(vec, myvec);
    sizeVectors(vec, myvec);
    capacityVectors(vec, myvec);
    printVectors(vec, myvec);



    printMethod("RESIZE");

    vec.resize(10, 200);
    myvec.resize(10, 200);

    emptyVectors(vec, myvec);
    sizeVectors(vec, myvec);
    capacityVectors(vec, myvec);
    printVectors(vec, myvec);


    vec.resize(5);
    myvec.resize(5);

    emptyVectors(vec, myvec);
    sizeVectors(vec, myvec);
    capacityVectors(vec, myvec);
    printVectors(vec, myvec);



    printMethod("ASSIGN");

    vec.assign(3, 300);
    myvec.assign(3, 300);

    emptyVectors(vec, myvec);
    sizeVectors(vec, myvec);
    capacityVectors(vec, myvec);
    printVectors(vec, myvec);



    printMethod("ERASE");

    for (int i = 0; i < 5; ++i) {
        vec.push_back(10 * (i + 1));
        myvec.push_back(10 * (i + 1));
    }

    std::vector<int>::iterator it = vec.begin();
    ft::vector<int>::iterator myit = myvec.begin();

    for (int i = 0; i < 4; ++i) {
        it++;
        myit++;
    }
    it = vec.erase(it);
    myit = myvec.erase(myit);
    (--myit)--;
    (--it)--;

//    std::cout << "std it: " << *it << " | ft it: " << *myit << std::endl;
    emptyVectors(vec, myvec);
    sizeVectors(vec, myvec);
    capacityVectors(vec, myvec);
    printVectors(vec, myvec);

    it = vec.erase(it, it + 3);
    myit = myvec.erase(myit, myit + 3);

//    std::cout << "std it: " << *it << " | ft it: " << *myit << std::endl;
    emptyVectors(vec, myvec);
    sizeVectors(vec, myvec);
    capacityVectors(vec, myvec);
    printVectors(vec, myvec);



    printMethod("TEST TEST TEST TEST TEST TEST TEST");


    vec.insert(it, 100);
    myvec.insert(myit, 100);

//    std::cout << "std it: " << *it << " | ft it: " << *myit << std::endl;
//    std::cout << "std it: " << vec[5] << " | ft it: " << myvec[5]<< std::endl;
//    std::cout << "std it: " << vec[6] << " | ft it: " << myvec[6]<< std::endl;
//    std::cout << "std it: " << vec[7] << " | ft it: " << myvec[7]<< std::endl;
//    std::cout << "std it: " << vec[8] << " | ft it: " << myvec[8]<< std::endl;
    emptyVectors(vec, myvec);
    sizeVectors(vec, myvec);
    capacityVectors(vec, myvec);
    printVectors(vec, myvec);


    return (0);
}

