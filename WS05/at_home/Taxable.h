#ifndef SICT_TAXABLE_H
#define SICT_TAXABLE_H
/*
 ============================================================================
 Name        : Taxable.h
 Author      : Adam Stinziani
 Email       : astinziani@myseneca.ca
 Student #   : 124 521 188
 Course Code : OOP345
 Section     : SCC
 Date        : 2019-06-12
 Workshop    : Workshop 5 - Lab
 ============================================================================
 */

 /*
  ============================================================================
  Description : Taxable functor
  ============================================================================
 */

namespace sict {

	// Function object identifier
	class Taxable {
		const float currentRate;
	public:

		// Single argument constructor to initialize tax rate
		Taxable(const float cr) :currentRate(cr) {}

		// Overloaded parenthesis(function) operator required for function object
		float operator()(float price) { return price * (currentRate + 1); }
	};
}

#endif // !SICT_TAXABLE_H