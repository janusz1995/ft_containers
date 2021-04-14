#ifndef FT_CONTAINERS_UTILS_HPP
# define FT_CONTAINERS_UTILS_HPP
# include <iostream>
//# include "../List/list.hpp"
//# include "../Vector/vector.hpp"

# define NC "\e[0m"
# define WHITE '\e[1;37m'
# define BLACK '\e[0;30m'
# define BLUE "\e[0;34m"
//#define BLUE "\e[1;38;5;208m"
# define LIGHT_BLUE "\e[1;34m"
# define GREEN "\e[0;32m"
# define LIGHT_GREEN '\e[1;32m'
# define CYAN "\e[0;36m"
# define LIGHT_CYAN '\e[1;36m'
# define RED "\e[0;31m"
# define LIGHT_RED '\e[1;31m'
# define PURPLE "\e[0;35m"
# define LIGHT_PURPLE "\e[1;35m"
# define BROWN '\e[0;33m'
# define YELLOW "\e[1;33m"
# define GRAY '\e[0;30m'
# define LIGHT_GRAY '\e[0;37m'
# define ORIGINAL "\e[0;34m"
# define MYCOLOR "\e[1;33m"

void printMethod(std::string method) {
    std::cout << RED <<  "<-<-<-<-<-<-<-<-<-<- " <<  CYAN <<  method << RED << " ->->->->->->->->->->\n" << NC;
}

void isEmpty(std::string str, bool empty, std::string color) {
    std::cout << color << str << (!empty ? RED : GREEN) << empty << "\n" << NC;
}

void printSize(std::string str, size_t size, std::string color) {
    std::cout << color << str << PURPLE << size << "\n" << NC;
}


#endif
