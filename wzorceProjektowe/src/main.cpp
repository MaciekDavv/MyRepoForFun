#include "wytworcza.hpp"

//#include <iostream>

int main () {
    std::cout << "App: Launched with the concreteCreator1." << "\n";
    auto creator = std::make_shared<ConcreteCreator1>();
    clientCode(*creator);
    std::cout << "\n";
    std::cout << "App: Launched with the concreteCreator2." << "\n";
    auto creator2 = std::make_shared<ConcreteCreator2>();
    clientCode(*creator2);

    return 0;
}