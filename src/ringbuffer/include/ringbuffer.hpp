#pragma once

#include <boost/circular_buffer.hpp>
#include <mutex>

struct Data {
    int x;
    int y;
};

class RingBuffer final {

public:
    RingBuffer(int buffer_size);
    void add(Data& data);
    void remove();
    Data get();

private:
    boost::circular_buffer<Data> buffer;
    std::mutex m;

};



