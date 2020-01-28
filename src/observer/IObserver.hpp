#pragma once

class IObserver {
public:
    virtual void notify() = 0;
    virtual ~IObserver() = default;
};
