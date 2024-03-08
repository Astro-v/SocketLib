#include "DatagramSocketBase.hpp"

Network::Datagram::DatagramSocketBase::DatagramSocketBase(int &domain) : Socket(domain, SOCK_DGRAM) {}

Network::Datagram::DatagramSocketBase::DatagramSocketBase(FileDescriptor fd) : Socket(fd) {}

Network::Datagram::DatagramSocketBase::DatagramSocketBase(DatagramSocketBase &&other) noexcept : Socket(std::move(other)) {}