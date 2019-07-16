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
 Workshop      : 7 - Lab
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
#include <math.h>

extern int FW, ND;

namespace sict {

	template <typename T>

	class DataTable {

		std::vector<std::pair<T, T>> xy;
		T median, slope, yIntercept;

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

			// calculate median
			std::vector<T> y;
			for (auto y_n : xy)
				y.push_back(y_n.second);
			std::vector<T> y_temp(y);
			std::sort(y_temp.begin(), y_temp.end());
			median = y_temp[y_temp.size() / 2];

			// calculate slope
			std::vector<T> x;
			for (auto x_n : xy)
				x.push_back(x_n.first);
			T ex = std::accumulate(x.begin(), x.end(), T(0));
			T ey = std::accumulate(y.begin(), y.end(), T(0));
			std::vector<T> product;
			for (size_t i = 0; i < xy.size(); i++)
				product.push_back(x[i] * y[i]);
			T exy = std::accumulate(product.begin(), product.end(), T(0));
			std::vector<T> x2;
			std::for_each(x.begin(), x.end(),
				[&](T x) { x2.push_back(x * x); });
				T ex2 = std::accumulate(x2.begin(),x2.end(), T(0));
				slope = (xy.size() * exy - ex * ey) / (xy.size() * ex2 - ex * ex);

				yIntercept = (ey - slope*ex) / xy.size();

		}

		// query to display data
		//
		void displayData(std::ostream& os) const {
			os << std::setprecision(ND) << std::fixed
				<< "Data Values\n------------\n"
				<< std::setw(FW) << "x" << " " << std::setw(FW) << "y\n";
			for (size_t i = 0; i < xy.size(); i++) {
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
				[&](std::pair<T, T> y_n) {
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
				<< "\nStatistics\n----------\n"
				<< std::setw(FW) << "y mean" << "    = " << std::setw(FW) << mean() << "\n "
				<< std::setw(FW) << "y sigma" << "   = " << std::setw(FW) << sigma() << "\n  "
				<< std::setw(FW) << "y median" << "  = " << std::setw(FW) << median << "\n"
				<< std::setw(FW) << "slope " << "    = " << std::setw(FW) << slope << "\n  "
				<< std::setw(FW) << "intercept" << " = " << std::setw(FW) << yIntercept << std::endl;



		}

	};

}

#endif // !SICT_DATA_TABLE_H
