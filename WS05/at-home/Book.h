// Name:Krishna Patel
// Seneca Student ID:162406185
// Seneca email:kdpatel27@myseneca.ca	
//
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>
#include<string>
namespace sdds
{
	class Book
	{
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
		template <typename T>
		void fixSpelling(T spellChecker)
		{
			spellChecker(b_description);
		}
	};
}

#endif