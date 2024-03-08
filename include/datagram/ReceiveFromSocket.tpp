template <DatagramSocketType DST>
Network::Datagram::ReceiveFromSocket<DST>::ReceiveFromSocket() : DST() {}

template <DatagramSocketType DST>
template <typename... Args>
Network::Datagram::ReceiveFromSocket<DST>::ReceiveFromSocket(Args... args) : DST(std::forward<Args>(args)...) {}

template <DatagramSocketType DST>
Network::Datagram::ReceiveFromSocket<DST>::ReceiveFromSocket(ReceiveFromSocket &&other) noexcept : DST(std::move(other)) {}

template <DatagramSocketType DST>
ssize_t Network::Datagram::ReceiveFromSocket<DST>::receive_from(void *buffer, size_t length, Address &src_addr, int flags)
{
    return ::recvfrom(DST::m_fd.value, buffer, length, flags, src_addr.get_address(), src_addr.get_size());
}

template <DatagramSocketType DST>
ssize_t Network::Datagram::ReceiveFromSocket<DST>::receive_from(std::string &buffer, size_t length, Address &src_addr, int flags)
{
    buffer.resize(length);
    return receive_from(buffer.data(), length, src_addr, flags);
}