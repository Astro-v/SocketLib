#ifndef ADDRESS_DOMAIN_HPP
#define ADDRESS_DOMAIN_HPP

#include <sys/socket.h>
#include <cstring>

namespace Network
{
    /**
     * @brief The domain of the address (e.g. AF_UNIX, AF_INET, etc.)
     */
    struct AddressDomain
    {
        virtual int get_domain() const = 0;
    };
} // namespace Network

template <typename T>
concept AddressDomainType = std::is_base_of<Network::AddressDomain, T>::value;

#endif // ADDRESS_DOMAIN_HPP