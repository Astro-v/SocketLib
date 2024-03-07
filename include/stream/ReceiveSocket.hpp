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
        /**
         * @brief Construct a new Receive Socket object
         * @note The next class constructor is called as a static decorator
         */
        ReceiveSocket();

        /**
         * @brief Construct a new Receive Socket object
         * @tparam Args The type of the arguments
         * @param args The arguments
         * @note The arguments are forwarded to the next class constructor
         */
        template <typename... Args>
        ReceiveSocket(Args... args);

        /**
         * @brief Move constructor
         * @param other The other receive socket
         */
        ReceiveSocket(ReceiveSocket &&other) noexcept;

        virtual ~ReceiveSocket() = default;

        /**
         * @brief Receive data from a socket
         * @param buffer The buffer to receive the data
         * @param length The length of the buffer
         * @param flags The flags for the receive
         * The flags are :
         * - MSG_DONTWAIT : Non-blocking operation
         * - MSG_OOB : Process out-of-band data
         * - MSG_PEEK : Peek at incoming data
         * - MSG_WAITALL : Wait for full request or error
         * @return ssize_t The number of bytes received
         */
        ssize_t receive(void *buffer, size_t length, int flags);

        /**
         * @brief Receive data from a socket
         * @param buffer The buffer to receive the data
         * @param length The length of the buffer
         * @param flags The flags for the receive
         * The flags are :
         * - MSG_DONTWAIT : Non-blocking operation
         * - MSG_OOB : Process out-of-band data
         * - MSG_PEEK : Peek at incoming data
         * - MSG_WAITALL : Wait for full request or error
         * @return ssize_t The number of bytes received
         */
        ssize_t receive(std::string &buffer, size_t length, int flags);
    };

} // namespace Network::Stream

#include "ReceiveSocket.tpp"

#endif // RECEIVE_SOCKET_HPP