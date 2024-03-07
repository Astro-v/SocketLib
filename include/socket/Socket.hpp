#ifndef SOCKET_HPP
#define SOCKET_HPP

#include <type_traits>
#include <stdexcept>
#include <unistd.h>
#include <sys/socket.h>

namespace Network
{
    /**
     * @brief A file descriptor
     */
    struct FileDescriptor
    {
        int value;
    };

    /**
     * @brief A socket
     */
    class Socket
    {

    protected:
        // The file descriptor of the socket
        FileDescriptor m_fd;

        Socket() = default;

        /**
         * @brief Construct a new Socket object
         * @param type The type of the socket
         * @param protocol Specifies a particular protocol to be used with the socket.
         * Specifying a protocol of 0 use an unspecified default protocol
         * appropriate for the requested socket type.
         */
        Socket(int domain, int type, int protocol = 0);

        /**
         * @brief Construct a new Socket object
         * @param fd The file descriptor of the socket
         */
        Socket(FileDescriptor fd);

        /**
         * @brief Move constructor
         * @param other The other socket
         * @note The other socket is invalidated after the move
         */
        Socket(Socket &&other) noexcept;

        /**
         * @brief Copy constructor
         * @param other The other socket
         * @note Deleted
         */
        Socket(const Socket &other) = delete;

        /**
         * @brief Copy assignment operator
         * @param other The other socket
         * @return Socket& The reference to this
         * @note Deleted
         */
        Socket &operator=(const Socket &other) = delete;

    public:
        /**
         * @brief Destroy the Socket object
         */
        virtual ~Socket();

        /**
         * @brief Equality operator
         * @param other The other socket
         * @return true If the sockets are equal
         * @return false If the sockets are not equal
         */
        bool operator==(const Socket &other) const;

        /**
         * @brief The invalid socket (file descriptor is -1)
         */
        static const Socket INVALID_SOCKET;
    };

} // namespace Network

template <typename T>
concept SocketType = std::is_base_of<Network::Socket, T>::value;

#endif // SOCKET_HPP