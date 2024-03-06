
#include <iostream>

#include "UnixDomain.hpp"
#include "StreamSocket.hpp"
#include "DatagramSocket.hpp"
#include "BindSocket.hpp"
#include "ListenSocket.hpp"
#include "AcceptSocket.hpp"
#include "SendSocket.hpp"
#include "SendToSocket.hpp"
#include "ReceiveSocket.hpp"
#include "ReceiveFromSocket.hpp"
#include "ConnectSocket.hpp"

typedef Network::Unix::UnixDomain::Address Address;
typedef Network::ConnectSocket<Network::Stream::SendSocket<Network::Stream::ReceiveSocket<Network::Stream::StreamSocket<Network::Unix::UnixDomain>>>> Client;

int main()
{
    std::cout << "Initialize Client" << std::endl;
    Client *s = new Client();
    Address address("/tmp/test");

    std::cout << "Connecting" << std::endl;
    if (s->connect(address) < 0)
    {
        std::cerr << "Error connecting" << std::endl;
        return 1;
    }
    std::string message = "Hello, world!";

    std::cout << "Sending " << message << std::endl;
    if (s->send(message, 0) < 0)
    {
        std::cerr << "Error sending" << std::endl;
        return 1;
    }

    if (s->receive(message, 100, 0) < 0)
    {
        std::cerr << "Error receiving" << std::endl;
        return 1;
    }
    std::cout << "Received : " << message << std::endl;
    std::cout << "End Client" << std::endl;
    return 0;
}