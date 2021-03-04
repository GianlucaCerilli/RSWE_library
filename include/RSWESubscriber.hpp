// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/**
 * @file RSWESubscriber.hpp
 *
 */

#include "../msg/TimeMsgPubSubTypes.h"

#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastdds/dds/domain/DomainParticipant.hpp>
#include <fastdds/dds/topic/TypeSupport.hpp>
#include <fastdds/dds/subscriber/Subscriber.hpp>
#include <fastdds/dds/subscriber/DataReader.hpp>
#include <fastdds/dds/subscriber/DataReaderListener.hpp>
#include <fastdds/dds/subscriber/qos/DataReaderQos.hpp>
#include <fastdds/dds/subscriber/SampleInfo.hpp>

namespace RSWE
{
    using namespace eprosima::fastdds::dds;

    class RSWESubscriber
    {

    private:
        DomainParticipant *participant_;

        Subscriber *subscriber_;

        DataReader *reader_;

        Topic *topic_;

        TypeSupport type_;
        class SubListener : public DataReaderListener
        {
        public:
            SubListener();

            ~SubListener() override;

            void on_subscription_matched(
                DataReader *,
                const SubscriptionMatchedStatus &info) override;

            void on_data_available(
                DataReader *reader) override;

            TimeMsg time_;

            std::atomic_int samples_;

        } listener_;

    public:
        RSWESubscriber();

        virtual ~RSWESubscriber();

        bool init();

        void run(
            uint32_t samples);
    };
}
