// rtspparser.cpp - реализация методов класса RTSPParser

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include "rtspparser.h"

	RTSPParser::RTSPParser()
	{
		/* Конструктор класса по умолчанию */

			reslen = 0;
			bzero(result, ressize);
			errstr = nullptr;
	}

	void RTSPParser::parseCacheControl(const char *message)
	{
		if(message == NULL) return;

		int i = 0;
		char *pos = strstr(message, "Content-Control: ");

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

	void RTSPParser::parseConnection(const char *message)
	{
		if(message == NULL) return;

		int i = 0;
		char *pos = strstr(message, "Connection: ");

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

	void RTSPParser::parseContentBase(const char *message)
	{
		if(message == NULL) return;

		int i = 0;
		char *pos = strstr(message, "Content-Base: ");

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

	void RTSPParser::parseContentEncoding(const char *message)
	{
		if(message == NULL) return;

		int i = 0;
		char *pos = strstr(message, "Content-Encoding: ");

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

	void RTSPParser::parseContentLanguage(const char *message)
	{
		if(message == NULL) return;

		int i = 0;
		char *pos = strstr(message, "Content-Language: ");

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

	int RTSPParser::parseContentLength(const char *message)
	{
		if(message == NULL) return;

		int i = 0;
		char *pos;
		char bufsize = 16;
		char buf[bufsize];

		pos = strstr(message, "Content-Length: ");
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

	void RTSPParser::parseContentLocation(const char *message)
	{
		if(message == NULL) return;

		int i = 0;
		char *pos = strstr(message, "Content-Location: ");

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

	void RTSPParser::parseContentType(const char *message)
	{
		if(message == NULL) return;

		int i = 0;
		char *pos = strstr(message, "Content-Type: ");

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

	void RTSPParser::parseContentTypeMediaType(char *buf, int bufsize)
	{
		if(reslen == 0) return;

		int i = 0;
		char *pos = result;
		
		while(i < bufsize && pos[i] != ';' && pos[i] != '\r')
		{
			buf[i] = pos[i];
			i++;
		}

		buf[i] = '\0';						
	}

	void RTSPParser::parseContentTypeCharset(char *buf, int bufsize)
	{
		if(reslen == 0) return;

		int i = 0;
		char *pos = strstr(result, "charset=");

		while(i < bufsize && pos[i] != ';' && pos[i] != '\r')
		{
			buf[i] = pos[i];
			i++;
		}

		buf[i] = '\0';
	}

	int RTSPParser::parseCSeq(const char *message)
	{
		/* Получение номера сообщения */

			if(message == NULL) return;

			int i = 0;
			char bufsize = 16;
			char buf[bufsize];

			char *pos = strstr(message, "CSeq: ");
			if(pos == NULL) return -1;

			reset();

			while(*pos++ != ' '); 

			while(i < bufsize && pos[i] != '\r')
			{
				buf[i] = pos[i];
				i++;
			}
			
			buf[i] = '\0';
			
			return strtol(buf, NULL, 10);	
	}

	void RTSPParser::parseDate(const char *message)
	{

		if(message == NULL) return;

		int i = 0;
		char *pos = strstr(message, "Date: ");

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

	void RTSPParser::parseExpires(const char *message)
	{
		if(message == NULL) return;

		int i = 0;
		char *pos = strstr(message, "Expires: ");

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

	void RTSPParser::parseLastModified(const char *message)
	{
		if(message == NULL) return;

		int i = 0;
		char *pos = strstr(message, "Last-Modified: ");

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

	void RTSPParser::parseRange(const char *message)
	{
		if(message == NULL) return;

		int i = 0;
		char *pos = strstr(message, "Range: ");

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

	double RTSPParser::parseScale(const char *message)
	{
		if(message == NULL) return;

		int i = 0;
		char *pos;
		int bufsize = 16;
		char buf[bufsize]; 

		pos = strstr(message, "Scale: ");
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

	void RTSPParser::parseServer(const char *message)
	{
		if(message == NULL) return;

		int i = 0;
		char *pos = strstr(message, "Server: ");

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

	void RTSPParser::parseSession(const char *message)
	{
		if(message == NULL) return;

		int i = 0;
		char *pos = strstr(message, "Session:");

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

	void RTSPParser::parseSessionID(char *buf, int bufsize)
	{
		if(reslen == 0) return;

		int i = 0;
		char *pos = result;

		while(*pos++ != ' ');

		while(i < bufsize && pos[i] != ';' && pos[i] != '\r')
		{
			buf[i] = pos[i];
			i++;
		}

		buf[i] = '\0';
	}

	int RTSPParser::parseSessionTimeout()
	{
		if(strstr(result, "Session:") == NULL) return;

		int i = 0;
		char *pos;
		char bufsize = 8;
		char buf[bufsize];

		pos = strstr(result, "timeout=");
		if(pos == NULL) return -1;

		while(*pos++ != '=');

		while(i < bufsize && pos[i] != ';' && pos[i] != '\r')
		{
			buf[i] = pos[i];
			i++;
		}

		buf[i] = '\0';

		return strtol(buf, NULL, 10);
	}

	int RTSPParser::parseSpeed(const char *message)
	{
		if(message == NULL) return;

		int i = 0;
		char bufsize = 8;
		char buf[bufsize];

		char *pos = strstr(message, "Speed: ");
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

	void RTSPParser::parseVia(const char *message)
	{
		if(message == NULL) return;

		int i = 0;
		char *pos = strstr(message, "Via:");

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

	void RTSPParser::reset()
	{
		/* Сброс данных класса */

			reslen = 0;
			bzero(result, ressize);
			errstr = 0;			
	}
