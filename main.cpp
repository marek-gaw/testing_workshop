#include "iostream"
#include "Cat.hpp"
#include "Mouse.hpp"


int main()
{

    IObserver* cat1 = new Cat("Miauczyslaw");
    IObserver* cat2 = new Cat("Miauczypuszek");

    Mouse mouse1;
    Mouse mouse2;

    mouse1.registerObserver(cat1);
    mouse2.registerObserver(cat2);

    mouse1.update();
    mouse2.update();

    mouse1.unregisterAllObservers();
    mouse2.unregisterAllObservers();

    mouse1.update();
    mouse2.update();

    delete cat1;
    delete cat2;

    return 0;
}
