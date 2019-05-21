/*
 ============================================================================
 Name        : Text.cpp
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
  Description : Text class definition
  ============================================================================
 */
#include <fstream>
#include <iostream>
#include "Text.h"

namespace sict {
	Text::Text()
	{
		stored = 0;
		strings = nullptr;
	}

	Text::Text(char* name)
	{
		*this = Text();
		std::ifstream input(name);
		if (input) {
			while (input.good()) {
				std::string tmp;
				std::getline(input, tmp, '\n');
				stored++;
			}
			strings = new std::string[stored];
			for (int i = 0; i < stored; i++) {
				std::string tmp;
				std::getline(input, tmp, '\n');
				strings[i] = tmp;
			}
		}
	}

	Text::Text(const Text& src)
	{
		*this = Text();
		*this = src;
	}

	Text& Text::operator=(const Text& src)
	{
		if (this != &src) {
			stored = src.stored;
			if (stored > 0)
				delete[] strings;
			strings = new std::string[stored];
			for (int i = 0; i < stored; i++)
				strings[i] = src.strings[i];
		}
		return *this;
	}

	Text::~Text()
	{
		delete[] strings;
		strings = nullptr;
	}

	size_t Text::size() const
	{
		return stored;
	}
}
