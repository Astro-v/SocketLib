#ifndef LISTEN_SOCKET_HPP
#define LISTEN_SOCKET_HPP

#include "Socket.hpp"
namespace Network
{
    template <SocketType ST>
    class ListenSocket : public ST
    {
    public:
        ListenSocket();

        /**
         * @brief Construct a new Listen Socket object
         * @tparam Args The type of the arguments
         * @param args The arguments
         * @note The arguments are forwarded to the next class constructor as a static decorator
         */
        template <typename... Args>
        ListenSocket(Args... args);

        /**
         * @brief Move constructor
         * @param other The other listen socket
         */
        ListenSocket(ListenSocket &&other) noexcept;

        /**
         * @brief Destructor
         */
        virtual ~ListenSocket() = default;

        /**
         * @brief Listen for connections on a socket
         * @param backlog The maximum length to which the queue of pending connections for sockfd may grow.
         * @return int 0 on success, -1 on error
         */
        int listen(int backlog = 5);
    };
} // namespace Network

#include "ListenSocket.tpp"

#endif // LISTEN_SOCKET_HPP