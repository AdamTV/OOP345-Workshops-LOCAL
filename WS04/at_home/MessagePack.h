#ifndef SICT_MESSAGEPACK_H
#define SICT_MESSAGEPACK_H
/*
 ============================================================================
 Name        : MessagePack.h
 Author      : Adam Stinziani
 Email       : astinziani@myseneca.ca
 Student #   : 124 521 188
 Course Code : OOP345
 Section     : SCC
 Date        : 2019-06-10
 Workshop    : Workshop 4 - Home
 ============================================================================
 */

 /*
  ============================================================================
  Description : MessagePack class decleration
  ============================================================================
 */

#include "Message.h"

namespace sict {

	//MessagePack class to hold composition of Message objects
	class MessagePack {
		Message** messages = nullptr;
		int currentSize;
	public:
		MessagePack();
		MessagePack(Message**, int);
		MessagePack(const MessagePack&);
		MessagePack(MessagePack&& src) noexcept { *this = std::move(src); }
		MessagePack& operator=(MessagePack&& src);
		MessagePack& operator=(const MessagePack&);
		~MessagePack();
		void display(std::ostream& os) const;
		size_t size() const;
	};
	std::ostream& operator<<(std::ostream& os, MessagePack&);
}

#endif