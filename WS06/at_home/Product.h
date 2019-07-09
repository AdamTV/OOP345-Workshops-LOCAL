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
 Date        : 2019-07-09
 Workshop    : Workshop 6 - Home
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

	// product concrete class
	class Product : public iProduct {
		int currentNumber;
		double currentPrice;
	public:
		Product(int num, double price);
		double price() const;
		void display(std::ostream& os)const;
	};

	// taxable Product concrete class for adding tax
	class TaxableProduct : public Product {
		enum taxType { HST, PST };
		taxType taxStatus;
		double taxRate;
	public:
		TaxableProduct(int n, double p, char t);
		double price() const;
		void display(std::ostream& os) const;
	};

	// helper functions
	std::ostream& operator<<(std::ostream& os, const iProduct& p);
	iProduct* readRecord(std::ifstream& file);

}

#endif // !SICT_PRODUCT_H
