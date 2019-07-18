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
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		int smallSize = desc.size() > price.size() ? price.size() : desc.size();
		int bigSize = desc.size() < price.size() ? price.size() : desc.size();

		for (int i = 0; i < smallSize; i++) {
			for (int k = 0; k < bigSize; k++) {
				if (bigSize == desc.size()) {
					if (desc[k].code == price[i].code) {
						Product prod(desc[k].desc, price[i].price);
						Product* p = &prod;
						try {
							p->validate();
							priceList += p;
						}
						catch (const std::string& msg) {
							throw msg;
						}
					}
				}
				else {
					if (desc[i].code == price[k].code) {
						Product prod(desc[i].desc, price[k].price);
						Product* p = &prod;
						try {
							p->validate();
							priceList += p;
						}
						catch (const char* msg) {
							throw msg;
						}
					}
				}
			}
		}
		return priceList;
	}
}