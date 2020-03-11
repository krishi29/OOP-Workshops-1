#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

#include <iostream>
#include <string>

namespace sdds
{
	class Reservation
	{
		std::string m_resID{};
		std::string m_nameofRes{};
		std::string m_email{};
		int m_numofppl{};
		int m_day{};
		int m_hour{};

	public:
		Reservation() { };
		Reservation(const std::string& res);
		friend std::ostream& operator<<(std::ostream& os, const Reservation& res);
	};
}

#endif // !SDDS_RESERVATION_H