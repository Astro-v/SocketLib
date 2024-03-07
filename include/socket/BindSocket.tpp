template <SocketType ST>
Network::BindSocket<ST>::BindSocket() : ST() {}

template <SocketType ST>
template <typename... Args>
Network::BindSocket<ST>::BindSocket(Args... args) : ST(std::forward<Args>(args)...)
{
}

template <SocketType ST>
Network::BindSocket<ST>::BindSocket(BindSocket &&other) noexcept : ST(std::move(other)) {}

template <SocketType ST>
int Network::BindSocket<ST>::bind(const Network::BindSocket<ST>::Address &address)
{
    return ::bind(ST::m_fd.value, address.get_address(), address.get_size());
}