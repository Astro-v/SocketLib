#include "InetDomain.hpp"

int Network::Inet::InetDomain::get_domain() const
{
    return domain;
}

Network::Inet::InetDomain::Address::Address(const char *ip, int port)
{
    address = std::make_unique<struct sockaddr_in>();
    address->sin_family = domain;
    address->sin_port = ::htons(port);
    ::inet_pton(domain, ip, &address->sin_addr);
    size = std::make_unique<socklen_t>(sizeof(struct sockaddr_in));
}

Network::Inet::InetDomain::Address::Address(struct sockaddr *addr)
{
    address = std::make_unique<struct sockaddr_in>();
    address->sin_family = domain;
    address->sin_port = reinterpret_cast<struct sockaddr_in *>(addr)->sin_port;
    address->sin_addr = reinterpret_cast<struct sockaddr_in *>(addr)->sin_addr;
    size = std::make_unique<socklen_t>(sizeof(struct sockaddr_in));
}

const struct sockaddr *Network::Inet::InetDomain::Address::get_address() const
{
    return reinterpret_cast<struct sockaddr *>(address.get());
}

struct sockaddr *Network::Inet::InetDomain::Address::get_address()
{
    return reinterpret_cast<struct sockaddr *>(address.get());
}

const socklen_t *Network::Inet::InetDomain::Address::get_size() const
{
    return size.get();
}

socklen_t *Network::Inet::InetDomain::Address::get_size()
{
    return size.get();
}