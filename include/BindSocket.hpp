#ifndef BIND_SOCKET_HPP
#define BIND_SOCKET_HPP

#include "Socket.hpp"

template <SocketType ST>
class BindSocket : public ST
{
public:
    BindSocket() : ST()
    {
    }

    template <typename... Args>
    BindSocket(Args... args) : ST(std::forward<Args>(args)...)
    {
    }

    virtual ~BindSocket() = default;

    // set the type of the address to be passed to bind
    typedef decltype(std::declval<ST>().get_domain_address()) Address;

    int bind(const Address &address)
    {
        return ::bind(ST::m_fd, address.get_address(), address.get_size());
    }
};

#endif // BIND_SOCKET_HPP