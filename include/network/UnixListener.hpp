#ifndef UNIX_LISTENER_HPP
#define UNIX_LISTENER_HPP

#include <memory>
#include "UnixSocket.hpp"

namespace Network::Unix
{
    class UnixListener
    {
        struct Socket;
        std::unique_ptr<Socket> socket;

    public:
        UnixListener(const char *path);
        ~UnixListener() = default;

        void listen();
        UnixSocket accept();
    };

} // namespace Network::Unix

#endif // UNIX_LISTENER_HPP