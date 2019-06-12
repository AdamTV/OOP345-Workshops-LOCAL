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

namespace sict 
{

	// Default no-argument constructor to set safe-empty state and initialize all variables
	MessagePack::MessagePack() 
	{
		currentSize = 0;
		messages = nullptr;
	}

	// Two-argument constructor to initialize object dynamically 
	MessagePack::MessagePack(Message** messages_n, int size_n)
	{
		if (size_n > 0 && messages_n != nullptr) 
		{
			currentSize = size_n - 1;
			messages = new Message * [size_n];
			int no_msgs = 0;
			for (int i = 0; i < size_n; i++) 
			{
				if (!messages_n[i]->empty()) 
				{
					messages[no_msgs] = messages_n[i];
					no_msgs++;
				}
			}
		}
		else {
			*this = MessagePack();
		}
	}

	// Copy constructor 
	MessagePack::MessagePack(const MessagePack& src)
	{
		// Calls assignment operator
		*this = src;
	}

	// Move-assignment operator
	MessagePack& MessagePack::operator= (MessagePack&& src) noexcept
	{
		if (this != &src) 
		{
			delete[] messages;
			messages = src.messages;
			currentSize = src.currentSize;

			src.currentSize = 0;
			src.messages = nullptr;
		}
		return *this;
	}

	// Copy assignment operator
	MessagePack& MessagePack::operator=(const MessagePack& src)
	{
		if (this != &src) 
		{
			delete[] messages;
			messages = new Message * [src.size()];

			for (size_t i = 0; i < src.size(); i++) 
				messages[i] = src.messages[i];
			
			currentSize = src.currentSize;
		}
		return *this;
	}

	// Overloaded extraction operator
	std::ostream& operator<<(std::ostream& os, MessagePack& src)
	{
		src.display(os);
		return os;
	}

	// Destructor to clean up class resource
	MessagePack::~MessagePack()
	{
		delete[] messages;
		messages = nullptr;
	}

	// Method to display current object
	void MessagePack::display(std::ostream& os) const
	{
		for (size_t i = 0; i < size(); i++) 
		{
			messages[i]->display(os);
		}
	}

	// Method to return size of current object
	size_t MessagePack::size() const
	{
		return currentSize;
	}
}