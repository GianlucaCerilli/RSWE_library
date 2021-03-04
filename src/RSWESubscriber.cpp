#include "../include/RSWESubscriber.hpp"

namespace RSWE
{
    RSWESubscriber::SubListener::SubListener()
        : samples_(0)
    {
    }

    RSWESubscriber::SubListener::~SubListener()
    {
    }

    void RSWESubscriber::SubListener::on_subscription_matched(
        DataReader *,
        const SubscriptionMatchedStatus &info)
    {
        if (info.current_count_change == 1)
        {
            std::cout << "Subscriber matched." << std::endl;
        }
        else if (info.current_count_change == -1)
        {
            std::cout << "Subscriber unmatched." << std::endl;
        }
        else
        {
            std::cout << info.current_count_change
                      << " is not a valid value for SubscriptionMatchedStatus current count change" << std::endl;
        }
    }

    void RSWESubscriber::SubListener::on_data_available(
        DataReader *reader)
    {
        SampleInfo info;
        if (reader->take_next_sample(&hello_, &info) == ReturnCode_t::RETCODE_OK)
        {
            if (info.valid_data)
            {
                samples_++;
                std::cout << "Message: " << hello_.message() << " with index: " << hello_.index()
                          << " RECEIVED." << std::endl;
            }
        }
    }

    RSWESubscriber::RSWESubscriber()
        : participant_(nullptr), subscriber_(nullptr), topic_(nullptr), reader_(nullptr), type_(new TimeMsgPubSubType())
    {
    }

    RSWESubscriber::~RSWESubscriber()
    {
        if (reader_ != nullptr)
        {
            subscriber_->delete_datareader(reader_);
        }
        if (topic_ != nullptr)
        {
            participant_->delete_topic(topic_);
        }
        if (subscriber_ != nullptr)
        {
            participant_->delete_subscriber(subscriber_);
        }
        DomainParticipantFactory::get_instance()->delete_participant(participant_);
    }

    bool RSWESubscriber::init()
    {
        DomainParticipantQos participantQos;
        participantQos.name("Participant_subscriber");
        participant_ = DomainParticipantFactory::get_instance()->create_participant(0, participantQos);

        if (participant_ == nullptr)
        {
            return false;
        }

        // Register the Type
        type_.register_type(participant_);

        // Create the subscriptions Topic
        topic_ = participant_->create_topic("TimeMsgTopic", "TimeMsg", TOPIC_QOS_DEFAULT);

        if (topic_ == nullptr)
        {
            return false;
        }

        // Create the Subscriber
        subscriber_ = participant_->create_subscriber(SUBSCRIBER_QOS_DEFAULT, nullptr);

        if (subscriber_ == nullptr)
        {
            return false;
        }

        // Create the DataReader
        reader_ = subscriber_->create_datareader(topic_, DATAREADER_QOS_DEFAULT, &listener_);

        if (reader_ == nullptr)
        {
            return false;
        }

        return true;
    }

    void RSWESubscriber::run(
        uint32_t samples)
    {
        std::cout << "Name : " << static_cast<DomainParticipantQos>(participant_->get_qos()).name() << std::endl;
        while (listener_.samples_ < samples)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }

}
