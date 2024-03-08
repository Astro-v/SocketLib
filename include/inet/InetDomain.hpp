#ifndef INET_DOMAIN_HPP
#define INET_DOMAIN_HPP

#include <memory>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "AddressDomain.hpp"

namespace Network::Inet
{
    struct InetDomain : public AddressDomain
    {
        /**
         * @brief The domain of the address
         * AF_UNIX is used for Unix domain sockets
         * AF_INET is used for IPv4
         * AF_INET6 is used for IPv6
         * AF_UNSPEC is used for unspecified
         * etc.
         */
        static const int domain = AF_INET;

        /**
         * @brief Get the domain of the address e.g. AF_UNIX, AF_INET, etc.
         * @return int The domain of the address
         */
        int get_domain() const override;

        struct Address
        {
            /**
             * @brief The address of the internet domain socket
             */
            std::unique_ptr<struct sockaddr_in> address;

            /**
             * @brief The size of the address
             */
            std::unique_ptr<socklen_t> size;

            Address() = default;

            /**
             * @brief Construct a new Address object
             * @param ip The IP address
             * @param port The port
             * @note The IP address should be in the form "xxx.xxx.xxx.xxx"
             * @note The port should be in the range 0-65535
             */
            Address(const char *ip, int port);

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
             * @return const socklen_t& The size object
             */
            const socklen_t *get_size() const;

            /**
             * @brief Get the size object
             * @return socklen_t& The size object
             */
            socklen_t *get_size();
        };
    };

} // namespace Network::Inet
#endif // INET_DOMAIN_HPP