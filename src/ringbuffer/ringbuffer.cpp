#include "include/ringbuffer.hpp"
#include <thread>
#include <fmt/core.h>


RingBuffer::RingBuffer(int buffer_size)
    : buffer(buffer_size)
{
}

void RingBuffer::add(Data& data)
{
    std::lock_guard<std::mutex> lock{m};
    buffer.push_back(data);
    fmt::print("[BUFFER] data ({},{}) added, releasing lock.\n", data.x, data.y);
}

Data RingBuffer::get()
{
    std::lock_guard<std::mutex> lock{m};
    return buffer.back();
}


