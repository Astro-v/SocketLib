template <SocketType ST, SocketType AcceptedSocket>
Network::AcceptSocket<ST, AcceptedSocket>::AcceptSocket() : ST()
{
}

template <SocketType ST, SocketType AcceptedSocket>
template <typename... Args>
Network::AcceptSocket<ST, AcceptedSocket>::AcceptSocket(Args... args) : ST(std::forward<Args>(args)...)
{
}

template <SocketType ST, SocketType AcceptedSocket>
Network::AcceptSocket<ST, AcceptedSocket>::AcceptSocket(AcceptSocket &&other) noexcept : ST(std::move(other))
{
}
template <SocketType ST, SocketType AcceptedSocket>
AcceptedSocket Network::AcceptSocket<ST, AcceptedSocket>::accept(Network::AcceptSocket<ST, AcceptedSocket>::Address &address)
{
    return AcceptedSocket(FileDescriptor{::accept(ST::m_fd.value, address.get_address(), address.get_size())});
}