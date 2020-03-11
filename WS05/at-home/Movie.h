// Name:Krishna Patel
// Seneca Student ID:162406185
// Seneca email:kdpatel27@myseneca.ca	
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor


#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <iostream>

namespace sdds
{
	class Movie {
		std::string m_title{};
		size_t m_releaseYear = 0;
		std::string m_description{};
	public:
		Movie();
		const std::string& title() const;
		Movie(const std::string& strMovie);
		friend std::ostream& operator<<(std::ostream& os, const Movie& Movie);
		template<typename T>
		void fixSpelling(T spellChecker)
		{
			spellChecker(m_title);
			spellChecker(m_description);
		}
	};

}
#endif