#ifndef SICT_MESSAGE_H
#define SICT_MESSAGE_H
/*
 ============================================================================
 Name        : Message.h
 Author      : Adam Stinziani
 Email       : astinziani@myseneca.ca
 Student #   : 124 521 188
 Course Code : OOP345
 Section     : SCC
 Date        : 2019-06-06
 Workshop    : Workshop 4 - Lab
 ============================================================================
 */

 /*
  ============================================================================
  Description : Message class decleration
  ============================================================================
 */

#include <string>
#include <ostream>

namespace sict {
	class Message {
		std::string user;
		std::string reply;
		std::string message;
	public:
		Message();
		Message(const std::string& str);
		bool empty() const;
		void display(std::ostream& os) const;
	};
}

#endif