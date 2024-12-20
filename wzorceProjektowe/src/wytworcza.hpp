#pragma once

#include <string>
#include <memory>
#include <iostream>

class Product {
    public:
    virtual ~Product() = default;
    virtual std::string operation() const = 0;
};

class ConcreteProduct1 : public Product {
    public:
    std::string operation() const override {
        return "Result of the ConcreteProduct1";
    }
};
class ConcreteProduct2 : public Product {
    public:
    std::string operation() const override {
        return "Result of the ConcreteProduct2";
    }
};

class Creator {
    public:
    virtual ~Creator() = default;
    virtual std::shared_ptr<Product> factoryMethod() const = 0;
    std::string someOperation() const {
        std::shared_ptr<Product> (Creator::*product)() const = &Creator::factoryMethod;
        auto result = (this->*product)();
        return "Creator: the same creator's has... " + result->operation();
    }
};

class ConcreteCreator1 : public Creator {
    public:
    std::shared_ptr<Product> factoryMethod() const override {
        return std::make_shared<ConcreteProduct1>();
    }
};
class ConcreteCreator2 : public Creator {
    public:
    std::shared_ptr<Product> factoryMethod() const override {
        return std::make_shared<ConcreteProduct2>();
    }
};

void clientCode(const Creator& creator) {
    std::cout << "Client: I'm not aware of the crator's class, but... \n" << creator.someOperation() << "\n";
}