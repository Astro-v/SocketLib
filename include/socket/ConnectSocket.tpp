
template <SocketType ST>
Network::ConnectSocket<ST>::ConnectSocket() : ST()
{
}

template <SocketType ST>
template <typename... Args>
Network::ConnectSocket<ST>::ConnectSocket(Args... args) : ST(std::forward<Args>(args)...)
{
}

template <SocketType ST>
Network::ConnectSocket<ST>::ConnectSocket(ConnectSocket &&other) noexcept : ST(std::move(other))
{
}

template <SocketType ST>
int Network::ConnectSocket<ST>::connect(const Address &addr)
{
    return ::connect(ST::m_fd.value, addr.get_address(), addr.get_size());
}