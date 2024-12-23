#ifndef SICT_NOTIFICATIONS_H
#define SICT_NOTIFICATIONS_H
/*
 ============================================================================
 Name        : Notifications.h
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
  Description : Notifications class deceleration
  ============================================================================
 */

#include "Message.h"

namespace sict 
{

	//Notifications class to manage an aggregation of Message objects
	class Notifications 
	{
		const Message** notifications = nullptr;
		int currentMax;
		int currentSize;
	public:
		Notifications();
		Notifications(int);
		Notifications(const Notifications&);
		// Move constructor
		Notifications(Notifications&& src) noexcept { *this = std::move(src); }
		~Notifications();
		Notifications& operator=(Notifications&& src) noexcept;
		Notifications& operator=(const Notifications& src);
		Notifications& operator+=(const Message& msg);
		Notifications& operator-=(const Message& msg);
		void display(std::ostream& os) const;
		size_t size() const;
	};
	std::ostream& operator<<(std::ostream& os, Notifications& src);
}

#endif