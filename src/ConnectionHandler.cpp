#include "ConnectionHandler.h"
#include <iostream>

void handleConnection(boost::asio::ip::tcp::socket socket, ServerManager& manager) {
    auto& server = manager.getLeastLoadedServer();
    // Here you would typically create a new connection to the chosen MySQL server
    std::cout << "Redirecting connection to " << server.address << ":" << server.port << std::endl;

    // Simulate releasing server connection
    manager.releaseServer(server.address);
}