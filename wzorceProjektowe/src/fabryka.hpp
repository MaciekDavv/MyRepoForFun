#pragma once

#include <memory>
#include <string>
#include <iostream>
 
 class Buton {
    public:
    virtual ~Buton() = default;
    virtual std::string push() const = 0;
 };

 class vinButon : public Buton {
    public:
    std::string push() const override {
        return "The result of vinButon PUSH()";
    }
 };
 class macButon : public Buton {
    public:
    std::string push() const override {
        return "The result of macButon PUSH()";
    }
 };

 class Checkbox {
    public:
    virtual ~Checkbox() = default;
    virtual std::string klik() const = 0;

    virtual std::string pushAndKlik(const Buton& collaborate) const = 0;
 };

 class vinCheckbox : public Checkbox {
    public:
    std::string klik() const override {
        return "The result of vinCheckbox KLIK()";
    }
    std::string pushAndKlik(const Buton& collaborate) const override {
        const std::string result = collaborate.push();
        return "The result of the vinCheckbox collaborating with *** " + result + " ***";
    }
 };

 class macCheckbox : public Checkbox {
    public:
    std::string klik() const override {
        return "The result of macCheckbox KLIK()";
    }
    std::string pushAndKlik(const Buton& collaborate) const override {
        const std::string result = collaborate.push();
        return "The result of the macCheckbox collaborating with *** " + result + " ***";
    }
 };

class Alarm {
    public:
    virtual ~Alarm() = default;
    virtual std::string bell() const = 0;
};

class vinAlarm : public Alarm {
    public:
    std::string bell() const override {
        return "VINalrm:\n"; 
    }
};
class macAlarm : public Alarm {
    public:
    std::string bell() const override {
        return "MACalarm:\n";
    }
};


 class GuiFactory {
    public:
    virtual ~GuiFactory() = default;
    virtual std::shared_ptr<Buton> createButon() const = 0;
    virtual std::shared_ptr<Checkbox> createCheckBox() const = 0;
    virtual std::shared_ptr<Alarm> createAlarm() const = 0;
 };

 class vinFactory : public GuiFactory {
    public:
    std::shared_ptr<Buton> createButon() const override {
        return std::make_shared<vinButon>();
    }
    std::shared_ptr<Checkbox> createCheckBox() const override {
        return std::make_shared<vinCheckbox>();
    }
    std::shared_ptr<Alarm> createAlarm() const override {
        return std::make_shared<vinAlarm>();
    }
 };
 class macFactory : public GuiFactory {
    public:
    std::shared_ptr<Buton> createButon() const override {
        return std::make_shared<macButon>();
    }
    std::shared_ptr<Checkbox> createCheckBox() const override {
        return std::make_shared<macCheckbox>();
    }
    std::shared_ptr<Alarm> createAlarm() const override {
        return std::make_shared<macAlarm>();
    }
 };

 void clientCode(const GuiFactory& factory) {
    const auto buton = factory.createButon();
    const auto checkbox = factory.createCheckBox();
    const auto alarm = factory.createAlarm();
    std::cout << alarm->bell() << "\n";
    std::cout << buton->push() << "\n";
    std::cout << checkbox->pushAndKlik((*buton)) << "\n";
 }