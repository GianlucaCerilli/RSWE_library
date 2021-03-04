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
 * @file RSWEPublisher.hpp
 *
 */

#include "../msg/TimeMsgPubSubTypes.h"

#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastdds/dds/domain/DomainParticipant.hpp>
#include <fastdds/dds/topic/TypeSupport.hpp>
#include <fastdds/dds/publisher/Publisher.hpp>
#include <fastdds/dds/publisher/DataWriter.hpp>
#include <fastdds/dds/publisher/DataWriterListener.hpp>

namespace RSWE
{
    using namespace eprosima::fastdds::dds;

    class RSWEPublisher
    {
    private:
        TimeMsg hello_;

        DomainParticipant *participant_;

        Publisher *publisher_;

        Topic *topic_;

        DataWriter *writer_;

        TypeSupport type_;

        class PubListener : public DataWriterListener
        {
        public:
            PubListener();

            ~PubListener() override;

            void on_publication_matched(
                DataWriter *,
                const PublicationMatchedStatus &info) override;

            std::atomic_int matched_;

        } listener_;

    public:
        RSWEPublisher();

        virtual ~RSWEPublisher();

        //!Initialize the publisher
        bool init();

        //!Send a publication
        bool publish();

        //!Run the Publisher
        void run(uint32_t samples);
    };
}