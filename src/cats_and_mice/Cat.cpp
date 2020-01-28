#include "Cat.hpp"
#include <iostream>

Cat::Cat(std::string name)
    : name(name) {

}

void Cat::notify() {
    std::cout << "Cat " << name << " sees a mouse!\n";
}
