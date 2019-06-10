/*
 ============================================================================
 Name        : MessagePack.cpp
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
  Description : MessagePack class definition
  ============================================================================
 */

#include "MessagePack.h"

namespace sict {
	//Default no-argument constructor to set safe-empty state and initialize all variables
	MessagePack::MessagePack() {
		currentSize = 0;
		messages = nullptr;
	}
	//Two-argument constructor to initialize object 
	MessagePack::MessagePack(Message** messages_n, int size_n) {
		if (size_n > 0 && messages_n != nullptr) {
			currentSize = size_n - 1;
			messages = new Message*[size_n];
			int no_msgs = 0;
			for (int i = 0; i < size_n; i++) {
				if (!messages_n[i]->empty()) {
					messages[no_msgs] = messages_n[i];
					no_msgs++;
				}
			}
		}
		else {
			*this = MessagePack();
		}
	}
	MessagePack::MessagePack(const MessagePack& src)
	{
		*this = src;
	}
	MessagePack& MessagePack::operator=(MessagePack&& src)
	{
		if (this != &src) {
			*this = src;

			src.currentSize = 0;
			src.messages = nullptr;
		}
		return *this;
	}
	MessagePack& MessagePack::operator=(const MessagePack& src)
	{
		if (this != &src) {
			delete[] messages;
			messages = new Message * [src.size()];
			for (int i = 0; i < src.size(); i++) {
				messages[i] = src.messages[i];
			}
			currentSize = src.currentSize;
		}
		return *this;
	}
	std::ostream& operator<<(std::ostream& os, MessagePack& src)
	{
		src.display(os);
		return os;
	}
	MessagePack::~MessagePack()
	{
		delete[] messages;
		messages = nullptr;
	}
	void MessagePack::display(std::ostream& os) const
	{
		for (int i = 0; i < size(); i++) {
			messages[i]->display(os);
		}
	}
	size_t MessagePack::size() const
	{
		return currentSize;
	}
}