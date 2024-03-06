#ifndef SEND_TO_SOCKET_HPP
#define SEND_TO_SOCKET_HPP

#include "DatagramSocketBase.hpp"

namespace Network::Datagram
{
    template <DatagramSocketType DST>
    class SendToSocket : public DST
    {
    public:
        SendToSocket() : DST()
        {
        }

        template <typename... Args>
        SendToSocket(Args... args) : DST(std::forward<Args>(args)...)
        {
        }

        /**
         * @brief Move constructor
         * @param other The other send to socket
         */
        SendToSocket(SendToSocket &&other) noexcept : DST(std::move(other)) {}

        virtual ~SendToSocket() = default;

        typedef decltype(std::declval<DST>().get_domain_address()) Address;

        int send_to(const void *buf, size_t len, const Address &dest_addr, int flags)
        {
            return ::sendto(DST::m_fd.value, buf, len, flags, dest_addr.get_address(), dest_addr.get_size());
        }

        int send_to(const std::string &buf, const Address &dest_addr, int flags)
        {
            return ::sendto(DST::m_fd.value, buf.c_str(), buf.size(), flags, dest_addr.get_address(), dest_addr.get_size());
        }
    };

} // namespace Network::Datagram

#endif // SEND_TO_SOCKET_HPP