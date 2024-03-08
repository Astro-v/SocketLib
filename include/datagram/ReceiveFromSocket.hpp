#ifndef RECEIVE_FROM_SOCKET_HPP
#define RECEIVE_FROM_SOCKET_HPP

#include "DatagramSocketBase.hpp"

namespace Network::Datagram
{
    template <DatagramSocketType DST>
    class ReceiveFromSocket : public DST
    {
    public:
        ReceiveFromSocket();

        template <typename... Args>
        ReceiveFromSocket(Args... args);

        /**
         * @brief Move constructor
         * @param other The other receive from socket
         */
        ReceiveFromSocket(ReceiveFromSocket &&other) noexcept;

        virtual ~ReceiveFromSocket() = default;

        typedef decltype(std::declval<DST>().get_domain_address()) Address;

        /**
         * @brief Receive data from a socket
         * @param buffer The buffer to store the data
         * @param length The length of the buffer
         * @param src_addr The address of the sender
         * @param flags The flags to pass to recvfrom
         * the possible flags are:
         * - MSG_DONTWAIT : Non-blocking operation
         * - MSG_OOB : Process out-of-band data
         * - MSG_PEEK : Peek at incoming data
         * - MSG_WAITALL : Wait for full request or error
         * @return The number of bytes received
         */
        ssize_t receive_from(void *buffer, size_t length, Address &src_addr, int flags = 0);

        ssize_t receive_from(std::string &buffer, size_t length, Address &src_addr, int flags = 0);
    };

} // namespace Network::Datagram

#include "ReceiveFromSocket.tpp"

#endif // RECEIVE_FROM_SOCKET_HPP