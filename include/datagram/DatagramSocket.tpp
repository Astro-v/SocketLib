template <AddressDomainType Domain>
Network::Datagram::DatagramSocket<Domain>::DatagramSocket() : DatagramSocketBase(m_domain.get_domain(), SOCK_DGRAM) {}

template <AddressDomainType Domain>
Network::Datagram::DatagramSocket<Domain>::DatagramSocket(FileDescriptor fd) : DatagramSocketBase(fd) {}

template <AddressDomainType Domain>
Network::Datagram::DatagramSocket<Domain>::DatagramSocket(DatagramSocket &&other) noexcept : DatagramSocketBase(std::move(other)), m_domain(other.m_domain) {}

template <AddressDomainType Domain>
typename Domain::Address Network::Datagram::DatagramSocket<Domain>::get_domain_address() const
{
    return m_domain.Address;
}