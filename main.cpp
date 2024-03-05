
#include <iostream>

#include "AddressDomain.hpp"
#include "Socket.hpp"
#include "BindSocket.hpp"

int main()
{
    std::cout << "A" << std::endl;
    auto s = new BindSocket<StreamSocket<UnixDomain>>();
    UnixDomain::Address address("/tmp/test");
    s->bind(address);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}