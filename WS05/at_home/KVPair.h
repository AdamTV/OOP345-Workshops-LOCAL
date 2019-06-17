#ifndef SICT_KVPAIR_H
#define SICT_KVPAIR_H
/*
 ============================================================================
 Name        : KVPair.h
 Author      : Adam Stinziani
 Email       : astinziani@myseneca.ca
 Student #   : 124 521 188
 Course Code : OOP345
 Section     : SCC
 Date        : 2019-06-12
 Workshop    : Workshop 5 - Lab
 ============================================================================
 */

 /*
  ============================================================================
  Description : KVPair class template definition
  ============================================================================
 */
#include <iostream>
#include <iomanip>

// Include externally linked variable from w5.cpp
extern int fieldWidth;

namespace sict {

	// Class template header
	template<typename K, typename V>

	// Class template body
	class KVPair {
		K currentKey;
		V currentValue;
		bool isEmpty;
	public:

		// Default constructor to set safe-empty state
		KVPair() { isEmpty = true; }

		// 2 argument constructor to initialize class instance variables
		KVPair(const K& k, const V& v) : currentKey(k), currentValue(v) { isEmpty = false; }

		// Function template to display contents of current object 
		template<typename F>void display(std::ostream& os, F f) const {
			if(!isEmpty)
				os << std::left << std::setw(fieldWidth) << currentKey << " " << ":" << " " << std::right << std::setw(fieldWidth) << currentValue << std::setw(fieldWidth) << f(currentValue);
		}
	};
}

#endif // !SICT_KVPAIR_H