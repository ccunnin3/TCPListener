// TCPListener.cpp : Listens via TCP for a string. WHen it recieves one, it responds with "Hello Disney!"
//

#include <windows.h>
#include <winsock.h>
#include <string>
#include "stdafx.h"

using namespace std;


TCPListener :: TCPListener()
{
	//Set up WSA environment
	int error = WSAStartup(0x0202, &w);   // Fill in WSA info

	if (error)
	{
		throw runtime_error("Error with WSA startup.");
	}

	if (w.wVersion != 0x0202) //Check Winsock version?
	{
		WSACleanup();
		throw runtime_error("Operating wrong Winsock version.");
	}

	//Create a socket
	SOCKADDR_IN addr; // The address structure for a TCP socket

	addr.sin_family = AF_INET;      // Address family
	addr.sin_port = htons(inet_addr("0.0.0.0"));   // Assign port to this socket
	addr.sin_addr.s_addr = htonl(INADDR_ANY);

	SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); // Create socket

	//CHeck that the socket was successfully created
	if (sock == INVALID_SOCKET)
	{
		throw runtime_error("Failed to create a socket.");
	}

	else if (bind(sock, (LPSOCKADDR)&addr, sizeof(addr)) == SOCKET_ERROR)
	{
		throw runtime_error("Could not bind to the socket.");
	}

}

//Listens on all ports for a string
boolean TCPListener :: listenForString()
{


	//SOMAXCONN allows as many connections as possible to be made
	//listen returns once a connection has been made
	listen(sock, SOMAXCONN);
	return true;
}

void TCPListener :: respondWithString()
{

	//Send the message
	string buffer = "Hello Disney!!";
	send(sock, buffer.c_str(), buffer.length(), 0);

}

void TCPListener :: cleanUp()
{
	//Close the socket
	closesocket(sock);
	WSACleanup();

}