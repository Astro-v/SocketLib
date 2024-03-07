#ifndef UNIX_DOMAIN_HPP
#define UNIX_DOMAIN_HPP

#include <sys/socket.h>
#include <sys/un.h>
#include "AddressDomain.hpp"

namespace Network::Unix
{
    struct UnixDomain : public AddressDomain
    {
        static const int domain = AF_UNIX;

        int get_domain() const override
        {
            return domain;
        }

        struct Address
        {
            struct sockaddr_un address;
            socklen_t size;

            Address() = default;

            Address(const char *path)
            {
                address.sun_family = domain;
                strncpy(address.sun_path, path, sizeof(address.sun_path));
                size = sizeof(address);
            }

            Address(struct sockaddr *addr)
            {
                address.sun_family = domain;
                strncpy(address.sun_path, ((struct sockaddr_un *)addr)->sun_path, sizeof(address.sun_path));
                size = sizeof(address);
            }

            const struct sockaddr *get_address() const
            {
                return (struct sockaddr *)&address;
            }

            struct sockaddr *get_address()
            {
                return (struct sockaddr *)&address;
            }

            const socklen_t &get_size() const
            {
                return size;
            }

            socklen_t &get_size()
            {
                return size;
            }
        };
    };
} // namespace Network::Unix
#endif // UNIX_DOMAIN_HPP