#ifndef SICT_PRODUCT_H
#define SICT_PRODUCT_H
/*
 ============================================================================
 Name        : Product.h
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
  Description : Product inheritance hierarchy concrete class deceleration
  ============================================================================
 */

#include <iomanip>
#include "iProduct.h"

namespace sict {

	class Product : public iProduct {
		int currentNumber;
		double currentPrice;
	public:
		Product(int num, double price);
		double price() const;
		void display(std::ostream& os)const;
	};

	std::ostream& operator<<(std::ostream& os, const iProduct& p);
	iProduct* readRecord(std::ifstream& file);

}

#endif // !SICT_PRODUCT_H
