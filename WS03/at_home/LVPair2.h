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
 Date        : 2019-05-31
 Workshop    : Workshop 3 - Home
 ============================================================================
 */

 /*
  ============================================================================
  Description : LVPair class template definition
  ============================================================================
 */
#include <iostream>
#include <iomanip>


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
		LVPair() {}

		//Constructor to set LVPair values
		LVPair(const L& label, const V& value): currentLabel(label), currentValue(value) {}

		//display Label value pair using any ostream
		virtual void display(std::ostream& os) const { os << currentLabel << " : " << currentValue << std::endl; }

		const L& getLabel{ return currentLabel; }
	};
	//Class template header redeclared for helper function
	template<typename L, typename V>
	//Overloaded extraction operator to display label-value pair
	std::ostream& operator<<(std::ostream& os, const LVPair<L, V>& pair) { pair.display(os); return os; }

	//Class template header
	template <typename L, typename V>
	class SummableLVPair : public LVPair<L,V> {
		static V initial;
		static size_t minWidth;
	public:
		SummableLVPair() {}
		SummableLVPair(const L& label, const V& v) : LVPair<L,V>(label, v) { if (label.size() > minWidth) minWidth = label.size(); }
		static const V& getInitialValue() { return initial; }
		V sum(const L& label, const V& sum) const { V theSum = initial + sum; return theSum; }
		void display(std::ostream& os) const { os << std::left << std::setw(minWidth); LVPair<L,V>::display(os); }
	};
}
#endif // !SICT_LVPAIR_H

