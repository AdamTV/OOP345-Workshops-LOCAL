/*
 ============================================================================
 Name        : Sale.cpp
 Author      : Adam Stinziani
 Email       : astinziani@myseneca.ca
 Student #   : 124 521 188
 Course Code : OOP345
 Section     : SCC
 Date        : 2019-06-19
 Workshop    : Workshop 6 - Lab
 ============================================================================
 */

 /*
  ============================================================================
  Description : Sale module for managing a sequence of iProduct objects.
				Definition.
  ============================================================================
 */
#include <fstream>
#include <iomanip>
#include "Sale.h"

namespace sict {

	// constructor to create sequence of iProduct objects
	//
	Sale::Sale(char* name)
	{
		std::ifstream file(name);
		if (file) {
			while (file) {
				products.push_back(readRecord(file));
			}
		}
		else {
			throw "Failed to open file";
		}
	}

	// display created list to any ostream
	//
	void Sale::display(std::ostream& os) const
	{
		os << std::setw(FW) << "\nProduct No" << " " << std::setw(FW) << "Cost\n";
		double totalPrice = 0;
		// range-based for
		for (auto i : products) {
			if (i == nullptr)
				break;
			os << *i;
			totalPrice += i->price();
		}
		os << std::setw(FW) << "Total" << std::setw(FW) << totalPrice;
	}

}
