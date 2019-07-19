#ifndef SICT_LIST_H
#define SICT_LIST_H
// Workshop 8 - Smart Pointers
// List.h
// Chris Szalwinski from Cornel Barna
// 2019/03/17

// Completed by: Adam Stinziani
// 2019-07-18

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace sict {
    template <typename T>
    class List {
		std::vector<T> list;
	public:
		
		// default constructor
		//
		List() { }
		
		// custom constructor
		//
		List(const char* fn) {
			std::ifstream file(fn);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(fn) + std::string(" ***");
            while (file) {
                T e;
                if (e.load(file))
                    list.push_back(*new T(e));
            }
		}
		
		// get size of list
		//
		size_t size() const { return list.size(); }
		
		// subscript operator for list class
		//
		const T& operator[](size_t i) const { return list[i]; }
		
		// += operator to add to list
		//
		void operator+=(T* ls) {
			list.push_back(*ls);
		}
		
		// display list object to any os
		// 
		void display(std::ostream& os) const {
            os << std::fixed << std::setprecision(2);
            for (auto& e : list)
                e.display(os);
        }
	};

	// display list object to any os
	//
    template<typename T>
    std::ostream& operator<<(std::ostream& os, const List<T>& l) {
		l.display(os);
		return os;
	}
}
#endif