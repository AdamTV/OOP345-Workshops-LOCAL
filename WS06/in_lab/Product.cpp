/*
 ============================================================================
 Name        : Product.cpp
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
  Description : Product inheritance hierarchy concrete class definition
  ============================================================================
 */

#include"Product.h"

namespace sict {
	Product::Product(int num, double price) :currentNumber(num), currentPrice(price) {}

	double Product::price() const
	{
		 return currentPrice;
	}
	void Product::display(std::ostream& os) const
	{
		os << std::setw(FW) << currentNumber << std::setw(FW) << currentPrice << std::endl;
	}
	std::ostream& operator<<(std::ostream& os, const iProduct& p)
	{
		p.display(os);
		return os;
	}
	iProduct* readRecord(std::ifstream& file)
	{
		iProduct* product = nullptr;
		int num;
		double price;
		if ((std::istream&)file >> num >> price)
			product = new Product(num, price);
		return product;
	}
}