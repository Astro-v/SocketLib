#ifndef INET_DOMAIN_HPP
#define INET_DOMAIN_HPP

#include <netinet/in.h>
#include <arpa/inet.h>
#include "AddressDomain.hpp"

namespace Network::Inet
{
    struct InetDomain : public AddressDomain
    {
        static const int domain = AF_INET;

        int get_domain() const override
        {
            return AF_INET;
        }

        struct Address
        {
            struct sockaddr_in address;
            socklen_t size;

            Address() = default;

            Address(const char *ip, int port)
            {
                address.sin_family = domain;
                address.sin_port = ::htons(port);
                ::inet_pton(domain, ip, &address.sin_addr);
                size = sizeof(address);
            }

            Address(struct sockaddr *addr)
            {
                address.sin_family = domain;
                address.sin_port = ((struct sockaddr_in *)addr)->sin_port;
                address.sin_addr = ((struct sockaddr_in *)addr)->sin_addr;
                size = sizeof(address);
            }

            struct sockaddr *get_address() const
            {
                return (struct sockaddr *)&address;
            }

            socklen_t get_size() const
            {
                return size;
            }
        };
    };

} // namespace Network::Inet
#endif // INET_DOMAIN_HPP