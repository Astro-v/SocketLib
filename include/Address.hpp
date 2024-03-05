#ifndef ADDRESS_HPP
#define ADDRESS_HPP

/*#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "AddressDomain.hpp"

struct UnixAddress
{
    struct sockaddr_un address;
    socklen_t size;

    UnixAddress(const char *path)
    {
        address.sun_family = AF_UNIX;
        strncpy(address.sun_path, path, sizeof(address.sun_path));
        size = sizeof(address);
    }
}

class UnixAddress : public Address
{
protected:
    UnixDomain::AddressType m_address;
    UnixDomain m_domain;

public:
    UnixAddress(const char *path)
    {
        m_address.sun_family = m_domain.get_domain();
        strncpy(m_address.sun_path, path, sizeof(m_address.sun_path));
    }

    struct sockaddr *get_address()
    {
        return reinterpret_cast<struct sockaddr *>(&m_address);
    }

    socklen_t get_size()
    {
        return sizeof(m_address);
    }
};

template <>
class InetAddress
{
    InetDomain::AddressType m_address;
    InetDomain m_domain;

public:
    Address(const char *ip, int port)
    {
        m_address.sin_family = m_domain.get_domain();
        m_address.sin_port = htons(port);
        inet_pton(m_domain.get_domain(), ip, &m_address.sin_addr);
    }

    struct sockaddr *get_address()
    {
        return reinterpret_cast<struct sockaddr *>(&m_address);
    }

    socklen_t get_size()
    {
        return sizeof(m_address);
    }
};

typedef Address<UnixDomain> UnixAddress;
typedef Address<InetDomain> InetAddress;
*/
#endif // ADDRESS_HPP