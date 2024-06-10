/* rtspparser.hpp - описания общего класса RTSPParser для парсинга
						  rtsp-запросов или  rtsp-ответов и получение  
						  необходимых значений строк и полей специфичных
						  для протоколов RTSP/1.0 и RTSP/1.1             */

#ifndef RTSP_PARSER_HPP

	class RTSPParser 
	{
		public:

			enum { ressize = 1024; }; // Максимальный размер буфера для 
											  // сохранения результата парсинга
			
		protected:

			int reslen;			    // Размер полезных данных в буфере
			char result[reslen];  // Буфер для сохранения результата парсинга
			const char *errstr;   // Указтель на строку с ошибкой

		public:

			/* Конструкторы и деструкторы класса */

				RTSPParser();
				virtual ~RTSPParser() {}

			/* Селекторы класса */
		
				int getReslen() const { return reslen; }
				const char *getResult() const { return result; }
				const char *getErrstr() const { return errstr; }

			/* Методы для парсинга rtsp-сообщений */

				void parseCacheControl(const char *message);
				void parseConnection(const char *message);
				void parseContentBase(const char *message);
				void parseContentEncoding(const char *message);
				void parseContentLanguage(const char *message);
				 int parseContentLength(const char *message);
				void parseContentLocation(const char *message);

				void parseContentType(const char *message);
				void parseContentTypeMediaType(char *buf, int bufsize);
				void parseContentTypeCharset(char *buf, int bufsize);

				 int parseCSeq(const char *message);
				void parseDate(const char *message);
				void parseExpires(const char *message);
				void parseLastModified(const char *message);
				void parseRange(const char *message);
			 double parseScale(const char *message);
				void parseServer(const char *message);

				void parseSession(const char *message);
				void parseSessionID(char *buf, int bufsize);
				 int parseSessionTimeout();
				
				 int parseSpeed(const char *message);

				void parseTransport(const char *message);
				void parseTransportProtocol(char *buf, int bufsize);
				void parseTransportProfile(char *buf, int bufsize);
				void parseTransportLower(char *buf, int bufsize);
				void parseTransportTransmission(char *buf, int bufsize);
				void parseTransportDestinationIP(char *buf, int bufsize);
				void parseTransportSourceIP(char *buf, int bufsize);
				void parseTransportClientPort(int *clientRtpPort, int *clientRtcpPort);
				void parseTransportServerPort(int *serverRtpPort, int *serverRtcpPort);
				void parseTransportMode(char *buf, int bufsize);
				void parseTransportSSRC(char *buf, int bufsize);

				void parseVia(const char *message);

			/* Чекеры класса  */
		
				bool isSuccess() const;
				bool isFailed() const;

			/* Другие методы класса */
				
				void reset();
			
	}; // class RTSPParser 

#endif // RTSP_PARSER_HPP
