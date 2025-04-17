#pragma once

#include <thread>
#include <functional>
#include <chrono>
#include <vector>

void theSleep(float time, int num_threads)
{
    using theClock = std::chrono::high_resolution_clock;
    using duration = std::chrono::duration<float>;
    std::vector<std::thread> threads(num_threads);
    for (int i = 0; i < num_threads; i++)
        threads[i] = std::thread([time]()
        {
            auto start = theClock::now();
            int x = 0;
            while (((duration)(theClock::now() - start)).count() < time)
                x = (x * 127 + 257) % 19260817;
        });
    
    for (auto& thread: threads)
        thread.join();
}
