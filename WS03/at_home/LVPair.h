#ifndef _SICT_LVPAIR_H
#define _SICT_LVPAIR_H
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
  Description : LVPair / SummableLVPair class template definition
  ============================================================================
 */
#include <iostream>
#include <iomanip>
#include <string>

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
		LVPair(const L& label, const V& value) : currentLabel(label), currentValue(value) {}
		
		//Public query to get value of label
		const L& getLabel() const { return currentLabel; }
		
		//Public query to get value of value
		const V& getValue() const { return currentValue; }
		
		//display Label value pair using any ostream
		virtual void display(std::ostream& os) const { os << currentLabel << " : " << currentValue << std::endl; }
	};
	
	//Class template header redeclared for helper function
	template <typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const LVPair<L, V>& pair) { pair.display(os); return os; }
	
	//Class template header
	template <typename L, typename V>
	
	//Class template body
	class SummableLVPair : public LVPair<L, V> {
		
		//Class template variables
		static V initial;
		static size_t minFieldWidth;
	public:
		
		//No arg constructor
		SummableLVPair() { }
		
		//Constructor to set label, value and width
		SummableLVPair(const L& label, const V& v) : LVPair<L, V>(label, v) {
			if (minFieldWidth < label.size())
				minFieldWidth = label.size() + 1;
		}
		
		//Class function to access class variable
		static const V& getInitialValue() { return initial; }
		
		//Accumulate sum of current object value and given sum of type V
		V sum(const L& label, const V& sum) const { return LVPair<L, V>::getValue() + sum; }
		
		//Display label concatenated with width
		void display(std::ostream& os) const {
			os << std::left << std::setw(minFieldWidth) << LVPair<L, V>::getLabel() << ": " << LVPair<L, V>::getValue() << std::endl;
			os.unsetf(std::ios::left);
		}
	};

	//Templated declaration to initialize minFieldWidth
	template<typename L, typename V>
	size_t SummableLVPair<L, V>::minFieldWidth{ 0u };

	//Templated declaration to initialize initial
	template<> int SummableLVPair<std::string, int>::initial = 0;

	//Template specialization of LVList<std::string, std::string>
	template<> std::string SummableLVPair<std::string, std::string>::initial = "";

	//Template specialization of the sum() query for LVPair<std::string, std::string> types
	template<>
	std::string SummableLVPair<std::string, std::string>::sum(const std::string& label, const std::string& value) const {
		return (value + " " + LVPair<std::string, std::string>::getValue());
	}
}
#endif // !_SICT_LVPAIR_H

