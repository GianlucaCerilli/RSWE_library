/**
 * @file ThreadsApp.cpp
 *
 */

#include <memory>
#include <thread>
#include <vector>
#include <iostream>

int main(
    int argc,
    char **argv)
{
    std::vector<std::unique_ptr<std::thread>> threads;
    for (int i = 0; i != 5; i++)
    {
        threads.emplace_back(new std::thread([i] {
            std::cout << "I'm thread " << i << "id :" << std::this_thread::get_id() << std::endl;
        }));
    }
    for (auto &thread : threads)
    {
        thread->join();
    }

    return 0;
}
