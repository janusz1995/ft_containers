#include "Queue.hpp"
#include "../utils/utils.hpp"
#include "../utils/utilsQueue.hpp"
#include <iostream>
#include <queue>
#include "Queue.hpp"


int main() {

	std::queue<int> q;
    ft::queue<int> myq;
    ft::queue<int> myq1;



    printMethod("EMPTY");

    emptyQueue(q, myq);
    sizeQueue(q, myq);



    printMethod("PUSH AND BACK");

    std::cout << BLUE << "Original Queue " << NC << " --->>> ";
    for (int i = 0;  i < 10; i++) {
        q.push(i * 10);
        std::cout << " | " << GREEN << q.back() << NC;
    }
    std::cout << " |\n";

    std::cout << YELLOW << "My Queue " << NC << " --------->>> ";
    for (int i = 0;  i < 10; i++) {
        myq.push(i * 10);
        std::cout << " | " << GREEN << myq.back() << NC;
    }
    std::cout << " |\n";

    emptyQueue(q, myq);
    sizeQueue(q, myq);



    printMethod("POP AND FRONT");

    std::cout << BLUE << "Original Queue " << NC << " --->>> ";
    for (int i = 0;  i < 10; i++) {
        std::cout << " | " << GREEN << q.front() << NC;
        q.pop();
    }
    std::cout << " |\n";

    std::cout << YELLOW << "My Queue " << NC << " --------->>> ";
    for (int i = 0;  i < 10 ; i++) {
        std::cout << " | " << GREEN << myq.front() << NC;
        myq.pop();
    }
    std::cout << " |\n";

    emptyQueue(q, myq);
    sizeQueue(q, myq);



    printMethod("SIZE");

    emptyQueue(q, myq);
    sizeQueue(q, myq);



    printMethod("RELATIONAL OPERATORS");

    for (int i = 0; i < 3; ++i) {
        myq.push(i + 1);
        myq1.push(i + 1);
    }

    std::cout << RED << "*****" << CYAN << " Operator == " << RED << "*****\n";
    if (myq == myq1)
        std::cout << PURPLE << "Queue EQUALS\n";

    std::cout << RED << "*****" << CYAN << " Operator <= " << RED << "*****\n";
    if (myq <= myq1)
        std::cout << PURPLE << "Queue 1 more or EQUAL Queue 2\n";

    std::cout << RED << "*****" << CYAN << " Operator >= " << RED << "*****\n";
    if (myq >= myq1)
        std::cout << PURPLE << "Queue 2 more or EQUAL Queue 1\n";

    myq1.pop();

    std::cout << RED << "*****" << CYAN << " Operator != " << RED << "*****\n";
    if (myq1 != myq)
        std::cout << PURPLE << "Queue NOT EQUALS\n";
    std::cout << RED << "*****" << CYAN << " Operator > " << RED << "*****\n";
    if (myq1 > myq)
        std::cout << PURPLE << "Queue 2 more than Queue 1\n";

    myq.pop();
    myq.pop();

    std::cout << RED << "*****" << CYAN << " Operator < " << RED << "*****\n";
    if (myq1 < myq) {
        std::cout << PURPLE << "Queue 1 more than Queue 2\n";
    }



	return (0);
}