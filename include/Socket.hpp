#ifndef SOCKET_HPP
#define SOCKET_HPP

#include <type_traits>
#include <stdexcept>
#include <unistd.h>
#include <sys/socket.h>
#include "AddressDomain.hpp"

/**
 * @brief A socket
 */
class Socket
{

protected:
    // The file descriptor of the socket
    int m_fd;

    Socket() = default;

    /**
     * @brief Construct a new Socket object
     * @param type The type of the socket
     * @param protocol Specifies a particular protocol to be used with the socket.
     * Specifying a protocol of 0 use an unspecified default protocol
     * appropriate for the requested socket type.
     */
    Socket(int domain, int type, int protocol = 0)
    {
        std::cout << "B1" << std::endl;
        std::cout << "Domain: " << domain << std::endl;
        m_fd = ::socket(domain, type, protocol);
        std::cout << "B2" << std::endl;
        if (m_fd == -1)
        {
            throw std::runtime_error("Failed to create socket");
        }
    }

public:
    virtual ~Socket()
    {
        ::close(m_fd);
    };
};

/**
 * @brief A stream socket
 * @tparam Domain The domain of the socket (e.g. UnixDomain, InetDomain, etc.)
 */
template <typename Domain>
class StreamSocket : public Socket
{
    // The domain of the socket (e.g. AF_INET, AF_UNIX, etc.)
    Domain m_domain;

public:
    StreamSocket() : Socket(m_domain.get_domain(), SOCK_STREAM) { std::cout << "C" << std::endl; }
    virtual ~StreamSocket() = default;

    const typename Domain::Address &get_domain_address() const { return m_domain.Address; }
};

/**
 * @brief A datagram socket
 * @tparam Domain The domain of the socket (e.g. UnixDomain, InetDomain, etc.)
 */
template <typename Domain>
class DatagramSocket : public Socket
{
    // The domain of the socket (e.g. AF_INET, AF_UNIX, etc.)
    Domain m_domain;

public:
    DatagramSocket() : Socket(m_domain.get_domain(), SOCK_DGRAM) {}
    virtual ~DatagramSocket() = default;

    const typename Domain::Address &get_domain_address() const { return m_domain.Address; }
};

template <typename T>
concept SocketType = std::is_base_of<Socket, T>::value;

template <typename T, typename Domain>
concept StreamSocketType = std::is_base_of<StreamSocket<Domain>, T>::value;

template <typename T, typename Domain>
concept DatagramSocketType = std::is_base_of<DatagramSocket<Domain>, T>::value;

#endif // SOCKET_HPP