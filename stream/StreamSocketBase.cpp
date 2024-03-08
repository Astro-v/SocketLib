#include "StreamSocketBase.hpp"

Network::Stream::StreamSocketBase::StreamSocketBase(int domain) : Socket(domain, SOCK_STREAM) {}

Network::Stream::StreamSocketBase::StreamSocketBase(FileDescriptor fd) : Socket(fd) {}

Network::Stream::StreamSocketBase::StreamSocketBase(StreamSocketBase &&other) noexcept : Socket(std::move(other)) {}