#ifndef SEND_SOCKET_HPP
#define SEND_SOCKET_HPP

#include "StreamSocketBase.hpp"

namespace Network::Stream
{
    template <StreamSocketType SST>
    class SendSocket : public SST
    {
    public:
        SendSocket() : SST()
        {
        }

        template <typename... Args>
        SendSocket(Args... args) : SST(std::forward<Args>(args)...)
        {
        }

        /**
         * @brief Move constructor
         * @param other The other send socket
         */
        SendSocket(SendSocket &&other) noexcept : SST(std::move(other)) {}

        virtual ~SendSocket() = default;

        int send(const void *buf, size_t len, int flags = 0)
        {
            return ::send(SST::m_fd.value, buf, len, flags);
        }

        int send(const std::string &buf, int flags = 0)
        {
            return ::send(SST::m_fd.value, buf.c_str(), buf.size(), flags);
        }
    };

} // namespace Network::Stream

#endif // SEND_SOCKET_HPP