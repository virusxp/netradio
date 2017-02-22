#ifndef TCPSERVER_H_
#define TCPSERVER_H_

#include <cstdint>
#include <atomic>
#include <thread>

class TCPServer_IncomingClient
{
    private:
        int clientSocket;
        struct sockaddr clientAddress;
        socklen_t addressLen;

        std::thread handlerThread;
        std::atomic<bool> threadKiller;

    public:
        TCPServer_IncomingClient(int sock, struct sockaddr clientAddr, socklen_t addrLen);
        virtual ~TCPServer_IncomingClient();
};

class TCPServer
{
    private:
        int sock;
        int16_t port;
        int maxConnectionQueue;

    public:
        TCPServer(int16_t serverport);
        virtual ~TCPServer();
};

#endif //TCPSERVER_H_
