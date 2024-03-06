#ifndef STREAM_SOCKET_HPP
#define STREAM_SOCKET_HPP

#include "StreamSocketBase.hpp"
#include "AddressDomain.hpp"

namespace Network::Stream
{
    /**
     * @brief A stream socket with a specific domain
     * @tparam Domain The domain of the socket (e.g. UnixDomain, InetDomain, etc.)
     */
    template <AddressDomainType Domain>
    class StreamSocket : public StreamSocketBase
    {
        // The domain of the socket (e.g. AF_INET, AF_UNIX, etc.)
        Domain m_domain;

    public:
        StreamSocket() : StreamSocketBase(m_domain.get_domain())
        {
            std::cout << "StreamSocket" << std::endl;
        }

        StreamSocket(FileDescriptor fd) : StreamSocketBase(fd) {}

        /**
         * @brief Move constructor
         * @param other The other stream socket
         */
        StreamSocket(StreamSocket &&other) noexcept : StreamSocketBase(std::move(other)), m_domain(other.m_domain) {}

        virtual ~StreamSocket() = default;

        typename Domain::Address get_domain_address() const { return m_domain.Address; }
    };
} // namespace Network

#endif // STREAM_SOCKET_HPP