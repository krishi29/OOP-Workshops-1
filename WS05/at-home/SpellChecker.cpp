#include<iostream>
#include<algorithm>
#include<string>
#include<fstream>

#include "SpellChecker.h"
namespace sdds
{
	SpellChecker::SpellChecker(const char* filename)
	{
		auto index = 0u;
		std::string file;
		std::ifstream textfile(filename);

		if (!textfile)
			throw "Bad file name!";
		else {
			for (size_t i = 0; i < SIZE; i++)

			{
				std::getline(textfile, file);
				index = file.find(' ');

				s_badWords[i] = file.substr(0, index);
				s_badWords[i].erase(remove(s_badWords[i].begin(), s_badWords[i].end(), ' '), s_badWords[i].end());

				s_goodWords[i] = file.substr(index, file.length() - 1);
				s_goodWords[i].erase(remove(s_goodWords[i].begin(), s_goodWords[i].end(), ' '), s_goodWords[i].end());
			}
		}
	}
	void SpellChecker::operator()(std::string& text) const
	{
		auto indexStart = 0u;
		for (size_t i = 0; i < SIZE; i++)
		{
			while (text.find(s_badWords[i]) != std::string::npos)
			{
				indexStart = text.find(s_badWords[i]);
				text.replace(indexStart, s_badWords[i].length(), s_goodWords[i]);
			}
		}
	}

}