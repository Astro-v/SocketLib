#ifndef ACCEPT_SOCKET_HPP
#define ACCEPT_SOCKET_HPP

#include "Socket.hpp"

template <typename Domain, typename ST>
    requires SocketType<ST, Domain>
class AcceptSocket : public ST
{
public:
    AcceptSocket() : ST()
    {
    }

    template <typename... Args>
    AcceptSocket(Args... args) : ST(std::forward<Args>(args...))
    {
    }

    virtual ~AcceptSocket() = default;

    template <typename U, typename T>
        requires SocketType<T, U>
    void accept(T &socket, Address<Domain> &address)
    {
        struct sockaddr *sa;
        socklen_t *address_len;
        socket.m_fd = ::accept(ST::m_fd, sa, address_len);
        address.m_address = *reinterpret_cast < decltype

                            return ::accept(ST::m_fd, address, address_len);
    }
};

#endif // ACCEPT_SOCKET_HPP