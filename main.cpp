#include "ringbuffer/include/ringbuffer.hpp"
#include <fmt/core.h>
#include <random>

#include <boost/signals2/signal.hpp>
#include <mutex>
#include <thread>
#include <chrono>

boost::signals2::signal<void(Data)> signal_write;
boost::signals2::signal<Data(void)> signal_read;

struct BufferWriter {

    void loop() {
        for (int i=0; i<10;i++) {
            fmt::print("Adding element {},{}\n", i,i);
            signal_write({i,i});

            std::random_device rd;
            std::mt19937 mt(rd());
            std::uniform_int_distribution<int> dist(400, 500);
            std::this_thread::sleep_for(std::chrono::milliseconds{dist(mt)});
        }
    }

    std::thread writerThread() {
        return std::thread([=] { loop(); });
    }

    std::uniform_int_distribution<int> dist;
};

struct BufferReader {

    void loop() {
        for (int i=0; i<30;i++) {
            Data d = *(signal_read());
            fmt::print("Last element in buffer: {}, {}\n", d.x, d.y);

            std::random_device rd;
            std::mt19937 mt(rd());
            std::uniform_int_distribution<int> dist(100, 300);
            std::this_thread::sleep_for(std::chrono::milliseconds{dist(mt)});

        }
    }

    std::thread readerThread() {
        return std::thread([=] { loop(); });
    }
};

int main()
{
    RingBuffer buffer(4);
    BufferWriter bw;
    BufferReader br;

   signal_write.connect([&buffer](Data d) {
        buffer.add(d);
     });
   signal_read.connect([&buffer]() {
         return buffer.get();
   });

    std::thread t1 = bw.writerThread();
    std::thread t2 = br.readerThread();
    t1.join();
    t2.join();

    return 0;
}
