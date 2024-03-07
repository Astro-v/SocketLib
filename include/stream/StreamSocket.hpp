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
        /**
         * @brief Construct a new Stream Socket object
         */
        StreamSocket();

        /**
         * @brief Construct a new Stream Socket object
         * @param fd The file descriptor of the socket
         */
        StreamSocket(FileDescriptor fd);

        /**
         * @brief Move constructor
         * @param other The other stream socket
         */
        StreamSocket(StreamSocket &&other) noexcept;

        virtual ~StreamSocket() = default;

        /**
         * @brief Get the domain address type of the socket
         * @return Domain::Address The domain address type of the socket
         */
        typename Domain::Address get_domain_address() const;
    };
} // namespace Network

#include "StreamSocket.tpp"

#endif // STREAM_SOCKET_HPP