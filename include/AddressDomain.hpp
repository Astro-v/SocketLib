#ifndef ADDRESS_DOMAIN_HPP
#define ADDRESS_DOMAIN_HPP

#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <cstring>

/**
 * @brief The domain of the address (e.g. AF_UNIX, AF_INET, etc.)
 */
struct AddressDomain
{
    typedef struct sockaddr AddressType;
    virtual int get_domain() const = 0;
};

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
    };
};

#endif // ADDRESS_DOMAIN_HPP