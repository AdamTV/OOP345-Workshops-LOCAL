/*
 ============================================================================
 Name        : Timekeeper.cpp
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
  Description : Timekeeper class definition
  ============================================================================
 */
#include <iomanip>
#include <iostream>
#include "Timekeeper.h"

namespace sict {
	//Default, no-argument constructor
	sict::Timekeeper::Timekeeper()
	{
		stored = 0;
	}

	//Start function to begin timing
	void sict::Timekeeper::start()
	{
		begin = std::chrono::steady_clock::now();
	}

	//Stop function to end timing
	void sict::Timekeeper::stop()
	{
		end = std::chrono::steady_clock::now();
	}

	//Function to save the record of an event
	void sict::Timekeeper::recordEvent(const char* message_n)
	{
		if (stored < MAX_RECORDS) {
			record[stored].message = message_n;
			record[stored].duration = end - begin;
			stored++;
		}
	}

	//Function to display report of events
	void sict::Timekeeper::report(std::ostream& o) const
	{
		using namespace std::chrono;
		o << "Execution Times:\n";
		for (int i = 0; i < stored; i++)
			o << record[i].message << std::setw(6) << duration_cast <milliseconds>(record[i].duration).count() << " " << record[i].timeUnits << std::endl;
	}
}
