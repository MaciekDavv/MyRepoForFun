#include "wytworcza.hpp"
#include "fabryka.hpp"

//#include <iostream>

int main () {
    //---------------------------fabryka.hpp implementation----------------------------------
    std::cout << "Client: testing client code with the first factory type:\n";
    auto facVin = std::make_shared<vinFactory>();
    clientCode(*facVin);
    auto checkVin = facVin->createCheckBox();
    std::cout << "checkVin we weel see wahat hapen when we use facVin poiter: " << facVin->createButon()->push() << "\n";
    std::cout << "checkVin we well see wahat hapen: " << checkVin->klik() << '\n';

    std::cout << "\n";
    std::cout << "Client: testing the same client code with the second factory type:\n";
    auto facMac = std::make_shared<macFactory>();
    clientCode(*facMac);
    auto checkMac = facMac->createButon();
    std::cout << "And one more time: " << facMac->createCheckBox()->pushAndKlik(*checkMac) << "\n";
    std::cout << "\n";


    //----------------------------wytworcz.hpp implementation--------------------------------
    // std::cout << "App: Launched with the concreteCreator1." << "\n";
    // auto creator = std::make_shared<ConcreteCreator1>();
    // clientCode(*creator);
    // std::cout << "\n";
    // std::cout << "App: Launched with the concreteCreator2." << "\n";
    // auto creator2 = std::make_shared<ConcreteCreator2>();
    // clientCode(*creator2);

    return 0;
}