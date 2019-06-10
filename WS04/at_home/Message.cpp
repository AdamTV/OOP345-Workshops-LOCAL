/*
 ============================================================================
 Name        : Message.cpp
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

#include "Message.h"

namespace sict {

	//Default constructor
	Message::Message()
	{
		//Safe empty state
		user = "Empty";
	}

	//Single argument constructor for parsing
	Message::Message(const std::string& str)
	{
		if (str.length() > 0) {
			std::size_t pos = str.find(" ");
			//Check for empty message
			if (pos != std::string::npos) {
				user = str.substr(0, pos);
				//Check for optional reply field
				if (str.find("@") != std::string::npos) {
					pos += 2;
					std::size_t pos2 = str.find(" ", pos);
					std::size_t pos3 = pos2 - pos;
					reply = str.substr(pos, pos3);
					message = str.substr(pos2 + 1);
				}
				else {
					message = str.substr(pos + 1);
				}
			}
		}
		if (message.length() < 1 || str.length() < 1)
			*this = Message();
	}

	//Function to determine safe empty state
	bool Message::empty() const
	{
		return (user == "Empty");
	}

	//Method to display a message object
	void Message::display(std::ostream& os) const
	{
		if (!empty()) {
			os << ">User  : " << user << std::endl;
			if(reply.length() > 0)
			os << " Reply : " << reply << std::endl;
			os << " Tweet : " << message << std::endl;
		}
	}
}
