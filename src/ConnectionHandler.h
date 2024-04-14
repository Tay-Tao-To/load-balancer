#ifndef CONNECTIONHANDLER_H
#define CONNECTIONHANDLER_H

#include <boost/asio.hpp>
#include "ServerManager.h"

void handleConnection(boost::asio::ip::tcp::socket socket, ServerManager& manager);

#endif // CONNECTIONHANDLER_H