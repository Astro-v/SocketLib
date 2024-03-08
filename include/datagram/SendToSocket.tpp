template <DatagramSocketType DST>
Network::Datagram::SendToSocket<DST>::SendToSocket() : DST()
{
}

template <DatagramSocketType DST>
template <typename... Args>
Network::Datagram::SendToSocket<DST>::SendToSocket(Args... args) : DST(std::forward<Args>(args)...)
{
}

template <DatagramSocketType DST>
Network::Datagram::SendToSocket<DST>::SendToSocket(SendToSocket &&other) noexcept : DST(std::move(other)) {}

template <DatagramSocketType DST>
int Network::Datagram::SendToSocket<DST>::send_to(const void *buf, size_t len, const Address &dest_addr, int flags)
{
    return ::sendto(DST::m_fd.value, buf, len, flags, dest_addr.get_address(), *dest_addr.get_size());
}

template <DatagramSocketType DST>
int Network::Datagram::SendToSocket<DST>::send_to(const std::string &buf, const Address &dest_addr, int flags)
{
    return send_to(buf.c_str(), buf.size(), dest_addr, flags);
}