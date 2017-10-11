#include "TCPListener.h"
#include "stdafx.h"

using namespace std;

int main()
{
	TCPListener greeting = TCPListener();
	boolean success = greeting.listenForString();
	if (success)
	{
		greeting.respondWithString();
	}

}