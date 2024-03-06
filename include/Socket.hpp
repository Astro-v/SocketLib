#ifndef SOCKET_HPP
#define SOCKET_HPP

#include <type_traits>
#include <stdexcept>
#include <unistd.h>
#include <sys/socket.h>

namespace Network
{
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
            m_fd = ::socket(domain, type, protocol);
            if (m_fd == -1)
            {
                throw std::runtime_error("Failed to create socket");
            }
        }

        /**
         * @brief Construct a new Socket object
         * @param fd The file descriptor of the socket
         */
        Socket(int fd) : m_fd(fd) {}

        /**
         * @brief Move constructor
         * @param other The other socket
         * @note The other socket is invalidated after the move
         */
        Socket(Socket &&other) noexcept
        {
            m_fd = other.m_fd;
            other.m_fd = -1;
        }

        Socket(const Socket &other) = delete;
        Socket &operator=(const Socket &other) = delete;

    public:
        virtual ~Socket()
        {
            ::close(m_fd);
        };

        bool operator==(const Socket &other) const
        {
            return m_fd == other.m_fd;
        }

        static const Socket INVALID_SOCKET;
    };

    const Socket Socket::INVALID_SOCKET{-1};

} // namespace Network

template <typename T>
concept SocketType = std::is_base_of<Network::Socket, T>::value;

#endif // SOCKET_HPP