
#include <iostream>

#include "UnixDomain.hpp"
#include "StreamSocket.hpp"
#include "BindSocket.hpp"
#include "ListenSocket.hpp"
#include "AcceptSocket.hpp"

typedef Network::ListenSocket<Network::BindSocket<Network::StreamSocket<Network::Unix::UnixDomain>>> MySocket;
typedef Network::AcceptSocket<MySocket, Network::StreamSocket<Network::Unix::UnixDomain>> MyAcceptSocket;
typedef Network::Unix::UnixDomain::Address Address;

int main()
{
    std::cout << "A" << std::endl;
    MyAcceptSocket *s = new MyAcceptSocket();
    Address address("/tmp/test");
    s->bind(address);
    s->listen();
    Address *client_address;
    std::cout
        << "B" << std::endl;
    auto client = s->accept(client_address);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}