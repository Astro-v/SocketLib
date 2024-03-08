#ifndef SEND_TO_SOCKET_HPP
#define SEND_TO_SOCKET_HPP

#include "DatagramSocketBase.hpp"

namespace Network::Datagram
{
    template <DatagramSocketType DST>
    class SendToSocket : public DST
    {
    public:
        SendToSocket();

        /**
         * @brief Construct a new Send To Socket object
         * @tparam Args The arguments to forward to the base class
         * @param args The arguments to forward to the base class
         * @note This constructor is used to forward the arguments to the base class
         */
        template <typename... Args>
        SendToSocket(Args... args);

        /**
         * @brief Move constructor
         * @param other The other send to socket
         */
        SendToSocket(SendToSocket &&other) noexcept;

        virtual ~SendToSocket() = default;

        typedef decltype(std::declval<DST>().get_domain_address()) Address;

        /**
         * @brief Send data to a specific address
         * @param buf The buffer to send
         * @param len The length of the buffer
         * @param dest_addr The destination address
         * @param flags The flags to use
         * the possible flags are:
         * - MSG_CONFIRM : Confirm path validity
         * - MSG_DONTROUTE : Bypass routing
         * - MSG_EOR : End of record
         * - MSG_MORE : More data coming
         * - MSG_NOSIGNAL : Do not generate SIGPIPE
         * - MSG_OOB : Out-of-band data
         * @return int The number of bytes sent
         */
        int send_to(const void *buf, size_t len, const Address &dest_addr, int flags = 0);

        /**
         * @brief Send data to a specific address
         * @param buf The buffer to send
         * @param dest_addr The destination address
         * @param flags The flags to use
         * the possible flags are:
         * - MSG_CONFIRM : Confirm path validity
         * - MSG_DONTROUTE : Bypass routing
         * - MSG_EOR : End of record
         * - MSG_MORE : More data coming
         * - MSG_NOSIGNAL : Do not generate SIGPIPE
         * - MSG_OOB : Out-of-band data
         * @return int The number of bytes sent
         */
        int send_to(const std::string &buf, const Address &dest_addr, int flags = 0);
    };

} // namespace Network::Datagram

#include "SendToSocket.tpp"

#endif // SEND_TO_SOCKET_HPP