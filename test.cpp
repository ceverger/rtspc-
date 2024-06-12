#include <iostream>
#include "requestparser.hpp"

#define req "OPTIONS rtsp://egor:132475@192.168.5.114:8554/test.264 RTSP/1.0\r\nCSeq: 2\r\nUser-Agent: ./openRTSP (LIVE555 Streaming Media v2024.03.08)"

int main(int argc, char *argv[])
{
	int port, bufsize = 1024;

	char login[bufsize];
	char password[bufsize];
	char host[bufsize];
	char uri[bufsize];
	char urn[bufsize];
	char version[bufsize];
	
	RTSPRequestParser requestParser;

	requestParser.parseMethod(req);
	std::cout << requestParser.getResult() << ' ' << requestParser.getReslen()<< std::endl;

	requestParser.parseURL(req);
	std::cout << requestParser.getResult() << ' ' << requestParser.getReslen()<< std::endl;

	requestParser.parseLogin(login, bufsize);
	std::cout << login << std::endl;

	requestParser.parsePassword(password, bufsize);
	std::cout << password << std::endl;

	requestParser.parseHost(host, bufsize);
	std::cout << host << std::endl;

	requestParser.parseURI(uri, bufsize);
	std::cout << uri << std::endl;
	
	return 0;
}
