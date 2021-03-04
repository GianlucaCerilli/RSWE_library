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

    std::unique_ptr<RSWESubscriber> mysub(new RSWESubscriber());

    if (mysub->init())
    {
        mysub->run(static_cast<uint32_t>(samples));
    }
}
