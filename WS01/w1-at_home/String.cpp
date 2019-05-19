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
 Workshop    : Workshop 1 - Home
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
			int length = strlen(string_n);
			string = new char[length];
			strncpy(string, string_n, length);
			string[length] = '\0';
		}
		else {
			string = nullptr;
		}
	}
	String::~String()
	{
		delete [] string;
		string = nullptr;
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