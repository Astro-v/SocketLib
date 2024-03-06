#ifndef CONNECT_SOCKET_HPP
#define CONNECT_SOCKET_HPP

#include "Socket.hpp"

namespace Network
{
    template <SocketType ST>
    class ConnectSocket : public ST
    {
    public:
        ConnectSocket() : ST() {}

        template <typename... Args>
        ConnectSocket(Args... args) : ST(std::forward<Args>(args)...) {}

        /**
         * @brief Move constructor
         * @param other The other connect socket
         */
        ConnectSocket(ConnectSocket &&other) noexcept : ST(std::move(other)) {}

        virtual ~ConnectSocket() = default;

        typedef decltype(std::declval<ST>().get_domain_address()) Address;

        int connect(const Address &addr)
        {
            return ::connect(ST::m_fd.value, addr.get_address(), addr.get_size());
        }
    };
} // namespace Network

#endif // CONNECT_SOCKET_HPP