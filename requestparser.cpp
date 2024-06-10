// requestparser.cpp - реализация методов класса RTSPRequestParser

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include "rtsprequestparser.h"

	void RTSPRequestParser::parseMethod(const char *message)
	{
		/* Получение названия метода  */

		if(message == NULL) return;

		int i = 0;

		reset();

		while(i < ressize && message[i] != ' ')
		{
			result[i] = message[i];
			i++;
		}

		result[i] = '\0';
		reslen = strlen(result);
	}

	void RTSPRequestParser::parseURI(const char *message)
	{
		if(message == NULL) return;
		
		int i = 0;
		const char *pos = message;

		reset();

		while(*pos++ != ' ');

		if(*pos == '*') 
		{
			result[0] = *pos;
			result[1] = '\0';
			reslen = 1;
			return;
		}

		if(strstr(pos, "rtsp://") == nullptr) return;

		while(i < ressize && pos[i] != ' ')
		{
			result[i] = pos[i];
			i++;			
		}

		result[i] = '\0';
		reslen = strlen(result);
	}

	void RTSPRequestParser::parseLogin(char buf, int bufsize)
	{
		if(buf == nullptr || reslen <= 1) return;

		int i = 0;
		int cachesize = 1024;
		char cache[cachesize];
		char *pos, *cur, *end;

 		pos = strstr(result, "rtsp://");
		if(pos == nullptr) return;

		cur = pos + strlen("rtsp://");
		end = result + strlen(result);

		while(*cur != '/' && cur != end) cur++;

		while((i < cachesize) && (i < cur - pos))
		{
			cache[i] = pos[i]
			i++
		}

		i = 0;
		cache[i] = '\0';

		pos = cache;
		cur = pos;
		end = strchr(cur, '@');
		if(end == nullptr) return;

		while(*cur != ':' && cur != '\0') cur++;
		if(cur == '\0') return;

		if(cur - pos == 0) return;

		bzero(buf, bufsize);

		while((i < bufsize) && (i < cur - pos))
		{
			buf[i] = pos[i];
			i++;
		}

		buf[i] = '\0';
	}

	void RTSPRequestParser::parsePassword(char buf, int bufsize)
	{
		if(buf == nullptr || reslen <= 1) return;

		int i = 0;
		int cachesize = 1024;
		char cache[cachesize];
		char *pos, *cur, *end;

 		pos = strstr(result, "rtsp://");
		if(pos == nullptr) return;

		cur = pos + strlen("rtsp://");
		end = result + strlen(result);

		while(*cur != '/' && cur != end) cur++;

		while((i < cachesize) && (i < cur - pos))
		{
			cache[i] = pos[i]
			i++
		}

		i = 0;
		cache[i] = '\0';

		pos = cache;
		cur = pos;
		end = strchr(cur, '@');
		if(end == nullptr) return;

		while(*cur != ':' && cur != '\0') cur++;
		if(cur == '\0') return;

		if(cur - pos == 0) return;
		cur++;

		bzero(buf, bufsize);

		while((i < bufsize) && (i < end - cur))
		{
			buf[i] = cur[i];
			i++;
		}

		buf[i] = '\0';
	}

	void RTSPRequestParser::parseURL(char buf, int bufsize)
	{
		if(buf == nullptr || reslen <= 1) return;

		int i = 0;
		int cachesize = 1024;
		char cache[cachesize];
		char *pos, *cur, *end;

 		pos = strstr(result, "rtsp://");
		if(pos == nullptr) return;

		cur = pos;
		end = result + strlen(result);

		while(*cur != '/' && cur != end) cur++;
	}

	 int RTSPRequestParser::parsePort(const char *uri)
	 {
	 	 
	 }

	void RTSPRequestParser::parseURN(const char *uri)
	{
		
	}

	void RTSPRequestParser::parseAccept(const char *message)
	{
		if(message == NULL) return;

		int i = 0;
		char *pos = strstr(message, "Accept: ");

		if(pos == NULL) return -1;

		reset();

		while(*pos++ != ' ');

		while(i < ressize && pos[i] != '\r')
		{
			result[i] = pos[i];
			i++;
		}

		result[i] = '\0';
		reslen = strlen(result);		
	}

	void RTSPRequestParser::parseAcceptEncoding(const char *message)
	{
		if(message == NULL) return;

		int i = 0;
		char *pos = strstr(message, "Accept-Encoding: ");

		if(pos == NULL) return -1;

		reset();

		while(*pos++ != ' ');

		while(i < ressize && pos[i] != '\r')
		{
			result[i] = pos[i];
			i++;
		}

		result[i] = '\0';
		reslen = strlen(result);		
	}

	void RTSPRequestParser::parseAcceptLanguage(const char *message)
	{
		if(message == NULL) return;

		int i = 0;
		char *pos = strstr(message, "Accept-Language: ");

		if(pos == NULL) return -1;

		reset();

		while(*pos++ != ' ');

		while(i < ressize && pos[i] != '\r')
		{
			result[i] = pos[i];
			i++;
		}

		result[i] = '\0';
		reslen = strlen(result);	
	}

	void RTSPRequestParser::parseBandwidth(const char *message)
	{
		if(message == NULL) return;

		int i = 0;
		char bufsize = 8;
		char buf[bufsize];

		char *pos = strstr(message, "Bandwidth: ");
		if(pos == NULL) return -1;

		while(*pos++ != ' '); 

		while(i < bufsize && pos[i] != '\r')
		{
			buf[i] = pos[i];
			i++;
		}
		
		buf[i] = '\0';
		
		return strtol(buf, NULL, 10);	
	}

	 int RTSPRequestParser::parseBlocksize(const char *message)
	 {
		if(message == NULL) return;

		int i = 0;
		char bufsize = 8;
		char buf[bufsize];

		char *pos = strstr(message, "Blocksize: ");
		if(pos == NULL) return -1;

		while(*pos++ != ' '); 

		while(i < bufsize && pos[i] != '\r')
		{
			buf[i] = pos[i];
			i++;
		}
		
		buf[i] = '\0';
		
		return strtol(buf, NULL, 10);		 
	 }

	void RTSPRequestParser::parseConference(const char *message)
	{
		if(message == NULL) return;

		int i = 0;
		char *pos = strstr(message, "Conference: ");

		if(pos == NULL) return -1;

		reset();

		while(*pos++ != ' ');

		while(i < ressize && pos[i] != '\r')
		{
			result[i] = pos[i];
			i++;
		}

		result[i] = '\0';
		reslen = strlen(result);
	}

	void RTSPRequestParser::parseFrom(const char *message)
	{
		if(message == NULL) return;

		int i = 0;
		char *pos = strstr(message, "From: ");

		if(pos == NULL) return -1;

		reset();

		while(*pos++ != ' ');

		while(i < ressize && pos[i] != '\r')
		{
			result[i] = pos[i];
			i++;
		}

		result[i] = '\0';
		reslen = strlen(result);
	}

	void RTSPRequestParser::parseIfModifiedSince(const char *message)
	{
		if(message == NULL) return;

		int i = 0;
		char *pos = strstr(message, "If-Modified-Since: ");

		if(pos == NULL) return -1;

		reset();

		while(*pos++ != ' ');

		while(i < ressize && pos[i] != '\r')
		{
			result[i] = pos[i];
			i++;
		}

		result[i] = '\0';
		reslen = strlen(result);
	}

	void RTSPRequestParser::parseProxyRequire(const char *message)
	{
		if(message == NULL) return;

		int i = 0;
		char *pos = strstr(message, "Proxy-Require: ");

		if(pos == NULL) return -1;

		reset();

		while(*pos++ != ' ');

		while(i < ressize && pos[i] != '\r')
		{
			result[i] = pos[i];
			i++;
		}

		result[i] = '\0';
		reslen = strlen(result);		
	}

	void RTSPRequestParser::parseReferer(const char *message)
	{
		if(message == NULL) return;

		int i = 0;
		char *pos = strstr(message, "Referer: ");

		if(pos == NULL) return -1;

		reset();

		while(*pos++ != ' ');

		while(i < ressize && pos[i] != '\r')
		{
			result[i] = pos[i];
			i++;
		}

		result[i] = '\0';
		reslen = strlen(result);		
	}

	void RTSPRequestParser::parseReuire(const char *message)
	{
		if(message == NULL) return;

		int i = 0;
		char *pos = strstr(message, "Reuire: ");

		if(pos == NULL) return -1;

		reset();

		while(*pos++ != ' ');

		while(i < ressize && pos[i] != '\r')
		{
			result[i] = pos[i];
			i++;
		}

		result[i] = '\0';
		reslen = strlen(result);		
	}

	void RTSPRequestParser::parseUserAgent(const char *message)
	{
		if(message == NULL) return;

		int i = 0;
		char *pos = strstr(message, "User-Agent: ");

		if(pos == NULL) return -1;

		reset();

		while(*pos++ != ' ');

		while(i < ressize && pos[i] != '\r')
		{
			result[i] = pos[i];
			i++;
		}

		result[i] = '\0';
		reslen = strlen(result);		
	}
