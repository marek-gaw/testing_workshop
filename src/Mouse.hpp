#pragma once

#include "observer/IObservable.hpp"
#include "observer/IObserver.hpp"

#include <vector>
#include <memory>

class Mouse : public IObservable {

public:
    virtual ~Mouse() = default;
    void registerObserver(IObserver* o) override;
    void unregisterAllObservers() override;
    void update() override;
private:
    std::vector<IObserver*> observers;
};
