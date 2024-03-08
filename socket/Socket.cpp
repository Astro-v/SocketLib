#include "Socket.hpp"
#include <iostream>

const Network::Socket Network::Socket::INVALID_SOCKET{FileDescriptor{-1}};

Network::Socket::Socket(int domain, int type, int protocol)
{
    m_fd.value = ::socket(domain, type, protocol);
    if (m_fd.value == -1)
    {
        throw std::runtime_error("Failed to create socket");
    }
}

Network::Socket::Socket(FileDescriptor fd) : m_fd{fd.value}
{
}

Network::Socket::Socket(Socket &&other) noexcept
{
    m_fd.value = other.m_fd.value;
    other.m_fd.value = -1;
}

Network::Socket::~Socket()
{
    std::cout << "closing socket" << std::endl;
    ::close(m_fd.value);
}

bool Network::Socket::operator==(const Socket &other) const
{
    return m_fd.value == other.m_fd.value;
}