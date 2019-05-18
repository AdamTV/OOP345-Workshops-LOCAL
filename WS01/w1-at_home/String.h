#ifndef SICT_STRING_H
#define SICT_STRING_H
/*
 ============================================================================
 Name        : String.h
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
#include <iostream>

namespace sict {
	const int MAX = 3;
	class String {
		char* string;
	public:
		String(const char* string_n);
		~String();
		void display(std::ostream& o) const;
	};
	std::ostream& operator<<(std::ostream&, String& source);
}
#endif // !SICT_STRING_H
