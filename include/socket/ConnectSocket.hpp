#ifndef CONNECT_SOCKET_HPP
#define CONNECT_SOCKET_HPP

#include "Socket.hpp"

namespace Network
{
    template <SocketType ST>
    class ConnectSocket : public ST
    {
    public:
        ConnectSocket();

        template <typename... Args>
        ConnectSocket(Args... args);

        /**
         * @brief Move constructor
         * @param other The other connect socket
         */
        ConnectSocket(ConnectSocket &&other) noexcept;

        virtual ~ConnectSocket() = default;

        typedef decltype(std::declval<ST>().get_domain_address()) Address;

        int connect(const Address &addr);
    };
} // namespace Network

#include "ConnectSocket.tpp"

#endif // CONNECT_SOCKET_HPP