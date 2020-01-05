#pragma once

#include "observer/IObserver.hpp"
#include <string>

class Cat : public IObserver {

public:
    Cat(std::string name);
    virtual ~Cat() = default;
    void notify() override;

private:
    std::string name;
};
