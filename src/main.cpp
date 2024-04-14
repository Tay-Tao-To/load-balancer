#include <boost/asio.hpp>
#include "ServerManager.h"
#include "ConnectionHandler.h"

void startListening(boost::asio::io_service& io_service, unsigned short port, ServerManager& manager) {
    boost::asio::ip::tcp::acceptor acceptor(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port));
    for (;;) {
        boost::asio::ip::tcp::socket socket(io_service);
        acceptor.accept(socket);
        std::thread(&handleConnection, std::move(socket), std::ref(manager)).detach();
    }
}

int main() {
    try {
        ServerManager manager;
        manager.addServer("192.168.1.10", 3306);
        manager.addServer("192.168.1.11", 3306);

        boost::asio::io_service io_service;
        startListening(io_service, 12345, manager);
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}