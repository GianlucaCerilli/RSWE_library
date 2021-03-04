/**
 * @file ThreadsApp.cpp
 *
 */

#include "../include/RSWEPublisher.hpp"
#include "../include/RSWESubscriber.hpp"

using namespace RSWE;

int main()
{
    /* Publisher thread streams messages.
    ** Subscriber thread keeps listening. */
    uint32_t samples{10};

    std::vector<std::unique_ptr<std::thread>> threads;

    threads.emplace_back(new std::thread([&samples] {
        std::unique_ptr<RSWEPublisher> pub(new RSWEPublisher());
        if (pub->init())
        {
            pub->run(samples);
        }
    }));

    threads.emplace_back(new std::thread([&samples] {
        std::unique_ptr<RSWESubscriber> sub(new RSWESubscriber());
        if (sub->init())
        {
            sub->run(samples);
        }
    }));

    for (auto &thread : threads)
    {
        thread->join();
    }
}