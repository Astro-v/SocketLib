#ifndef STREAM_SOCKET_HPP
#define STREAM_SOCKET_HPP

#include "Socket.hpp"
#include "AddressDomain.hpp"
namespace Network
{
    /**
     * @brief A stream socket
     * @tparam Domain The domain of the socket (e.g. UnixDomain, InetDomain, etc.)
     */
    template <AddressDomainType Domain>
    class StreamSocket : public Socket
    {
        // The domain of the socket (e.g. AF_INET, AF_UNIX, etc.)
        Domain m_domain;

    public:
        StreamSocket() : Socket(m_domain.get_domain(), SOCK_STREAM) {}
        StreamSocket(int fd) : Socket(fd) {}

        /**
         * @brief Move constructor
         * @param other The other stream socket
         */
        StreamSocket(StreamSocket &&other) noexcept : Socket(std::move(other)), m_domain(other.m_domain) {}

        virtual ~StreamSocket() = default;

        typename Domain::Address get_domain_address() const { return m_domain.Address; }
    };
} // namespace Network

template <typename T, typename Domain>
concept StreamSocketType = std::is_base_of<Network::StreamSocket<Domain>, T>::value;

#endif // STREAM_SOCKET_HPP