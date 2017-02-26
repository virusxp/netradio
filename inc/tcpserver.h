#ifndef TCPSERVER_H_
#define TCPSERVER_H_

#include <cstdint>
#include <atomic>
#include <thread>
#include <queue>
#include <string>
#include <mutex>
#include <stdexcept>

/*
template <class T>
class IOElement
{
    private:
        T val;
        bool dir;

    public:
        static const bool INPUT  = false;
        static const bool OUTPUT = true;

        IOElement(T value, bool direction)
        {
            this->val = value;
            this->dir = direction;
        }

        //virtual ~IOElement();

        bool getValue(T* value)
        {
            *value = this->val;
            return this->dir;
        }
};*/

class TCPServer_IncomingClient
{
    private:
        int clientSocket;
        struct sockaddr clientAddress;
        socklen_t addressLen;

        std::thread handlerThread;
        std::atomic<bool> threadKiller;
        std::queue<std::string> input;
        std::mutex inputMtx;
        std::queue<std::string> output;
        std::mutex outputMtx;

    public:
        TCPServer_IncomingClient(int sock, struct sockaddr clientAddr, socklen_t addrLen);
        virtual ~TCPServer_IncomingClient();

        void send(std::string message);
        int receive(std::string* message);
};

class TCPServerException : public std::runtime_error
{
	private:
	public:
		TCPServerException(const char* what_arg) : std::runtime_error(what_arg) {}
		//virtual ~TCPServerException();
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
