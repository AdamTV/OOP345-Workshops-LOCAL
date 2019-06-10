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

namespace sict 
{

	// Default no-argument constructor to set safe-empty state and initialize all variables
	Notifications::Notifications()
	{
		currentSize = 0;
		currentMax = 0;
		notifications = nullptr;
	}

	// Two-argument constructor to initialize object dynamically 
	Notifications::Notifications(int max_n)
	{
		if (max_n > 0) 
		{
			notifications = new (const Message * [max_n]);
			currentMax = max_n;
			currentSize = 0;
		}
		else {
			*this = Notifications();
		}
	}

	// Copy constructor
	Notifications::Notifications(const Notifications& src)
	{
		*this = src;
	}

	// Destructor
	Notifications::~Notifications()
	{
		delete[] notifications;
		notifications = nullptr;
	}

	// Move-assignment operator
	Notifications& Notifications::operator=(Notifications&& src) noexcept
	{
		if (this != &src) 
		{
			delete[] notifications;
			notifications = src.notifications;
			currentMax = src.currentMax;
			currentSize = src.currentSize;

			src.notifications = nullptr;
			src.currentMax = 0;
			src.currentSize = 0;
		}
		return *this;
	}

	// Copy assignment operator
	Notifications& Notifications::operator=(const Notifications& src)
	{
		if (this != &src) 
		{
			currentSize = src.currentSize;
			currentMax = src.currentMax;

			delete[] notifications;
			notifications = new (const Message * [src.size()]);
			for (int i = 0; i < src.size(); i++)
			{
				notifications[i] = src.notifications[i];
			}
		}
		return *this;
	}

	// Overloaded += operator to add Message object to aggregation
	Notifications& Notifications::operator+=(const Message& msg)
	{
		if (!msg.empty() && currentSize < currentMax)
		{
			notifications[currentSize] = &msg;
			currentSize++;
		}
		return *this;
	}

	// Overloaded -= operator to remove Message object from aggregation
	Notifications& Notifications::operator-=(const Message& msg)
	{
		int foundAt;
		bool found = false;
		for (int i = 0; i < size() && !found; i++) 
		{
			if (notifications[i] == &msg) 
			{
				notifications[i] = nullptr;
				currentSize--;
				found = true;
				foundAt = i;
			}
		}
		if (found) 
		{
			for (int i = foundAt; i < (size() + 1); i++)
			{
				notifications[i] = notifications[i + 1];
			}
		}
		return *this;
	}

	// Method to display contents of current object
	void Notifications::display(std::ostream& os) const
	{
		for (int i = 0; i < size(); i++) 
		{
			if(notifications[i] != nullptr)
			notifications[i]->display(os);
		}
	}

	// Method to determine size of current object
	size_t Notifications::size() const
	{
		return currentSize;
	}

	// Overloaded extraction operator to display object
	std::ostream& operator<<(std::ostream& os, Notifications& src)
	{
		src.display(os);
		return os;
	}
}