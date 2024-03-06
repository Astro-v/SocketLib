#ifndef RECEIVE_FROM_SOCKET_HPP
#define RECEIVE_FROM_SOCKET_HPP

#include "DatagramSocketBase.hpp"

namespace Network::Datagram
{
    template <DatagramSocketType DST>
    class ReceiveFromSocket : public DST
    {
    public:
        ReceiveFromSocket() : DST() {}

        template <typename... Args>
        ReceiveFromSocket(Args... args) : DST(std::forward<Args>(args)...) {}

        /**
         * @brief Move constructor
         * @param other The other receive from socket
         */
        ReceiveFromSocket(ReceiveFromSocket &&other) noexcept : DST(std::move(other)) {}

        virtual ~ReceiveFromSocket() = default;

        typedef decltype(std::declval<DST>().get_domain_address()) Address;

        ssize_t receive_from(void *buffer, size_t length, int flags, Address &src_addr)
        {
            return ::recvfrom(DST::m_fd.value, buffer, length, flags, src_addr.get_address(), &src_addr.get_size());
        }

        ssize_t receive_from(std::string &buffer, size_t length, int flags, Address &src_addr)
        {
            buffer.resize(length);
            return receive_from(buffer.data(), length, flags, src_addr);
        }
    };
} // namespace Network::Datagram

#endif // RECEIVE_FROM_SOCKET_HPP