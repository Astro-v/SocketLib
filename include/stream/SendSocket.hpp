#ifndef SEND_SOCKET_HPP
#define SEND_SOCKET_HPP

#include "StreamSocketBase.hpp"

namespace Network::Stream
{
    template <StreamSocketType SST>
    class SendSocket : public SST
    {
    public:
        /**
         * @brief Construct a new Send Socket object
         * @note The next class constructor is called as a static decorator
         */
        SendSocket();

        /**
         * @brief Construct a new Send Socket object
         * @tparam Args The type of the arguments
         * @param args The arguments
         * @note The arguments are forwarded to the next class constructor
         */
        template <typename... Args>
        SendSocket(Args... args);

        /**
         * @brief Move constructor
         * @param other The other send socket
         */
        SendSocket(SendSocket &&other) noexcept;

        virtual ~SendSocket() = default;

        /**
         * @brief Send data to a socket
         * @param buf The buffer to send
         * @param len The length of the buffer
         * @param flags The flags for the send
         * The flags are :
         * - MSG_CONFIRM : Confirm path validity
         * - MSG_DONTROUTE : Bypass routing
         * - MSG_DONTWAIT : Non-blocking operation
         * - MSG_EOR : End of record
         * - MSG_MORE : More data coming
         * - MSG_NOSIGNAL : Do not generate a signal
         * - MSG_OOB : Process out-of-band data
         * @return int The number of bytes sent
         * @note The MSG_NOSIGNAL flag is added to the flags by default
         */
        int send(const void *buf, size_t len, int flags = 0);

        /**
         * @brief Send data to a socket
         * @param buf The buffer to send
         * @param flags The flags for the send
         * The flags are :
         * - MSG_CONFIRM : Confirm path validity
         * - MSG_DONTROUTE : Bypass routing
         * - MSG_DONTWAIT : Non-blocking operation
         * - MSG_EOR : End of record
         * - MSG_MORE : More data coming
         * - MSG_NOSIGNAL : Do not generate a signal
         * - MSG_OOB : Process out-of-band data
         * @return int The number of bytes sent
         * @note The MSG_NOSIGNAL flag is added to the flags by default
         */
        int send(const std::string &buf, int flags = 0);
    };

} // namespace Network::Stream

#include "SendSocket.tpp"

#endif // SEND_SOCKET_HPP