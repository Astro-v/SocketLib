
template <SocketType ST>
Network::ListenSocket<ST>::ListenSocket() : ST()
{
}

template <SocketType ST>
template <typename... Args>
Network::ListenSocket<ST>::ListenSocket(Args... args) : ST(std::forward<Args>(args)...)
{
}

template <SocketType ST>
Network::ListenSocket<ST>::ListenSocket(ListenSocket &&other) noexcept : ST(std::move(other))
{
}
template <SocketType ST>
int Network::ListenSocket<ST>::listen(int backlog)
{
    return ::listen(ST::m_fd.value, backlog);
}