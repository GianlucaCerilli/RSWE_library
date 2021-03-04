#include <memory>
#include "RSWEPublisher.hpp"

using namespace RSWE;

int main(
    int argc,
    char **argv)
{
    std::cout << "Starting publisher." << std::endl;

    int samples = 10;

    std::unique_ptr<RSWEPublisher> mypub(new RSWEPublisher());
    //RSWEPublisher *mypub = new RSWEPublisher();

    if (mypub->init())
    {
        mypub->run(static_cast<uint32_t>(samples));
    }

    //delete mypub;

    return 0;
}
