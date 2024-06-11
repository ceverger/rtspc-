// requestparser.cpp - реализация методов класса RTSPRequestParser

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include "requestparser.hpp"

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

		if(strstr(pos, "rtsp://") == NULL) return;

		while(i < ressize && pos[i] != ' ')
		{
			result[i] = pos[i];
			i++;			
		}

		result[i] = '\0';
		reslen = strlen(result);
	}

	void RTSPRequestParser::parseLogin(char *buf, int bufsize)
	{
		if(buf == NULL || reslen <= 1) return;

		int i = 0;
		int cachesize = 1024;
		char cache[cachesize];
		char *pos, *cur, *end;

 		pos = strstr(result, "rtsp://");
		if(pos == NULL) return;

		cur = pos + strlen("rtsp://");
		end = result + strlen(result);

		while(*cur != '/' && cur != end) cur++;

		while((i < cachesize) && (i < cur - pos))
		{
			cache[i] = pos[i];
			i++;
		}

		i = 0;
		cache[i] = '\0';

		pos = cache;
		cur = pos;
		end = strchr(cur, '@');
		if(end == NULL) return;

		while(*cur != ':' && *cur != '\0') cur++;
		if(*cur == '\0') return;

		if(cur - pos == 0) return;

		bzero(buf, bufsize);

		while((i < bufsize) && (i < cur - pos))
		{
			buf[i] = pos[i];
			i++;
		}

		buf[i] = '\0';
	}

	void RTSPRequestParser::parsePassword(char *buf, int bufsize)
	{
		if(buf == NULL || reslen <= 1) return;

		int i = 0;
		int cachesize = 1024;
		char cache[cachesize];
		char *pos, *cur, *end;

 		pos = strstr(result, "rtsp://");
		if(pos == NULL) return;

		cur = pos + strlen("rtsp://");
		end = result + strlen(result);

		while(*cur != '/' && cur != end) cur++;

		while((i < cachesize) && (i < cur - pos))
		{
			cache[i] = pos[i];
			i++;
		}

		i = 0;
		cache[i] = '\0';

		pos = cache;
		cur = pos;
		end = strchr(cur, '@');
		if(end == NULL) return;

		while(*cur != ':' && *cur != '\0') cur++;
		if(*cur == '\0') return;

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

	void RTSPRequestParser::parseURL(char *buf, int bufsize)
	{
		if(buf == NULL || reslen <= 1) return;

		int i = 0;
		int cachesize = 1024;
		char cache[cachesize];
		char *pos, *cur, *end;

 		pos = strstr(result, "rtsp://");
		if(pos == NULL) return;

		cur = pos;
		end = result + strlen(result);

		while(*cur != '/' && cur != end) cur++;
	}

	 int RTSPRequestParser::parsePort()
	 {
	 	 return 0;
	 }

	void RTSPRequestParser::parseURN(char *buf, int bufsize)
	{
		
	}

	void RTSPRequestParser::parseAccept(char *message)
	{
		if(message == NULL) return;

		int i = 0;
		char *pos = strstr(message, "Accept: ");

		if(pos == NULL) return;

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

	void RTSPRequestParser::parseAcceptEncoding(char *message)
	{
		if(message == NULL) return;

		int i = 0;
		char *pos = strstr(message, "Accept-Encoding: ");

		if(pos == NULL) return;

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

	void RTSPRequestParser::parseAcceptLanguage(char *message)
	{
		if(message == NULL) return;

		int i = 0;
		char *pos = strstr(message, "Accept-Language: ");

		if(pos == NULL) return;

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

	int RTSPRequestParser::parseBandwidth(char *message)
	{
		if(message == NULL) return -1;

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

	 int RTSPRequestParser::parseBlocksize(char *message)
	 {
		if(message == NULL) return -1;

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

	void RTSPRequestParser::parseConference(char *message)
	{
		if(message == NULL) return;

		int i = 0;
		char *pos = strstr(message, "Conference: ");

		if(pos == NULL) return;

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

	void RTSPRequestParser::parseFrom(char *message)
	{
		if(message == NULL) return;

		int i = 0;
		char *pos = strstr(message, "From: ");

		if(pos == NULL) return;

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

	void RTSPRequestParser::parseIfModifiedSince(char *message)
	{
		if(message == NULL) return;

		int i = 0;
		char *pos = strstr(message, "If-Modified-Since: ");

		if(pos == NULL) return;

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

	void RTSPRequestParser::parseProxyRequire(char *message)
	{
		if(message == NULL) return;

		int i = 0;
		char *pos = strstr(message, "Proxy-Require: ");

		if(pos == NULL) return;

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

	void RTSPRequestParser::parseReferer(char *message)
	{
		if(message == NULL) return;

		int i = 0;
		char *pos = strstr(message, "Referer: ");

		if(pos == NULL) return;

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

	void RTSPRequestParser::parseReuire(char *message)
	{
		if(message == NULL) return;

		int i = 0;
		char *pos = strstr(message, "Reuire: ");

		if(pos == NULL) return;

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

	void RTSPRequestParser::parseUserAgent(char *message)
	{
		if(message == NULL) return;

		int i = 0;
		char *pos = strstr(message, "User-Agent: ");

		if(pos == NULL) return;

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
