#ifndef _SICT_LIST_H
#define _SICT_LIST_H
/*
 ============================================================================
 Name        : List.h
 Author      : Adam Stinziani
 Email       : astinziani@myseneca.ca
 Student #   : 124 521 188
 Course Code : OOP345
 Section     : SCC
 Date        : 2019-05-31
 Workshop    : Workshop 3 - Home
 ============================================================================
 */

 /*
  ============================================================================
  Description : List / LVList class template definition
  ============================================================================
 */
namespace sict {

	//Class template header
	template <class T, int N>

	//Class template body
	class List {

		//Class template variables
		T list[N];

		//Initialize listSize to 0 to start at beggining of array
		size_t listSize = {0u};
	public:

		//Returns the current size of the array
		size_t size() const {return listSize;}

		//Subscript operator to make values in array accessible
		const T& operator[](size_t i) const{
			const T& t = list[i];
			return t;
		}

		//Overloaded += operator to add an element to the array if there is room
		void operator+=(const T& t){
			if (listSize < N){
				list[listSize] = t;
				listSize++;
			}
		}
	};

	//Class template header
	template<typename T, typename L, typename V, int N>

	//Class template body
	class LVList : public List<T, N>{
	public:

		//Accumulate all of the values of all of the elements in the current object
		V accumulate(const L& label) const {
			// Initialize the accumulator to the initial value for objects of the label-value pair
			SummableLVPair<L,V> currentSummable;
			V sumOfCurrentLVList = currentSummable.getInitialValue();
			for (size_t i = 0; i < ((List<T, N>&)*this).size(); ++i) {
				// If the labels match, append the values
				if (label == ((List<T, N>&)*this)[i].getLabel())
					sumOfCurrentLVList = ((List<T, N>&)*this)[i].sum(label, sumOfCurrentLVList);
			}
			return sumOfCurrentLVList;
		}
	};
}

#endif // !_SICT_LIST_H