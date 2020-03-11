#include"Book.h"
#include <iostream>
#include<iomanip>

using namespace std;
namespace sdds
{
	Book::Book()
	{
		b_year = 0;
		b_price = 0;
	}
	Book::~Book()
	{

	}
	const string& Book::title() const
	{
		return b_title;
	}
	const string& Book::country() const
	{
		return b_country;
	}
	const size_t& Book::year() const
	{
		return b_year;
	}
	double& Book::price()
	{
		return b_price;
	}

	Book::Book(const std::string& textbook)
	{
		size_t indexStart = 0;
		string str = textbook;
		/*	while (str.find(" ") != std::string::npos)//Omitted as we dont want to delete all space
			{
				indexStart = str.find(" ");
				str.erase(indexStart, 1);
			}*/

		indexStart = str.find(',');
		b_author = str.substr(0, indexStart);
		auto start = b_author.find_first_not_of(' ');
		auto end = b_author.find_last_not_of(' ');
		b_author = b_author.substr(start, end - start + 1);//delete unwanted space
		str.erase(0, indexStart + 1);


		indexStart = str.find(',');
		b_title = str.substr(0, indexStart);
		start = b_title.find_first_not_of(' ');
		end = b_title.find_last_not_of(' ');
		b_title = b_title.substr(start, end - start + 1);
		str.erase(0, indexStart + 1);

		indexStart = str.find(',');
		b_country = str.substr(0, indexStart);
		start = b_country.find_first_not_of(' ');
		end = b_country.find_last_not_of(' ');
		b_country = b_country.substr(start, end - start + 1);
		str.erase(0, indexStart + 1);

		indexStart = str.find(',');
		b_price = stod(str.substr(0, indexStart));
		str.erase(0, indexStart + 1);

		indexStart = str.find(',');
		b_year = stoi(str.substr(0, indexStart));
		str.erase(0, indexStart + 1);

		b_description = str;
		start = b_description.find_first_not_of(' ');
		end = b_description.find_last_not_of(' ');
		b_description = b_description.substr(start, end - start + 1);



	}

	ostream& operator<<(std::ostream& os, const Book& book) //Friend fucntion
	{

		os << std::setw(20) << std::right << book.b_author << " | "
			<< std::setw(22) << std::right << book.b_title << " | "
			<< std::setw(5) << book.b_country << " | "
			<< std::setw(4) << book.b_year << " | "
			<< std::setw(6) << std::fixed << std::setprecision(2) << book.b_price << " | "
			<< book.b_description << std::endl;
		return os;
	}

}