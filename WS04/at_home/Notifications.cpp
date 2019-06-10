/*
 ============================================================================
 Name        : Notifications.cpp
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
  Description : Notifications class definition
  ============================================================================
 */

#include "Notifications.h"

namespace sict {
	Notifications::Notifications()
	{
		currentMax = 0;
		notifications = nullptr;
	}
	Notifications::Notifications(int max_n)
	{
		if (max_n > 0) {
			notifications = new (const Message * [max_n]);
			currentMax = max_n;
			currentSize = 0;
		}
		else {
			*this = Notifications();
		}
	}
	Notifications& Notifications::operator=(Notifications&& src)
	{
		if (this != &src) {
			currentSize = src.currentSize;
			currentMax = src.currentMax;

			delete[] notifications;
			notifications = new (const Message * [src.size()]);
			for (int i = 0; i < src.size(); i++) {
				notifications[i] = src.notifications[i];
			}
			src.notifications = nullptr;
			src.currentMax = 0;
			src.currentSize = 0;
		}
		return *this;
	}
	Notifications& Notifications::operator+=(const Message& msg)
	{
		if (!msg.empty() && currentSize < currentMax) {
			notifications[currentSize] = &msg;
			currentSize++;
		}
		return *this;
	}
	Notifications& Notifications::operator-=(const Message& msg)
	{
		int foundAt;
		bool found = false;
		for (int i = 0; i < size() && !found; i++) {
			if (notifications[i] == &msg) {
				notifications[i] = nullptr;
				currentSize--;
				found = true;
				foundAt = i;
			}
		}
		if (found) {
			for (int i = foundAt; i < (size() + 1); i++) {
				notifications[i] = notifications[i + 1];
			}
		}
		return *this;
	}
	void Notifications::display(std::ostream& os) const
	{
		for (int i = 0; i < size(); i++) {
			if(notifications[i] != nullptr)
			notifications[i]->display(os);
		}
	}
	size_t Notifications::size() const
	{
		return currentSize;
	}
	std::ostream& operator<<(std::ostream& os, Notifications& src)
	{
		src.display(os);
		return os;
	}
}