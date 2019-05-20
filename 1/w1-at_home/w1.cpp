/*
 ============================================================================
 Name        : w1.cpp
 Author      : Adam Stinziani
 Email       : astinziani@myseneca.ca
 Student #   : 124521188
 Course Code : OOP345
 Section     : SCC
 Date        : 2019-05-15
 Workshop    : Workshop 1 - Home
 ============================================================================
 */

 /*
  ============================================================================
  Description : main function and global variable
  ============================================================================
 */
#include <iostream>
#include "process.h"

extern const int INITIAL = 3;

	using namespace std;

	int main(int argCount, char** args) {

		int control = 0;

		if (argCount > 0) {
			cout << "Command Line : ";
			for (int i = 0; i < argCount; i++) {
				cout << args[i] << ' ';
			}
			cout << endl;
			for (int i = 1; i < argCount; i++) {
				sict::process(args[i]);
			}
		}

		else {
			cout << "***Insufficient number of arguments***";
			control = 1;
		}
		return control;
	}
