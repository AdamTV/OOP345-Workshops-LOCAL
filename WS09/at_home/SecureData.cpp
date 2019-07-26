// Workshop 9 - Multi-Threading
// SecureData.cpp
// Chris Szalwinski after Cornel Barna
// 2019/03/19

// Secure Data module to process and encrypt data
// Completed by: Adam Stinziani
// 2019-07-24

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <functional>
#include "SecureData.h"

using namespace std;

namespace sict {

	// coverts data to encrypted version
	//
	void converter(char* t, char key, int n, const Cryptor& c) {
		for (int i = 0; i < n; i++)
			t[i] = c(t[i], key);
	}

	// custom constructor to set data values
	//
	SecureData::SecureData(const char* file, char key, ostream* pOfs) {
		ofs = pOfs;

		// open text file
		fstream input(file, std::ios::in);
		if (!input)
			throw string("\n***Failed to open file ") +
			string(file) + string(" ***\n");

		// copy from file into memory
		input.seekg(0, std::ios::end);
		nbytes = (int)input.tellg() + 1;

		text = new char[nbytes];

		input.seekg(ios::beg);
		int i = 0;
		input >> noskipws;
		while (input.good())
			input >> text[i++];
		text[nbytes - 1] = '\0';
		*ofs << "\n" << nbytes - 1 << " bytes copied from file "
			<< file << " into memory (null byte added)\n";
		encoded = false;

		// encode using key
		code(key);
		*ofs << "Data encrypted in memory\n";
	}

	// destructor to clean up memory
	//
	SecureData::~SecureData() {
		delete[] text;
	}

	// method to display data if valid
	//
	void SecureData::display(std::ostream& os) const {
		if (text && !encoded)
			os << text << std::endl;
		else if (encoded)
			throw std::string("\n***Data is encoded***\n");
		else
			throw std::string("\n***No data stored***\n");
	}

	// method to encode data via encryption
	//
	void SecureData::code(char key) {
		//threads.push_back(std::thread(converter(text, key, nbytes, Cryptor())));
		converter(text, key, nbytes, Cryptor());
		encoded = !encoded;
	}

	// method to backup encrypted data
	//
	void SecureData::backup(const char* file) {
		if (!text)
			throw std::string("\n***No data stored***\n");
		else if (!encoded)
			throw std::string("\n***Data is not encoded***\n");
		else
		{
			// open a binary file for writing
			std::ofstream f(file, std::ios::out | std::ios::binary);

			// write data into the binary file
			//         and close the file
			f.write(text, (long long int)nbytes);
			f.close();
		}
	}

	// method to restore encrypted data
	//
	void SecureData::restore(const char* file, char key) {

		// open binary file for reading
		std::ifstream input(file, std::ios::in | std::ios::binary);

		// allocate memory here for the file content
		text = new char[nbytes];

		// read the content of the binary file
		//         and close the file
		input.read(text, nbytes);
		input.close();

		*ofs << "\n" << nbytes << " bytes copied from binary file "
			<< file << " into memory.\n";

		encoded = true;

		// decode using key
		code(key);

		*ofs << "Data decrypted in memory\n\n";
	}

	// method to display data if valid
	//
	std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
		sd.display(os);
		return os;
	}
}
