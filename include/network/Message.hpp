#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <string>

namespace Network
{
    class Message
    {
    public:
        Message() = default;
        virtual ~Message() = default;
        virtual const std::string &get_message() const = 0;
        virtual std::string &get_message() = 0;
    };

    class StringMessage : public Message
    {
    protected:
        std::string data;

    public:
        StringMessage() = default;

        StringMessage(const std::string &message) : data(message) {}

        virtual ~StringMessage() = default;

        const std::string &get_message() const override
        {
            return data;
        }

        std::string &get_message() override
        {
            return data;
        }
    };

} // namespace Network

#endif // MESSAGE_HPP