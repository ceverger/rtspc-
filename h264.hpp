#include <cstdint>

#ifndef H264_HPP
#define H264_HPP

	class H264NalUnit
	{
		private:

			uint8_t hdr;  // Дубликат заголовока nal unit
			uint8_t *pos; // Начальная позиция буфера с nal unit, в котором хранится поток h264
			uint8_t *end; // Конечная позиция буфера с nal unit, в котром хранится поток h264		

		public:

			/* Конструкторы и деструкторы класса */

				H264NalUnit();
				virtual ~H264NalUnit() {}

			/* Селекторы класса */

				int getSize() const;
				uint8_t *getPosition() const;
				uint8_t *getPayload() const;
				int getPayloadLen() const;

				uint8_t getForbiddenBit() const;
				uint8_t getReferenceIDC() const;
				uint8_t getPayloadType() const;

				friend uint8_t HDRGet(H264NaluUnit & nu);
				friend uint8_t HDRGetForbiddenBit(H264NaluUnit & nu);
				friend uint8_t HDRGetReferenceIDC(H264NaluUnit & nu);
				friend uint8_t HDRGetPayloadType( H264NaluUnit & nu);

			/* Модификаторы класса */

				void setPosition(uint8_t *position);

				friend uint8_t HDRSetForbiddenBit(uint8_t forbiddenBit, H264NaluUnit & nu);
				friend uint8_t HDRSetReferenceIDC(uint8_t referenceIDC, H264NaluUnit & nu);
				friend uint8_t HDRSetPayloadType(uint8_t payloadType, H264NaluUnit & nu);

			/* Другие методы класса */

				bool init();
				void reset();
			

	
	}; // H264NalUnit


	class H264AccessUnit
	{
		private:

			uint8_t *pos; // Начальная позиция буфера с access unit, в котором хранится поток h264
			uint8_t *cur; // Текущая позиция буфера с access unit, в котором хранится поток h264
			uint8_t *end; // Конечная позиция буфера с access unit, в котром хранится поток h264
		
		public:

			H264AccessUnit();
			virtual ~H264AccessUnit() {}

			int getSize() const;
			uint8_t *getPosition() const;

			void parseNalUnit(H264NalUnit & nu);

	}; // H264AccessUnit


	class H264Parser
	{
		private:

			uint8_t *pos; // Начальная позиция буфера, в котором хранится поток h264
			uint8_t *cur; // Текущая позиция буфера, в котором хранится поток h264
			uint8_t *end; // Конечная позиция буфера, в котром хранится поток h264

		public:

			H264Parser();
			virtual ~H264Parser() {}

			int getAUCout() const;

			void parseAU(H264AccessUnit & au);
			
		
	}; // class H264Parser


#endif // H264_HPP
