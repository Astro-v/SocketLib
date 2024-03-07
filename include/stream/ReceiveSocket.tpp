template <StreamSocketType SST>
Network::Stream::ReceiveSocket<SST>::ReceiveSocket() : SST() {}

template <StreamSocketType SST>
template <typename... Args>
Network::Stream::ReceiveSocket<SST>::ReceiveSocket(Args... args) : SST(std::forward<Args>(args)...) {}

template <StreamSocketType SST>
Network::Stream::ReceiveSocket<SST>::ReceiveSocket(ReceiveSocket &&other) noexcept : SST(std::move(other)) {}

template <StreamSocketType SST>
ssize_t Network::Stream::ReceiveSocket<SST>::receive(void *buffer, size_t length, int flags)
{
    return ::recv(SST::m_fd.value, buffer, length, flags);
}

template <StreamSocketType SST>
ssize_t Network::Stream::ReceiveSocket<SST>::receive(std::string &buffer, size_t length, int flags)
{
    buffer.resize(length);
    return receive(buffer.data(), length, flags);
}