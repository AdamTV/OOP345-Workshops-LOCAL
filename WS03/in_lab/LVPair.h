#ifndef SICT_LVPAIR_H
#define SICT_LVPAIR_H
/*
 ============================================================================
 Name        : LVPair.h
 Author      : Adam Stinziani
 Email       : astinziani@myseneca.ca
 Student #   : 124 521 188
 Course Code : OOP345
 Section     : SCC
 Date        : 2019-05-30
 Workshop    : Workshop 3 - Lab
 ============================================================================
 */

 /*
  ============================================================================
  Description : LVPair class template definition
  ============================================================================
 */
#include <iostream>

namespace sict {
	//Class template header
	template <typename L, typename V>
	//Class template body
	class LVPair {
		//Class template variables
		L currentLabel;
		V currentValue;
	public:
		//No argument constructor to set safe empty state
		LVPair() : currentLabel{}, currentValue{} {}
		//Constructor to set LVPair values
		LVPair(const L& label, const V& value): currentLabel(label), currentValue(value) {}
		//display Label value pair using any ostream
		void display(std::ostream& os) const { os << currentLabel << " : " << currentValue << std::endl; }
	};
	//Class template header redeclared for helper function
	template<typename L, typename V>
	//Overloaded extraction operator to display label-value pair
	std::ostream& operator<<(std::ostream& os, const LVPair<L, V>& pair) { pair.display(os); return os; }
}
#endif // !SICT_LVPAIR_H

