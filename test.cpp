#include <iostream>
#include "requestparser.hpp"

#define req "OPTIONS rtsp://egor:132475@192.168.5.114:8554/test.254 RTSP/1.0\r\nCSeq: 2\r\nUser-Agent: ./openRTSP (LIVE555 Streaming Media v2024.03.08)"

int main(int argc, char *argv[])
{
	int port, bufsize = 1024;

	char login[bufsize];
	char password[bufsize];
	char host[bufsize];
	char url[bufsize];
	char name[bufsize];
	char version[bufsize];
	
	RTSPRequestParser requestParser;

	requestParser.parseMethod(req);
	std::cout << requestParser.getResult() << std::endl;

	requestParser.parseURI(req);
	std::cout << requestParser.getResult() << std::endl;

	requestParser.parseLogin(login, bufsize);
	std::cout << login << std::endl;

	requestParser.parsePassword(password, bufsize);
	std::cout << password << std::endl;

	requestParser.parseHost(host, bufsize);
	std::cout << host << std::endl;

	port = requestParser.parsePort();
	std::cout << port << std::endl;

	requestParser.parseURL(url, bufsize);
	std::cout << url << std::endl;

	requestParser.parseName(name, bufsize);
	std::cout << name << std::endl;
	
	return 0;
}
