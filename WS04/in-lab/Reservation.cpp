
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <sstream>
#include<algorithm>
#include "Reservation.h"

using namespace std;

namespace sdds
{
	Reservation::Reservation(const string& res)
	{
		size_t pos = 0;
		string str = res;

		while (str.find(" ") != std::string::npos)
		{
			pos = str.find(" ");
			str.erase(pos, 1);
		}


		pos = str.find(":");
		m_resID = str.substr(0, pos);
		str.erase(0, pos + 1);

		pos = str.find(",");
		m_nameofRes = str.substr(0, pos);
		str.erase(0, pos + 1);

		pos = str.find(",");
		m_email = '<' + str.substr(0, pos) + '>';
		str.erase(0, pos + 1);

		pos = str.find(",");
		m_numofpeople = stoi(str);
		str.erase(0, pos + 1);

		pos = str.find(",");
		m_day = stoi(str);
		str.erase(0, pos + 1);

		m_hour = stoi(str);

	}

	ostream& operator<<(ostream& os, const Reservation& res)
	{
		os << "Reservation " << res.m_resID << ":"
			<< setw(11) << right << res.m_nameofRes << "  "
			<< left << setw(20) << res.m_email << right << "    ";
		if (res.m_hour >= 6 && res.m_hour <= 9)
			os << "Breakfast";
		else if (res.m_hour >= 11 && res.m_hour <= 15)
			os << "Lunch";
		else if (res.m_hour >= 17 && res.m_hour <= 21)
			os << "Dinner";
		else os << "Drinks";

		os << " on day " << res.m_day << " @ " << res.m_hour << ":00 for " << res.m_numofpeople << " people." << endl;

		return os;
	}
}
