#ifndef DATAGRAM_SOCKET_HPP
#define DATAGRAM_SOCKET_HPP

#include "DatagramSocketBase.hpp"
#include "AddressDomain.hpp"

namespace Network::Datagram
{
    /**
     * @brief A datagram socket with a specific domain
     * @tparam Domain The domain of the socket (e.g. UnixDomain, InetDomain, etc.)
     */
    template <AddressDomainType Domain>
    class DatagramSocket : public DatagramSocketBase
    {
        // The domain of the socket (e.g. AF_INET, AF_UNIX, etc.)
        Domain m_domain;

    public:
        DatagramSocket();
        DatagramSocket(FileDescriptor fd);

        /**
         * @brief Move constructor
         * @param other The other datagram socket
         */
        DatagramSocket(DatagramSocket &&other) noexcept;

        virtual ~DatagramSocket() = default;

        typename Domain::Address get_domain_address() const;
    };

} // namespace Network

#include "DatagramSocket.tpp"

#endif // DATAGRAM_SOCKET_HPP