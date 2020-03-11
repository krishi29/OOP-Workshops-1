#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H

#include "Reservation.h"

namespace sdds {
	class Restaurant {

		Reservation** res = nullptr;
		size_t num = 0;


	public:
		Restaurant();
		Restaurant(Reservation* reservation[], size_t cnt);
		Restaurant(const Restaurant& restaurant);
		Restaurant(Restaurant&&);
		Restaurant& operator = (const Restaurant&);
		Restaurant& operator = (Restaurant&&);
		~Restaurant();
		size_t size() const;
		friend std::ostream& operator << (std::ostream& os, const Restaurant& restaurant);

	};

}

#endif // !SDDS_RESTAURANT_H