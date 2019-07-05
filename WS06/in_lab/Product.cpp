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

	// constructor to initialize data members
	//
	Product::Product(int num, double price) :currentNumber(num), currentPrice(price) {}

	// query to get price of current object
	//
	double Product::price() const
	{
		 return currentPrice;
	}

	// query to display current object to any ostream
	//
	void Product::display(std::ostream& os) const
	{
		os << std::setw(FW) << currentNumber << std::setw(FW) << std::fixed << std::setprecision(2) << currentPrice << std::endl;
	}

	// extraction operator to use on iProduct object
	//
	std::ostream& operator<<(std::ostream& os, const iProduct& p)
	{
		p.display(os);
		return os;
	}

	// allocate memory for Product instance and return address 
	//
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