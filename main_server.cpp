
#include <iostream>

#include "UnixDomain.hpp"
#include "StreamSocket.hpp"
#include "DatagramSocket.hpp"
#include "BindSocket.hpp"
#include "ListenSocket.hpp"
#include "AcceptSocket.hpp"
#include "SendSocket.hpp"
#include "SendToSocket.hpp"

typedef Network::ListenSocket<Network::BindSocket<Network::Stream::StreamSocket<Network::Unix::UnixDomain>>> MySocket;
typedef Network::AcceptSocket<MySocket, Network::Stream::StreamSocket<Network::Unix::UnixDomain>> MyAcceptSocket;
typedef Network::Unix::UnixDomain::Address Address;

int main()
{
    MyAcceptSocket *s = new MyAcceptSocket();
    Address address("/tmp/test");
    s->bind(address);
    s->listen();
    Address client_address;
    auto client = s->accept(client_address);
    if (client == Network::Socket::INVALID_SOCKET)
        std::cout << "ERROR" << std::endl;
    return 0;
}