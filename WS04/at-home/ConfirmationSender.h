#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H

#include "Reservation.h"

namespace sdds {
	class ConfirmationSender {

		const Reservation** m_res = nullptr;
		size_t m_size = 0;

	public:

		ConfirmationSender();
		~ConfirmationSender();
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		ConfirmationSender(const ConfirmationSender& res);
		ConfirmationSender(ConfirmationSender&& res);
		ConfirmationSender& operator = (const ConfirmationSender& res);
		ConfirmationSender& operator = (ConfirmationSender&&);

		friend std::ostream& operator << (std::ostream& os, const ConfirmationSender& confirm);

	};
}

#endif // !SDDS_CONFIRMATIONSENDER_H