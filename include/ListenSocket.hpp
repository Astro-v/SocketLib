#ifndef LISTEN_SOCKET_HPP
#define LISTEN_SOCKET_HPP

#include "Socket.hpp"

template <typename Domain, typename ST>
    requires SocketType<ST, Domain>
class ListenSocket : public ST
{
public:
    ListenSocket() : ST()
    {
    }

    template <typename... Args>
    ListenSocket(Args... args) : ST(std::forward<Args>(args...))
    {
    }

    virtual ~ListenSocket() = default;

    int listen(int backlog)
    {
        return ::listen(ST::m_fd, backlog);
    }
};

#endif // LISTEN_SOCKET_HPP