
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>
#include<string>
#include <algorithm>
#include <cmath>
using namespace std;

namespace sdds{
	class Book{
		std::string b_author;
		std::string b_title;
		std::string b_country;
		size_t b_year;
		double b_price;
		std::string b_description;
	public:
		Book();
		~Book();
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();

		Book(const std::string& textbook);

		friend std::ostream& operator<<(std::ostream& os, const Book& book);
	};
}

#endif// !NAMESPACE_BOOK_H