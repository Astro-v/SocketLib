#include "UnixListener.hpp"

#include "UnixDomain.hpp"
#include "StreamSocket.hpp"
#include "BindSocket.hpp"
#include "ListenSocket.hpp"
#include "AcceptSocket.hpp"
#include "ConnectSocket.hpp"
#include "SendSocket.hpp"
#include "ReceiveSocket.hpp"

typedef Network::ConnectSocket<Network::Stream::SendSocket<Network::Stream::ReceiveSocket<Network::Stream::StreamSocket<Network::Unix::UnixDomain>>>> Client;
typedef Network::AcceptSocket<Network::ListenSocket<Network::BindSocket<Network::Stream::StreamSocket<Network::Unix::UnixDomain>>>, Client> Listener;

struct Network::Unix::UnixListener::Socket
{
    std::unique_ptr<Listener> listener;
};

Network::Unix::UnixListener::UnixListener(const char *path) : socket(std::make_unique<Socket>())
{
    socket->listener = std::make_unique<Listener>();
    Network::Unix::UnixDomain::Address address(path);
    socket->listener->bind(address);
    socket->listener->listen();
}

void Network::Unix::UnixListener::listen()
{
    socket->listener->listen();
}

Network::Unix::UnixSocket Network::Unix::UnixListener::accept()
{
    Network::Unix::UnixDomain::Address client_address;
    Client client = socket->listener->accept(client_address);
}
