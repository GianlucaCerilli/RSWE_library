/**
 * @file SubscriberApp.cpp
 *
 */

#include "../include/RSWESubscriber.hpp"

using namespace RSWE;

int main()
{
    std::cout << "Starting subscriber." << std::endl;

    int samples{2};

    std::unique_ptr<RSWESubscriber> sub(new RSWESubscriber());

    if (sub->init())
    {
        sub->run(static_cast<uint32_t>(samples));
    }
}
