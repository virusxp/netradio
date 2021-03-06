#include "tcpserver.h"

#include <errno.h>
#include <sstream>
#include <sys/socket.h>
#include <netinet/in.h>

void handlerThread(int* socketPtr, std::queue<std::string> inputQu, std::mutex* in, 
    std::queue<std::string> outputQu, std::mutex out, std::atomic<bool>* killThread)
{
    while(!killThread)
    {
        
    }
}

TCPServer_IncomingClient::TCPServer_IncomingClient(int sock, struct sockaddr clientAddr, socklen_t addrLen)
{
    this->clientSocket = sock;
    this->clientAddress = clientAddr;
    this->addressLen = addrLen;

    this->threadKiller = false;

    //TODO
}

TCPServer_IncomingClient::~TCPServer_IncomingClient()
{
    this->threadKiller = true;
    this->handlerThread.join(); //error handling !
}

void TCPServer_IncomingClient::send(std::string message)
{
    std::unique_lock<std::mutex> lck(this->outputMtx);

    this->input.push(message);
}

int TCPServer_IncomingClient::receive(std::string* message)
{
    if(this->output.size == 0)
        return -1;

    std::unique_lock<std::mutex> lck(this->inputMtx);

    std::string ret = this->output.front();
    this->output.pop();

    *message = ret;

    return 0;
}


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

TCPServer::TCPServer(int16_t serverport)
{
    this->maxConnectionQueue = 5;   //spaeter durch config anzupassen
    this->port = serverport;

    this->sock = socket(AF_INET,SOCK_STREAM,0);
    if(this->sock == -1)
    	throw TCPServerException("[Exception] Could not open socket");

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(this->port);

    if(bind(this->sock,(struct sockaddr*)&server,(socklen_t)sizeof(server)) < 0)
    {
    	std::stringstream str;
    	str << "[Exception] Could not bind address [port = " << this->port << "|errno = " << errno << "]";
    	close(this->sock);
    	throw TCPServerException(str.str().c_str());
    }

    listen(this->sock,this->maxConnectionQueue);
}
