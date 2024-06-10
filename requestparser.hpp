// requestparser.hpp - описание класса RTSPRequestParser для парсинга rtsp-запросов

#include "rtspparser.h"

#ifndef RTSP_REQUEST_PARSER_HPP

	class RTSPRequestParser : public RTSPParser 
	{
		public:

			/* Конструкторы и деструкторы класса */

				RTSPRequestParser() : RTSPParser() {}
				virtual ~RTSPRequestParser() {}

			/* Методы для парсинга rtsp-запроса */

				void parseMethod(const char *message);

				void parseURI(const char *message);
				void parseLogin(char buf, int bufsize);
				void parsePassword(char buf, int bufsize);
				void parseURL(char buf, int bufsize);
				 int parsePort();
				void parseURN(char buf, int bufsize);

				void parseVersion(const char *message);

				void parseAccept(const char *message);
				void parseAcceptEncoding(const char *message);
				void parseAcceptLanguage(const char *message);

				void parseAuthorization(const char *message);
				 int parseBandwidth(const char *message);
				 int parseBlocksize(const char *message);
				void parseConference(const char *message);
				void parseFrom(const char *message);
				void parseIfModifiedSince(const char *message);
				void parseProxyRequire(const char *message);
				void parseReferer(const char *message);
				void parseReuire(const char *message);
				void parseUserAgent(const char *message);

			/* Чекеры класса  */

				bool messageIsRequest(const char *message) const;
				
	}; // RTSPRequestParser

#endif // RTSP_REQUEST_PARSER_HPP
