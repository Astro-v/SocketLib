#ifndef RECEIVE_SOCKET_HPP
#define RECEIVE_SOCKET_HPP

#include "StreamSocketBase.hpp"

namespace Network::Stream
{
    /**
     * @brief A receive socket
     */
    template <StreamSocketType SST>
    class ReceiveSocket : public SST
    {
    public:
        ReceiveSocket() : SST() {}

        template <typename... Args>
        ReceiveSocket(Args... args) : SST(std::forward<Args>(args)...) {}

        /**
         * @brief Move constructor
         * @param other The other receive socket
         */
        ReceiveSocket(ReceiveSocket &&other) noexcept : SST(std::move(other)) {}

        virtual ~ReceiveSocket() = default;

        ssize_t receive(void *buffer, size_t length, int flags)
        {
            return ::recv(SST::m_fd.value, buffer, length, flags);
        }

        ssize_t receive(std::string &buffer, size_t length, int flags)
        {
            buffer.resize(length);
            return receive(buffer.data(), length, flags);
        }
    };

} // namespace Network::Stream

#endif // RECEIVE_SOCKET_HPP