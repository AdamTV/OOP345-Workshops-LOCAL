// Workshop 8 - Smart Pointers
// Utilities.cpp
// Chris Szalwinski from Cornel Barna
// 2019/03/17

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sict {
	// compares product codes and allocates memory for each successful comparison (raw pointer syntax)
	// 
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		for (size_t i = 0; i < desc.size(); i++) {
			for (size_t k = 0; k < price.size(); k++) {
				if (desc[i].code == price[k].code) {
					Product* p = new Product(desc[i].desc, price[k].price);
					p->validate();
					priceList += p;
					delete p;
				}
			}
		}
		return priceList;
	}

	// compares product codes and allocates memory for each successful comparison (smart pointer syntax)
	// 
	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		for (size_t i = 0; i < desc.size(); i++) {
			for (size_t k = 0; k < price.size(); k++) {
				if (desc[i].code == price[k].code) {
					std::unique_ptr<Product> p (new Product(desc[i].desc, price[k].price));
					p->validate();
					priceList += std::move(p);
				}
			}
		}
		return priceList;
	}
}