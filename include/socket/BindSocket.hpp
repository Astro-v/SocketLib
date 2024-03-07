#ifndef BIND_SOCKET_HPP
#define BIND_SOCKET_HPP

#include "Socket.hpp"

namespace Network
{
    template <SocketType ST>
    class BindSocket : public ST
    {
    public:
        /**
         * @brief Construct a new Bind Socket object
         */
        BindSocket();

        /**
         * @brief Construct a new Bind Socket object
         * @tparam Args The type of the arguments
         * @param args The arguments
         */
        template <typename... Args>
        BindSocket(Args... args);

        /**
         * @brief Move constructor
         * @param other The other bind socket
         * @note The move constructor is noexcept
         */
        BindSocket(BindSocket &&other) noexcept;

        virtual ~BindSocket() = default;

        // set the type of the address to be passed to bind
        typedef decltype(std::declval<ST>().get_domain_address()) Address;

        int bind(const Address &address);
    };
} // namespace Network

#include "BindSocket.tpp"

#endif // BIND_SOCKET_HPP