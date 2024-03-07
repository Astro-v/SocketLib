template <AddressDomainType Domain>
Network::Stream::StreamSocket<Domain>::StreamSocket() : StreamSocketBase(m_domain.get_domain()) {}

template <AddressDomainType Domain>
Network::Stream::StreamSocket<Domain>::StreamSocket(Network::FileDescriptor fd) : StreamSocketBase(fd) {}

template <AddressDomainType Domain>
Network::Stream::StreamSocket<Domain>::StreamSocket(StreamSocket &&other) noexcept : StreamSocketBase(std::move(other)), m_domain(other.m_domain) {}

template <AddressDomainType Domain>
typename Domain::Address Network::Stream::StreamSocket<Domain>::get_domain_address() const
{
    return m_domain.Address;
}