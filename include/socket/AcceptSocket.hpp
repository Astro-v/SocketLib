#ifndef ACCEPT_SOCKET_HPP
#define ACCEPT_SOCKET_HPP

#include "Socket.hpp"

namespace Network
{
    template <SocketType ST, SocketType AcceptedSocket>
    class AcceptSocket : public ST
    {
    public:
        /**
         * @brief Construct a new Accept Socket object
         */
        AcceptSocket();

        /**
         * @brief Construct a new Accept Socket object
         * @tparam Args The type of the arguments
         * @param args The arguments
         * @note The arguments are forwarded to the next class constructor
         */
        template <typename... Args>
        AcceptSocket(Args... args);

        /**
         * @brief Move constructor
         * @param other The other accept socket
         */
        AcceptSocket(AcceptSocket &&other) noexcept;

        /**
         * @brief Destructor
         */
        virtual ~AcceptSocket() = default;

        /**
         * @brief Declared type for the address
         */
        typedef decltype(std::declval<AcceptedSocket>().get_domain_address()) Address;

        /**
         * @brief Accept a connection on a socket
         * @param address The address of the client
         * @return AcceptedSocket The accepted socket
         * @note The address is filled with the client address
         */
        AcceptedSocket accept(Address &address);
    };

} // namespace Network

#include "AcceptSocket.tpp"

#endif // ACCEPT_SOCKET_HPP