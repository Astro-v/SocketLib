#ifndef LISTEN_SOCKET_HPP
#define LISTEN_SOCKET_HPP

#include "Socket.hpp"
namespace Network
{
    template <SocketType ST>
    class ListenSocket : public ST
    {
    public:
        ListenSocket() : ST() {}

        template <typename... Args>
        ListenSocket(Args... args) : ST(std::forward<Args>(args)...)
        {
        }

        /**
         * @brief Move constructor
         * @param other The other listen socket
         */
        ListenSocket(ListenSocket &&other) noexcept : ST(std::move(other)) {}

        virtual ~ListenSocket() = default;

        int listen(int backlog = 5)
        {
            return ::listen(ST::m_fd.value, backlog);
        }
    };
} // namespace Network

#endif // LISTEN_SOCKET_HPP