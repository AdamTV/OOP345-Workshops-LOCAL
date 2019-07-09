/*
 ============================================================================
 Name        : Product.cpp
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
  Description : Product inheritance hierarchy concrete class definition
  ============================================================================
 */

#include <algorithm>
#include <string>
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
		os << std::setw(FW) << currentNumber << std::setw(FW) << std::fixed << std::setprecision(2) << currentPrice;
	}

	// constructor to initialize data members
	//
	TaxableProduct::TaxableProduct(int n, double p, char t) : Product(n, p)
	{
		if (t == 'H') {
			taxStatus = HST;
			taxRate = 0.13;
		}
		if (t == 'P') {
			taxStatus = PST;
			taxRate = 0.08;
		}
	}

	// query to get price of current object
	//
	double TaxableProduct::price() const
	{
		return Product::price() * (1 + taxRate);
	}

	// query to display current object to any ostream
	//
	void TaxableProduct::display(std::ostream& os) const
	{
		Product::display(os);
		std::cout << " ";
		if (taxStatus == HST)
			std::cout << "HST";
		if (taxStatus == PST)
			std::cout << "PST";
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
		int num = 1;
		double price = 1;
		char tax = 0;
		std::string s;

		getline(file,s);

		if (s.length() > 0) {

			size_t spaces = std::count(s.begin(), s.end(), ' ');
			size_t sz;
			num = std::stoi(s, &sz);
			s = s.substr(++sz);
			price = std::stod(s, &sz);

			if (spaces == 1) {
				product = new Product(num, price);
			}
			else if (spaces == 2) {
				s = s.substr(++sz);
				tax = s[0];
				product = new TaxableProduct(num, price, tax);
			}
		}

		return product;
	}

}