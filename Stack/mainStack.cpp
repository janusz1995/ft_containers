#include "Stack.hpp"
#include <stack>
#include "../utils/utilsStack.cuh"

int main() {

    std::stack<int> s;
    ft::stack<int> myS;
    ft::stack<int> myS1;



    printMethod("EMPTY AND SIZE");

    emptyStack(s, myS);
    sizeStack(s, myS);



    printMethod("PUSH AND TOP");

    std::cout << BLUE << "Original Stack " << NC << " --->>> ";
    for (int i = 0;  i < 10; i++) {
        s.push(i * 10);
        std::cout << " | " << GREEN << s.top() << NC;
    }
    std::cout << " |\n";

    std::cout << YELLOW << "My Stack " << NC << " --------->>> ";
    for (int i = 0;  i < 10; i++) {
        myS.push(i * 10);
        std::cout << " | " << GREEN << myS.top() << NC;
    }
    std::cout << " |\n";

    emptyStack(s, myS);
    sizeStack(s, myS);



    printMethod("POP AND TOP");

    for (int i = 0;  i < 10; i++) {
        s.pop();
        myS.pop();
    }

//    std::cout << BLUE << "Original Stack " << NC << " --->>> " << " | " << GREEN << s.top() << NC;
//    std::cout << YELLOW << "My Stack " << NC << " --------->>> " << " | " << GREEN << myS.top() << NC;

    emptyStack(s, myS);
    sizeStack(s, myS);



    printMethod("RELATIONAL OPERATORS");

    for (int i = 0; i < 3; ++i) {
        myS.push(i + 1);
        myS1.push(i + 1);
    }

    std::cout << RED << "*****" << CYAN << " Operator == " << RED << "*****\n";
    if (myS == myS1)
        std::cout << PURPLE << "Queue EQUALS\n";

    std::cout << RED << "*****" << CYAN << " Operator <= " << RED << "*****\n";
    if (myS <= myS1)
        std::cout << PURPLE << "Queue 1 more or EQUAL Queue 2\n";

    std::cout << RED << "*****" << CYAN << " Operator >= " << RED << "*****\n";
    if (myS >= myS1)
        std::cout << PURPLE << "Queue 2 more or EQUAL Queue 1\n";

    myS1.pop();

    std::cout << RED << "*****" << CYAN << " Operator != " << RED << "*****\n";
    if (myS1 != myS)
        std::cout << PURPLE << "Queue NOT EQUALS\n";
    std::cout << RED << "*****" << CYAN << " Operator < " << RED << "*****\n";
    if (myS1 < myS) {
        std::cout << PURPLE << "Queue 1 more than Queue 2\n";
    }

    myS.pop();
    myS.pop();

    std::cout << RED << "*****" << CYAN << " Operator > " << RED << "*****\n";
    if (myS1 > myS)
        std::cout << PURPLE << "Queue 2 more than Queue 1\n";


    return (0);
}
