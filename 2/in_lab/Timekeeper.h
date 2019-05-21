#ifndef SICT_TIMEKEEPER_H
#define SICT_TIMEKEEPER_H
/*
 ============================================================================
 Name        : Timekeeper.h
 Author      : Adam Stinziani
 Email       : astinziani@myseneca.ca
 Student #   : 124521188
 Course Code : OOP345
 Section     : SCC
 Date        : 2019-05-20
 Workshop    : Workshop 2 - Lab
 ============================================================================
 */

 /*
  ============================================================================
  Description : Timekeeper class declaration and global variable
  ============================================================================
 */
#include <chrono>

namespace sict
{

	const int MAX_RECORDS = 10;

	class Timekeeper
	{
		int stored;
		std::chrono::steady_clock::time_point begin;
		std::chrono::steady_clock::time_point end;
		struct
		{
			const char* message;
			const char* timeUnits = "seconds";
			std::chrono::steady_clock::duration duration;
		}record[MAX_RECORDS];
	public:
		Timekeeper();
		void start();
		void stop();
		void recordEvent(const char* message_n);
		void report(std::ostream& o) const;
	};
}



#endif // !SICT_TIMEKEEPER_H

