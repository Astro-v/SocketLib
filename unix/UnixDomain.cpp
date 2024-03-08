#include "UnixDomain.hpp"

int Network::Unix::UnixDomain::get_domain() const
{
    return domain;
}

Network::Unix::UnixDomain::Address::Address(const char *path)
{
    address = std::make_unique<struct sockaddr_un>();
    address->sun_family = domain;
    strncpy(address->sun_path, path, sizeof(address->sun_path));
    size = std::make_unique<socklen_t>(sizeof(struct sockaddr_un));
}

Network::Unix::UnixDomain::Address::Address(struct sockaddr *addr)
{
    address = std::make_unique<struct sockaddr_un>();
    address->sun_family = domain;
    strncpy(address->sun_path, reinterpret_cast<struct sockaddr_un *>(addr)->sun_path, sizeof(address->sun_path));
    size = std::make_unique<socklen_t>(sizeof(struct sockaddr_un));
}

const struct sockaddr *Network::Unix::UnixDomain::Address::get_address() const
{
    return reinterpret_cast<struct sockaddr *>(address.get());
}

struct sockaddr *Network::Unix::UnixDomain::Address::get_address()
{
    return reinterpret_cast<struct sockaddr *>(address.get());
}

const socklen_t *Network::Unix::UnixDomain::Address::get_size() const
{
    return size.get();
}

socklen_t *Network::Unix::UnixDomain::Address::get_size()
{
    return size.get();
}