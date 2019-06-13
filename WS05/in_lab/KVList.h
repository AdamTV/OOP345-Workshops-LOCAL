#ifndef SICT_KVLIST_H
#define SICK_KVLIST_H
/*
 ============================================================================
 Name        : KVList.h
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
  Description : KVList class template definition
  ============================================================================
 */
#include "KVPair.h"

namespace sict {

	// Class template header
	template<typename T>

	// Class template body
	class KVList {
		T* currentList;
		size_t maxSize;
		size_t currentSize;
	public:

		// Default constructor to set safe-empty state
		KVList() { currentList = nullptr; }

		// 1 argument constructor to initialize class instance and class resource instance variables
		KVList(int n) {
			if (n > 0) {
				currentList = new T[n];
				maxSize = n;
				currentSize = 0;
			}
			else {
				currentList = nullptr;
			}
		}

		// Move-constructor
		KVList(KVList&& src) {
			if (this != &src) {
				currentList = src.currentList;
				maxSize = src.maxSize;
				currentSize = src.currentSize;
				src.currentList = nullptr;
				src.maxSize = 0;
				src.currentSize = 0;
			}
		}

		// Destructor to clean up dynamically allocated memory
		~KVList() { delete[] currentList; currentList = nullptr; }

		// Subscript operator for array
		const T& operator[](size_t i) const { return i; }
	
		// Function template to display contents of current object 
		template<typename F>void display(std::ostream& os, F f) const {
			if (currentList != nullptr && currentSize > 0) {
				for (size_t i = 0; i < currentSize; i++) {
					currentList[i].display(os, f);
					os << std::endl;
				}
			}
		}

		// Function to add element to end of array if there is room
		void push_back(const T& t) {
			if (currentSize < maxSize) {
				currentList[currentSize] = t;
				currentSize++;
			}
		}

		// Copy/Move assignment operators and copy constructor disabled
		KVList& operator= (KVList&) = delete;
		KVList& operator=(KVList&&) = delete;
		KVList(KVList&) = delete;
	};
}

#endif // !SICT_KVLIST_H