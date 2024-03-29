#ifndef ACCEPT_SOCKET_HPP
#define ACCEPT_SOCKET_HPP

#include "Socket.hpp"

namespace Network
{
    template <SocketType ST, SocketType AcceptedSocket>
    class AcceptSocket : public ST
    {
    public:
        AcceptSocket() : ST()
        {
        }

        template <typename... Args>
        AcceptSocket(Args... args) : ST(std::forward<Args>(args)...)
        {
        }

        /**
         * @brief Move constructor
         * @param other The other accept socket
         */
        AcceptSocket(AcceptSocket &&other) noexcept : ST(std::move(other)) {}

        virtual ~AcceptSocket() = default;

        typedef decltype(std::declval<AcceptedSocket>().get_domain_address()) Address;

        AcceptedSocket accept(Address *address)
        {
            struct sockaddr *sa;
            socklen_t *sl;
            int client_fd = ::accept(ST::m_fd, sa, sl);
            std::cout << client_fd << std::endl;
            address = new Address(sa, sl);
            return AcceptedSocket(client_fd);
        }
    };

} // namespace Network
#endif // ACCEPT_SOCKET_HPP