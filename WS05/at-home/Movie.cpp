#include<iostream>
#include<cstring>
#include<iomanip>
#include "Movie.h"
#include<sstream>
namespace sdds

{

	Movie::Movie()
	{
		m_releaseYear = 0;
	}
	const std::string& Movie::title() const {
		return m_title;
	}
	Movie::Movie(const std::string& strMovie)
	{
		size_t indexStart = 0;
		std::string str = strMovie;


		indexStart = str.find(',');
		m_title = str.substr(0, indexStart);
		auto start = m_title.find_first_not_of(' ');
		auto end = m_title.find_last_not_of(' ');
		m_title = m_title.substr(start, end - start + 1);//delete unwanted space
		str.erase(0, indexStart + 1);


		indexStart = str.find(',');
		m_releaseYear = stoi(str.substr(0, indexStart));
		/*	start = m_releaseYear.find_first_not_of(' ');
			end = m_releaseYear.find_last_not_of(' ');
			m_releaseYear = m_releaseYear.substr(start, end - start + 1);*/
		str.erase(0, indexStart + 1);


		m_description = str;
		start = m_description.find_first_not_of(' ');
		end = m_description.find_last_not_of(' ');
		m_description = m_description.substr(start, end - start + 1);
	}

	std::ostream& operator<<(std::ostream& os, const Movie& Movie)
	{
		os << std::setw(40) << std::right << Movie.m_title << " | ";
		os << std::setw(4) << Movie.m_releaseYear << " | ";
		os << Movie.m_description << std::endl;
		return os;
	}
}