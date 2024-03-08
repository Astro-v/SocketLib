#ifndef STREAM_SOCKET_BASE_HPP
#define STREAM_SOCKET_BASE_HPP

#include "Socket.hpp"

namespace Network::Stream
{
    /**
     * @brief A stream socket
     */
    class StreamSocketBase : public Socket
    {
    protected:
        StreamSocketBase(int domain);
        StreamSocketBase(FileDescriptor fd);

    public:
        /**
         * @brief Move constructor
         * @param other The other stream socket
         */
        StreamSocketBase(StreamSocketBase &&other) noexcept;

        virtual ~StreamSocketBase() = default;
    };

} // namespace Network::Stream

template <typename T>
concept StreamSocketType = std::is_base_of<Network::Stream::StreamSocketBase, T>::value;

#endif // STREAM_SOCKET_BASE_HPP