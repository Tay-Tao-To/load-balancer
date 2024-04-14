#ifndef SERVERMANAGER_H
#define SERVERMANAGER_H

#include <vector>
#include <mutex>
#include <algorithm>
#include <string>

struct ServerInfo {
    std::string address;
    int port;
    int current_connections;
    ServerInfo(const std::string& addr, int p) : address(addr), port(p), current_connections(0) {}
};

class ServerManager {
private:
    std::vector<ServerInfo> servers;
    std::mutex mtx;

public:
    void addServer(const std::string& address, int port);
    ServerInfo& getLeastLoadedServer();
    void releaseServer(const std::string& address);
};

#endif // SERVERMANAGER_H