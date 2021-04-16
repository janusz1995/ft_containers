#include "vector.hpp"
#include <vector>
#include "../utils/utilsVector.hpp"


int main() {

    std::vector<int> vec;
    ft::vector<int> myvec;
    std::vector<int> vec1(3, 66);
    ft::vector<int> myvec1(3, 66);
    std::vector<int> vec2(1, 66);
    ft::vector<int> myvec2(1, 66);
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


    vec2.assign(++vec.begin(), vec.end());
    myvec2.assign(++myvec.begin(), myvec.end());

    emptyVectors(vec2, myvec2);
    sizeVectors(vec2, myvec2);
    capacityVectors(vec2, myvec2);
    printVectors(vec2, myvec2);



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



    printMethod("INSERT");

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


//    vec.insert(vec.end(), 3, 777);
//    myvec.insert(myvec.end(), 3, 777);
    vec.insert(it, 3, 777);
    myvec.insert(myit, 3, 777);

//    std::cout << "std it: " << *it << " | ft it: " << *myit << std::endl;
//    std::cout << "std it: " << vec[5] << " | ft it: " << myvec[5]<< std::endl;
//    std::cout << "std it: " << vec[6] << " | ft it: " << myvec[6]<< std::endl;
//    std::cout << "std it: " << vec[7] << " | ft it: " << myvec[7]<< std::endl;
//    std::cout << "std it: " << vec[8] << " | ft it: " << myvec[8]<< std::endl;


    emptyVectors(vec, myvec);
    sizeVectors(vec, myvec);
    capacityVectors(vec, myvec);
    printVectors(vec, myvec);


    vec.insert(++it, vec1.begin(), vec1.end());
    myvec.insert(++myit, myvec1.begin(), myvec1.end());

    emptyVectors(vec, myvec);
    sizeVectors(vec, myvec);
    capacityVectors(vec, myvec);
    printVectors(vec, myvec);


    vec.insert(it, ++it, vec.end());
    myvec.insert(myit, ++myit, myvec.end());


//    std::cout << "std it: " << *it << " | ft it: " << *myit << std::endl;
    emptyVectors(vec, myvec);
    sizeVectors(vec, myvec);
    capacityVectors(vec, myvec);
    printVectors(vec, myvec);


    printMethod("CONSTRUCTORS AND OPERATOR=");

    std::vector<int> vec3(vec.begin(), vec.end());
    ft::vector<int> myvec3(myvec.begin(), myvec.end());

    emptyVectors(vec3, myvec3);
    sizeVectors(vec3, myvec3);
    capacityVectors(vec3, myvec3);
    printVectors(vec3, myvec3);


    myit = myvec.begin();
    it = vec.begin();
    for (int i = 0; i < 7; ++i) {
        it++;
        myit++;
    }

    std::vector<int> vec4(it, vec.end());
    ft::vector<int> myvec4(myit, myvec.end());

    emptyVectors(vec4, myvec4);
    sizeVectors(vec4, myvec4);
    capacityVectors(vec4, myvec4);
    printVectors(vec4, myvec4);

    vec3 = vec4;
    myvec3 = myvec4;

    emptyVectors(vec3, myvec3);
    sizeVectors(vec3, myvec3);
    capacityVectors(vec3, myvec3);
    printVectors(vec3, myvec3);



    printMethod("FRONT AND BACK");

    vec3.front() -= vec3.back();
    myvec3.front() -= myvec3.back();

    emptyVectors(vec3, myvec3);
    sizeVectors(vec3, myvec3);
    capacityVectors(vec3, myvec3);
    printVectors(vec3, myvec3);



    printMethod("SWAP");

    printTwoVectors(vec1, vec3, myvec1, myvec3);

    vec1.swap(vec3);
    myvec1.swap(myvec3);

    printTwoVectors(vec1, vec3, myvec1, myvec3);

    std::swap(vec1, vec3);
    ft::swap(myvec1, myvec3);

    printTwoVectors(vec1, vec3, myvec1, myvec3);



    printMethod("CLEAR");

    vec3.clear();
    myvec3.clear();

    emptyVectors(vec3, myvec3);
    sizeVectors(vec3, myvec3);
    capacityVectors(vec3, myvec3);
    printVectors(vec3, myvec3);



    printMethod("RELATIONAL OPERATORS");

    myvec3.assign(3, 66);
    printTwoVectors(myvec1, myvec3);

    std::cout << RED << "*****" << CYAN << " Operator == " << RED << "*****\n";
    if (myvec3 == myvec1)
        std::cout << PURPLE << "Vectors EQUALS\n";


    std::cout << RED << "*****" << CYAN << " Operator <= " << RED << "*****\n";
    if (myvec3 <= myvec1)
        std::cout << PURPLE << "Vector 1 more or EQUAL Vector 2\n";

    std::cout << RED << "*****" << CYAN << " Operator >= " << RED << "*****\n";
    if (myvec3 >= myvec1)
        std::cout << PURPLE << "Vector 2 more or EQUAL Vector 1\n";

    myvec3.pop_back();
    printTwoVectors(myvec1, myvec3);

    std::cout << RED << "*****" << CYAN << " Operator != " << RED << "*****\n";
    if (myvec3 != myvec1)
        std::cout << PURPLE << "Vectors NOT EQUALS\n";

    std::cout << RED << "*****" << CYAN << " Operator < " << RED << "*****\n";
    if (myvec3 < myvec1)
        std::cout << PURPLE << "Vector 1 more than Vector 2\n";

    myvec1.pop_back();
    myvec1.pop_back();
    printTwoVectors(myvec1, myvec3);

    std::cout << RED << "*****" << CYAN << " Operator > " << RED << "*****\n";
    if (myvec3 > myvec1)
        std::cout << PURPLE << "Vector 2 more than Vector 1\n";



    printMethod("REVERSE ITERATOR");

    printVectorsReverse(vec4, myvec4);



    printMethod("TEST TEST TEST TEST TEST TEST TEST");

    return (0);
}
