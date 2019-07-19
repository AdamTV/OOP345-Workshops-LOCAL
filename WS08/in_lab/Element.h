#ifndef SICT_ELEMENT_H
#define SICT_ELEMENT_H
// Workshop 8 - Smart Pointers
// Element.h
// Chris Szalwinski from Cornel Barna
// 2019/03/17

// Completed by: Adam Stinziani
// 2019-07-18

#include <iomanip>
#include <string>
#include <fstream>

extern const int FWC;
extern const int FWD;
extern const int FWP;

namespace sict {

	// holds product code and user-friendly description
	//
	struct Description {
		unsigned code;
		std::string desc;
		
		// load into member variables from file
		//
		bool load(std::ifstream& f) {
			f >> code >> desc;
			return f.good();
		}
		
		// display description object to any os
		//
		void display(std::ostream& os) const {
			os << std::setw(FWC) << code
				<< std::setw(FWD) << desc
				<< std::endl;
		}
	};

	// holds product code and current price
	//
	struct Price {
		unsigned code;
		double price;
		
		// load into member variables from file
		//
		bool load(std::ifstream& f) {
			f >> code >> price;
			return f.good();
		}
		
		// display price object to any os
		//
		void display(std::ostream& os) const {
			os << std::setw(FWC) << code << std::setw(FWP)
				<< price << std::endl;
		}
	};

	// holds user-friendly description and product price
	//
	struct Product {
		std::string desc;
		double price;
		int m_id;
		static size_t idGenerator;
		
		// this variable is used to print trace messages from
		//     constructors/destructor
		static bool Trace;
		
		//default constructor
		//
		Product() {
			m_id = ++Product::idGenerator;
			if (Product::Trace)
				std::cout << "    DC [" << m_id << "]" << std::endl;
		}
		
		// custom constructor
		//
		Product(const std::string& str, double p) {
			this->desc = str;
			this->price = p;
			m_id = ++Product::idGenerator;
			if (Product::Trace)
				std::cout << "     C [" << m_id << "]" << std::endl;
		}
		
		// copy constructor
		//
		Product(const Product& other) {
			this->desc = other.desc;
			this->price = other.price;
			m_id = ++Product::idGenerator;
			if (Product::Trace)
				std::cout << "    CC [" << m_id
				<< "] from [" << other.m_id << "]"
				<< std::endl;
		}
		
		// destructor
		//
		~Product() {
			if (Product::Trace)
				std::cout << "    ~D [" << m_id << "]" << std::endl;
		}
		
		// display product object to any os
		//
		void display(std::ostream& os) const {
			os << std::setw(FWD) << desc
				<< std::setw(FWP) << price
				<< std::endl;
		}
		
		// validate price of product object
		//
		void validate() {
			if (price < 0) throw std::string("*** Negative prices are invalid ***");
		}
	};
}
#endif