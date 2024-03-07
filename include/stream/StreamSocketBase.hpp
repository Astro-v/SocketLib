#ifndef STREAM_SOCKET_BASE_HPP
#define STREAM_SOCKET_BASE_HPP

#include "Socket.hpp"
#include "AddressDomain.hpp"

namespace Network::Stream
{
    /**
     * @brief A stream socket
     */
    class StreamSocketBase : public Socket
    {
    protected:
        StreamSocketBase(int domain) : Socket(domain, SOCK_STREAM) {}
        StreamSocketBase(FileDescriptor fd) : Socket(fd) {}

    public:
        /**
         * @brief Move constructor
         * @param other The other stream socket
         */
        StreamSocketBase(StreamSocketBase &&other) noexcept : Socket(std::move(other)) {}

        virtual ~StreamSocketBase() = default;
    };

} // namespace Network::Stream

template <typename T>
concept StreamSocketType = std::is_base_of<Network::Stream::StreamSocketBase, T>::value;

#endif // STREAM_SOCKET_BASE_HPP