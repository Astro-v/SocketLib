#ifndef UNIX_DOMAIN_HPP
#define UNIX_DOMAIN_HPP

#include <memory>
#include <sys/socket.h>
#include <sys/un.h>
#include "AddressDomain.hpp"

namespace Network::Unix
{
    struct UnixDomain : public AddressDomain
    {
        /**
         * @brief The domain of the address
         * AF_UNIX is used for Unix domain sockets
         * AF_INET is used for IPv4
         * AF_INET6 is used for IPv6
         * AF_UNSPEC is used for unspecified
         * etc.
         */
        static const int domain = AF_UNIX;

        /**
         * @brief Get the domain of the address e.g. AF_UNIX, AF_INET, etc.
         */
        int get_domain() const override;

        struct Address
        {
            /**
             * @brief The address of the Unix domain socket
             */
            std::unique_ptr<struct sockaddr_un> address;

            /**
             * @brief The size of the address
             */
            std::unique_ptr<socklen_t> size;

            Address() = default;

            /**
             * @brief Construct a new Address object
             * @param path The path to the Unix domain socket
             */
            Address(const char *path);

            /**
             * @brief Construct a new Address object
             * @param addr The address to copy
             */
            Address(struct sockaddr *addr);

            /**
             * @brief Get the address object
             * @return const struct sockaddr* The address object
             */
            const struct sockaddr *get_address() const;

            /**
             * @brief Get the address object
             * @return struct sockaddr* The address object
             */
            struct sockaddr *get_address();

            /**
             * @brief Get the size object
             * @return const socklen_t* The size object
             */
            const socklen_t *get_size() const;

            /**
             * @brief Get the size object
             * @return socklen_t* The size object
             */
            socklen_t *get_size();
        };
    };
} // namespace Network::Unix

#endif // UNIX_DOMAIN_HPP