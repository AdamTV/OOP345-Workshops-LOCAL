#define _CRT_SECURE_NO_WARNINGS
/*
 ============================================================================
 Name        : String.cpp
 Author      : Adam Stinziani
 Email       : astinziani@myseneca.ca
 Student #   : 124521188
 Course Code : OOP345
 Section     : SCC
 Date        : 2019-05-15
 Workshop    : Workshop 1 - Lab
 ============================================================================
 */

 /*
  ============================================================================
  Description : String class
  ============================================================================
 */

#include <cstring>
#include "String.h"

extern const int INITIAL;
int initial = INITIAL;

namespace sict {

	String::String(const char* string_n)
	{
		if (string_n != nullptr) {
			strncpy(string, string_n, MAX);
			string[MAX] = '\0';
		}
		else {
			string[0] = '\0';
		}
	}
	void String::display(std::ostream& o) const
	{
		o << string;
	}
	std::ostream& operator<<(std::ostream& o, String& source)
	{
		
		o << initial++ << ": ";
		source.display(o);
		return o;
	}
}