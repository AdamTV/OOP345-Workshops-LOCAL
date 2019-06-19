#ifndef SICT_IPRODUCT_H
#define SICT_IPRODUCT_H
/*
 ============================================================================
 Name        : iProduct.h
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
  Description : iProduct inheritance hierarchy pure interface
  ============================================================================
 */
#include <iostream>

namespace sict {
	extern int FW;
	class iProduct {
	public:
		virtual double price() const = 0;
		virtual void display(std::ostream& os)const = 0;
	};
	std::ostream& operator<<(std::ostream& os, const iProduct& p);
	iProduct* readRecord(std::ifstream& file);
}

#endif // !1

