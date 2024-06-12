// requestparser.hpp - описание класса RTSPRequestParser для парсинга rtsp-запросов

#include "rtspparser.hpp"

#ifndef RTSP_REQUEST_PARSER_HPP

	class RTSPRequestParser : public RTSPParser 
	{
		public:

			/* Конструкторы и деструкторы класса */

				RTSPRequestParser() : RTSPParser() {}
				virtual ~RTSPRequestParser() {}

			/* Методы для парсинга rtsp-запроса */

				void parseMethod(const char *message);

				void parseURL(const char *message);
				void parseLogin(char *buf, int bufsize);
				void parsePassword(char *buf, int bufsize);
				void parseHost(char *buf, int bufsize);
				 int parsePort();
				void parseURI(char *buf, int bufsize);
				void parseURN(char *buf, int bufsize);

				void parseVersion(char *message);

				void parseAccept(char *message);
				void parseAcceptEncoding(char *message);
				void parseAcceptLanguage(char *message);

				void parseAuthorization(char *message);
				 int parseBandwidth(char *message);
				 int parseBlocksize(char *message);
				void parseConference(char *message);
				void parseFrom(char *message);
				void parseIfModifiedSince(char *message);
				void parseProxyRequire(char *message);
				void parseReferer(char *message);
				void parseReuire(char *message);
				void parseUserAgent(char *message);

			/* Чекеры класса  */

				bool messageIsRequest(const char *message) const;
				
	}; // RTSPRequestParser

#endif // RTSP_REQUEST_PARSER_HPP
