#ifndef DATAGRAM_SOCKET_HPP
#define DATAGRAM_SOCKET_HPP

#include "Socket.hpp"
#include "AddressDomain.hpp"

namespace Network
{
    /**
     * @brief A datagram socket
     * @tparam Domain The domain of the socket (e.g. UnixDomain, InetDomain, etc.)
     */
    template <AddressDomainType Domain>
    class DatagramSocket : public Socket
    {
        // The domain of the socket (e.g. AF_INET, AF_UNIX, etc.)
        Domain m_domain;

    public:
        DatagramSocket() : Socket(m_domain.get_domain(), SOCK_DGRAM) {}
        DatagramSocket(int fd) : Socket(fd) {}

        /**
         * @brief Move constructor
         * @param other The other datagram socket
         */
        DatagramSocket(DatagramSocket &&other) noexcept : Socket(std::move(other)), m_domain(other.m_domain) {}

        virtual ~DatagramSocket() = default;

        typename Domain::Address get_domain_address() const { return m_domain.Address; }
    };
} // namespace Network

template <typename T, typename Domain>
concept DatagramSocketType = std::is_base_of<Network::DatagramSocket<Domain>, T>::value;

#endif // DATAGRAM_SOCKET_HPP