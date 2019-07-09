#ifndef SICT_SALE_H
#define SICT_SALE_H
/*
 ============================================================================
 Name        : Sale.h
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
  Description : Sale module for managing a sequence of iProduct objects.
				Deceleration.
  ============================================================================
 */
#include <vector>
#include "iProduct.h"

namespace sict {

	class Sale {
	std::vector<iProduct*> products;
	public:
		Sale(char* name);
		void display(std::ostream& os)const;
	};

}

#endif // !SICT_SALE_H
