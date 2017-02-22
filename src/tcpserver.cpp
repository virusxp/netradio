#include "tcpserver.h"

#include <sys/socket.h>

void listenerThread(int* socketPtr, std::atomic<bool>* killThread)
{
    struct sockaddr_in client;
    size_t socklen = sizeof(struct sockaddr_in);

    while(!killThread)
    {
        int clientSocket = -1;

        clientSocket = accept(*socketPtr,(struct sockaddr*)&client,(socklen_t*)&socklen);
        
    }
}

TCPServer_IncomingClient::TCPServer_IncomingClient(int sock, struct sockaddr clientAddr, socklen_t addrLen)
{
    this->clientSocket = sock;
    this->clientAddress = clientAddr;
    this->addressLen = addrLen;

    //TODO
}

TCPServer_IncomingClient::~TCPServer_IncomingClient()
{
    this->threadKiller = true;
    this->handlerThread.join(); //error handling !
}

TCPServer::TCPServer(int16_t serverport)
{
    this->maxConnectionQueue = 5;   //spaeter durch config anzupassen
    this->port = serverport;

    this->sock = socket(AF_INET,SOCK_STREAM,0);
    if(this->sock == -1);//include exception

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(this->port);

    if(bind(socket_desc,(struct sockaddr*)&server,sizeof(server)) < 0);//include exception

    listen(this->sock,this->maxConnectionQueue);
}
