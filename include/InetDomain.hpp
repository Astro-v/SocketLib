#ifndef INET_DOMAIN_HPP
#define INET_DOMAIN_HPP

#include <netinet/in.h>
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

            struct sockaddr *get_address() const
            {
                return (struct sockaddr *)&address;
            }

            socklen_t get_size() const
            {
                return size;
            }

            void set_address(const struct sockaddr *addr, socklen_t len)
            {
                memcpy(&address, addr, len);
                size = len;
            }
        };
    };

} // namespace Network::Inet
#endif // INET_DOMAIN_HPP