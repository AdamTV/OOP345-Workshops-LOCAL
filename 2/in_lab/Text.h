#ifndef SICT_TEXT_H
#define SICT_TEXT_H
/*
 ============================================================================
 Name        : Text.h
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
  Description : Text class declaration
  ============================================================================
 */
#include <string>

namespace sict {
	class Text {
		int stored;
		std::string* strings;
	public:
		Text();
		Text(char* name);
		Text (const Text& src);
		Text& operator=(const Text& src);
		~Text();
		size_t size() const;
	};
}
#endif
