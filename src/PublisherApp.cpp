/**
 * @file PublisherApp.cpp
 *
 */

#include "../include/RSWEPublisher.hpp"

using namespace RSWE;

int main()
{
    std::cout << "Starting publisher." << std::endl;

    int samples{2};

    std::unique_ptr<RSWEPublisher> pub(new RSWEPublisher());

    if (pub->init())
    {
        pub->run(static_cast<uint32_t>(samples));
    }
}
