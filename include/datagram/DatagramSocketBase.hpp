#ifndef DATAGRAM_SOCKET_BASE_HPP
#define DATAGRAM_SOCKET_BASE_HPP

#include "Socket.hpp"
#include "AddressDomain.hpp"

namespace Network::Datagram
{
    /**
     * @brief A datagram socket
     * @tparam Domain The domain of the socket (e.g. UnixDomain, InetDomain, etc.)
     */
    class DatagramSocketBase : public Socket
    {
    protected:
        DatagramSocketBase(AddressDomain &domain) : Socket(domain.get_domain(), SOCK_DGRAM) {}
        DatagramSocketBase(FileDescriptor fd) : Socket(fd) {}

    public:
        /**
         * @brief Move constructor
         * @param other The other datagram socket
         */
        DatagramSocketBase(DatagramSocketBase &&other) noexcept : Socket(std::move(other)) {}

        virtual ~DatagramSocketBase() = default;
    };
} // namespace Network

template <typename T>
concept DatagramSocketType = std::is_base_of<Network::Datagram::DatagramSocketBase, T>::value;

#endif // DATAGRAM_SOCKET_BASE_HPP