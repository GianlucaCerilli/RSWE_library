/**
 * @file ThreadsApp.cpp
 *
 */

#include "../include/RSWEPublisher.hpp"
#include "../include/RSWESubscriber.hpp"

using namespace RSWE;

int main()
{
    /* Subscriber wants to read a single message from the topic.
    ** Publisher thread is activated. */

    std::unique_ptr<RSWESubscriber> sub(new RSWESubscriber());

    if (sub->init())
    {
        uint32_t samples{1};

        std::unique_ptr<std::thread> thread(new std::thread([&samples] {
            std::unique_ptr<RSWEPublisher> pub(new RSWEPublisher());
            if (pub->init())
            {
                pub->run(samples);
            }
        }));

        thread->join();

        sub->run(static_cast<uint32_t>(samples));
    }
}