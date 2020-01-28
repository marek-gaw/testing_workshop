#pragma once

#include "IObserver.hpp"

class IObservable {
public:
    virtual void registerObserver(IObserver* o) = 0;
    virtual void unregisterAllObservers() = 0;
    virtual void update() = 0;
    virtual ~IObservable() = default;
};
