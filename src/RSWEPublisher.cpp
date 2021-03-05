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
 * @file RSWEPublisher.cpp
 *
 */

#include "../include/RSWEPublisher.hpp"

namespace RSWE
{
    RSWEPublisher::PubListener::PubListener()
        : matched_(0)
    {
    }

    RSWEPublisher::PubListener::~PubListener()
    {
    }

    void RSWEPublisher::PubListener::on_publication_matched(
        DataWriter *,
        const PublicationMatchedStatus &info)
    {
        if (info.current_count_change == 1)
        {
            matched_ = info.total_count;
            std::cout << "Publisher matched." << std::endl;
        }
        else if (info.current_count_change == -1)
        {
            matched_ = info.total_count;
            std::cout << "Publisher unmatched." << std::endl;
        }
        else
        {
            std::cout << info.current_count_change
                      << " is not a valid value for PublicationMatchedStatus current count change." << std::endl;
        }
    }

    RSWEPublisher::RSWEPublisher()
        : participant_(nullptr), publisher_(nullptr), topic_(nullptr), writer_(nullptr), type_(new TimeMsgPubSubType())
    {
    }

    RSWEPublisher::~RSWEPublisher()
    {
        if (writer_ != nullptr)
        {
            publisher_->delete_datawriter(writer_);
        }
        if (publisher_ != nullptr)
        {
            participant_->delete_publisher(publisher_);
        }
        if (topic_ != nullptr)
        {
            participant_->delete_topic(topic_);
        }
        DomainParticipantFactory::get_instance()->delete_participant(participant_);
    }

    //!Initialize the publisher
    bool RSWEPublisher::init()
    {
        time_.message("Current time");
        time_.index(0);
        updateTimeMsg();
        DomainParticipantQos participantQos;
        participantQos.name("Participant_publisher");
        participant_ = DomainParticipantFactory::get_instance()->create_participant(0, participantQos);

        if (participant_ == nullptr)
        {
            return false;
        }

        // Register the Type
        type_.register_type(participant_);

        // Create the publications Topic
        topic_ = participant_->create_topic("TimeMsgTopic", "TimeMsg", TOPIC_QOS_DEFAULT);

        if (topic_ == nullptr)
        {
            return false;
        }

        // Create the Publisher
        publisher_ = participant_->create_publisher(PUBLISHER_QOS_DEFAULT, nullptr);

        if (publisher_ == nullptr)
        {
            return false;
        }

        // Create the DataWriter
        writer_ = publisher_->create_datawriter(topic_, DATAWRITER_QOS_DEFAULT, &listener_);

        if (writer_ == nullptr)
        {
            return false;
        }
        return true;
    }

    //!Send a publication
    bool RSWEPublisher::publish()
    {
        if (listener_.matched_ > 0)
        {
            time_.index(time_.index() + 1);
            writer_->write(&time_);
            return true;
        }
        return false;
    }

    //!Run the Publisher
    void RSWEPublisher::run(
        uint32_t samples)
    {
        uint32_t samples_sent = 0;
        std::cout << "Participant: " << static_cast<DomainParticipantQos>(participant_->get_qos()).name()
                  << " [Thread id: " << std::this_thread::get_id() << "]" << std::endl;
        while (samples_sent < samples)
        {
            if (publish())
            {
                samples_sent++;
                updateTimeMsg();
                std::cout << "Message " << time_.index() << " SENT : " << time_.message() << " - "
                          << time_.hour() << " : " << time_.minute() << " : " << time_.second() << std::endl;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    }

    void RSWEPublisher::updateTimeMsg()
    {
        time_t ttime = time(0);
        tm *local_time = localtime(&ttime);

        time_.hour(static_cast<unsigned long>(local_time->tm_hour));
        time_.minute(static_cast<unsigned long>(local_time->tm_min));
        time_.second(static_cast<unsigned long>(local_time->tm_sec));
    }
}