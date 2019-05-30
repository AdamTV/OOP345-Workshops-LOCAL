#ifndef SICT_LIST_H
#define SICT_LIST_H
/*
 ============================================================================
 Name        : List.h
 Author      : Adam Stinziani
 Email       : astinziani@myseneca.ca
 Student #   : 124 521 188
 Course Code : OOP345
 Section     : SCC
 Date        : 2019-05-30
 Workshop    : Workshop 3 - Lab
 ============================================================================
 */

 /*
  ============================================================================
  Description : List class template definition
  ============================================================================
 */

namespace sict {
	
	template <typename T, size_t N>
	class List {
		T a [N];
		//Initialize listSize to 0 to start at beggining of array
		size_t listSize = 0;
	public:
		//Returns the current size of the array
		size_t size() const {
			return listSize;
		}
		//subscript operator to make values in array accessible
		const T& operator[](size_t i) const {
			return a[i];
		}
		//overloaded += operator to add an element to the array if there is room
		void operator+=(const T& t) {
			if (listSize < N) {
				a[listSize] = t;
				listSize++;
			}
		}
	};
}
#endif // !SICT_LIST_H

