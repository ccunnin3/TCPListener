#include <windows.h>
#include <winsock.h>
#include "stdafx.h"

using namespace std;

class TCPListener
{
public:
	TCPListener();
	boolean listenForString();
	void respondWithString();
	void cleanUp();

private:
	SOCKET sock;
	WSADATA w;
};

