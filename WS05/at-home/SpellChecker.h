// Name:Krishna Patel
// Seneca Student ID:162406185
// Seneca email:kdpatel27@myseneca.ca	
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor

#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
#include<iostream>
#define SIZE 5

namespace sdds
{
	class SpellChecker
	{
		std::string s_badWords[SIZE];
		std::string s_goodWords[SIZE];
	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text) const;
	};
}
#endif