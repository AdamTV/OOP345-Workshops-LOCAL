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

	//Default, no-arg ctor
	Text::Text()
	{
		stored = 0;
		strings = nullptr;
	}

	//1-arg ctor
	Text::Text(char* name)
	{
		*this = Text();
		std::ifstream input(name);
		if (input) {
			stored--;
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

	//Copy ctor (calls assignment operator)
	Text::Text(const Text& src)
	{
		*this = Text();
		*this = src;
	}

	//Copy assignment operator for Text class
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

	//Destructor: clean up that garbage!
	Text::~Text()
	{
		delete[] strings;
		strings = nullptr;
	}

	//Query to determine number of strings stored
	size_t Text::size() const
	{
		return stored;
	}
}
