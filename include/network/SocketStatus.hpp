#ifndef SOCKET_STATUS_HPP
#define SOCKET_STATUS_HPP

namespace Network
{
    enum class SocketStatus
    {
        Done,
        NotReady,
        Disconnected,
        Error
    };
} // namespace Network

#endif // SOCKET_STATUS_HPP