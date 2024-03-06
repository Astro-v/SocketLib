
#include <iostream>
#include <string>

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
typedef Network::AcceptSocket<Network::ListenSocket<Network::BindSocket<Network::Stream::StreamSocket<Network::Unix::UnixDomain>>>, Client> Listener;

int main()
{

    std::cout << "Initialize Server" << std::endl;
    Listener *s = new Listener();
    Address address("/tmp/test");
    std::cout << "Binding" << std::endl;
    s->bind(address);
    std::cout << "Listening" << std::endl;
    s->listen();
    Address client_address;

    std::cout << "Accecepting Client" << std::endl;
    Client client = s->accept(client_address);

    std::cout << "Client accepted" << std::endl;
    if (client == Network::Socket::INVALID_SOCKET)
        std::cout << "ERROR" << std::endl;

    std::string message;
    std::cout << "Waiting for message" << std::endl;
    client.receive(message, 100, 0);

    std::string response = "Hello, client!";

    std::cout << "Sending " << response << std::endl;
    client.send(response, 0);

    std::cout << "Received : " << message << std::endl;
    std::cout << "End Server" << std::endl;
    return 0;
}