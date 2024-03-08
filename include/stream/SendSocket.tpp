template <StreamSocketType SST>
Network::Stream::SendSocket<SST>::SendSocket() : SST() {}

template <StreamSocketType SST>
template <typename... Args>
Network::Stream::SendSocket<SST>::SendSocket(Args... args) : SST(std::forward<Args>(args)...) {}

template <StreamSocketType SST>
Network::Stream::SendSocket<SST>::SendSocket(SendSocket &&other) noexcept : SST(std::move(other)) {}

template <StreamSocketType SST>
int Network::Stream::SendSocket<SST>::send(const void *buf, size_t len, int flags)
{
    flags |= MSG_NOSIGNAL;
    return ::send(SST::m_fd.value, buf, len, flags);
}

template <StreamSocketType SST>
int Network::Stream::SendSocket<SST>::send(const std::string &buf, int flags)
{
    return send(buf.c_str(), buf.size(), flags);
}