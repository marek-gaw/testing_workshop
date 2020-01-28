#include <iostream>

#include "Mouse.hpp"
#include "Cat.hpp"


void Mouse::registerObserver(IObserver* o) {
    observers.push_back(o);
    std::cout << "New observer registered.\n";
}

void Mouse::unregisterAllObservers() {
    observers.clear();
    std::cout << "All observers unregistered.\n";
}

void Mouse::update() {
    std::cout << "Updating observers...\n";
    for(const auto& o : observers) {
        o->notify();
    }
}
