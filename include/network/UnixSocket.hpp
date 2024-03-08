#ifndef UNIX_SOCKET_HPP
#define UNIX_SOCKET_HPP

#include "Message.hpp"
#include "SocketStatus.hpp"

namespace Network::Unix
{
    class UnixSocket
    {
        struct Socket;

    public:
        UnixSocket();
        ~UnixSocket();

        void bind();
        SocketStatus send(const Message &message);
        SocketStatus receive(Message &message);
    };
}; // namespace Network::Unix

#endif // UNIX_SOCKET_HPP