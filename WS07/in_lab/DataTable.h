#ifndef SICT_DATA_TABLE_H
#define SICT_DATA_TABLE_H
/*
 ============================================================================
 Name          : DataTable.h
 Author        : Adam Stinziani
 Email         : astinziani@myseneca.ca
 Student #     : 124 521 188
 Course Code   : OOP345
 Section       : SCC
 Date Created  : 2019-07-11
 Last Modified : 2019-07-11
 Workshop	   : 7 - Lab
 ============================================================================
 */

 /*
  ============================================================================
  Description  : Template class DataTable for processing statistical data
  ============================================================================
 */

#include <iostream>
#include <utility>
#include <iomanip>
#include <vector>
#include <numeric>
#include <algorithm>

extern int FW, ND;

namespace sict {

	template <typename T>

	class DataTable {

		std::vector<std::pair<T,T>> xy;

	public:

		// custom constructor to set values
		//
		DataTable(std::ifstream& fi) {
			T x_n, y_n;

			// copy from file to sequential container
			while (fi) {
				fi >> x_n;
				fi >> y_n;
				if (fi) {
					xy.push_back(std::pair<T, T>(x_n, y_n));
				}
			}
		}

		// query to display data
		//
		void displayData(std::ostream& os) const {
			os << std::setprecision(ND) << std::fixed
				<< "Data Values\n------------\n"
				<< std::setw(FW) << "x" << std::setw(FW) << "y\n";
			for (int i = 0; i < xy.size(); i++) {
				os << std::setw(FW) << xy[i].first
					<< std::setw(FW) << xy[i].second << std::endl;
			}
		}

		// query to calculate mean of data
		//
		T mean() const {
			T yMean = 0;

			// use algorithm library to sort data values
			std::for_each(xy.begin(), xy.end(),

				// use lambda to specify operation on each value in set
				[&](std::pair<T, T> y_n) { yMean += y_n.second; });

			yMean /= xy.size();
			return yMean;
		}

		// query to calculate standard deviation
		//
		T sigma() const {
			T diffMean, ySigma;
			std::vector<T> subMeanSq;

			// use algorithm library to sort data values
			std::for_each(xy.begin(), xy.end(),

				// use lambda to specify operation on each value in set
				[&](std::pair<T,T> y_n) { 
					subMeanSq.push_back((y_n.second - mean()) * (y_n.second - mean()));
				});

			// use numeric library to accumulate data values
			diffMean = std::accumulate(subMeanSq.begin(), subMeanSq.end(), T(0));
			diffMean /= xy.size() - 1;
			ySigma = std::pow(diffMean, 0.5);
			return ySigma;
		}

		// query to display statistical data
		//
		void displayStatistics(std::ostream& os) const {
			os << std::setprecision(ND) << std::fixed
				<< "Statistics\n----------\n"
				<< std::setw(FW) << "y mean" << "    =" << std::setw(FW) << mean() << "\n "
				<< std::setw(FW) << "y sigma" << "   =" << std::setw(FW) << sigma() << std::endl;
		}

	};

}

#endif // !SICT_DATA_TABLE_H