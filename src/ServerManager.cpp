#include "ServerManager.h"

void ServerManager::addServer(const std::string& address, int port) {
	servers.emplace_back(address, port);
}

ServerInfo& ServerManager::getLeastLoadedServer() {
  std::lock_guard<std::mutex> lock(mtx);
	auto min_iter = std::min_element(servers.begin(), servers.end(),
									 [](const ServerInfo& a, const ServerInfo& b) {
										 return a.current_connections < b.current_connections;
									 });
	min_iter->current_connections++;
	return *min_iter;
}

void ServerManager::releaseServer(const std::string& address) {
	std::lock_guard<std::mutex> lock(mtx);
	auto it = std::find_if(servers.begin(), servers.end(),
						   [&address](const ServerInfo& server) {
							   return server.address == address;
						   });
	if (it != servers.end()) {
		it->current_connections--;
	}
}