#ifndef BIND_SOCKET_HPP
#define BIND_SOCKET_HPP

#include "Socket.hpp"

namespace Network
{
    template <SocketType ST>
    class BindSocket : public ST
    {
    public:
        BindSocket() : ST()
        {

            std::cout << "ListenSocket" << std::endl;
        }

        template <typename... Args>
        BindSocket(Args... args) : ST(std::forward<Args>(args)...)
        {
        }

        /**
         * @brief Move constructor
         * @param other The other bind socket
         */
        BindSocket(BindSocket &&other) noexcept : ST(std::move(other)) {}

        virtual ~BindSocket() = default;

        // set the type of the address to be passed to bind
        typedef decltype(std::declval<ST>().get_domain_address()) Address;

        int bind(const Address &address)
        {
            return ::bind(ST::m_fd.value, address.get_address(), address.get_size());
        }
    };
} // namespace Network

#endif // BIND_SOCKET_HPP