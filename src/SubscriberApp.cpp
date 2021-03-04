/**
 * @file SubscriberApp.cpp
 *
 */

#include <memory>
#include "../include/RSWESubscriber.hpp"

using namespace RSWE;

int main(
    int argc,
    char **argv)
{
    std::cout << "Starting subscriber." << std::endl;

    int samples = 10;

    std::unique_ptr<RSWESubscriber> mysub(new RSWESubscriber());

    if (mysub->init())
    {
        mysub->run(static_cast<uint32_t>(samples));
    }

    return 0;
}
