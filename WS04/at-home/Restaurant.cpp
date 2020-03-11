#include "Restaurant.h"

namespace sdds {

	Restaurant::Restaurant() {
		res = nullptr;
		num = 0;
	}

	Restaurant::Restaurant(Reservation* reservation[], size_t cnt) {
		num = 0;
		if (reservation != nullptr && cnt >= 0) {
			res = new Reservation * [cnt];
			for (size_t i = 0; i < cnt; i++) {
				res[num] = new Reservation(*reservation[i]);
				num++;
			}
		}
		else {
			*this = Restaurant();
		}

	}

	Restaurant::Restaurant(const Restaurant& restaurant) {

		*this = restaurant;
	}

	Restaurant::Restaurant(Restaurant&& restaurant) {

		*this = std::move(restaurant);
	}

	Restaurant& Restaurant::operator = (const Restaurant& restaurant) {

		if (this != &restaurant) {
			for (size_t i = 0; i < num; i++)
				delete res[i];
			delete[] res;

			num = restaurant.num;
			res = new Reservation * [num];

			for (size_t i = 0; i < num; i++) {
				res[i] = new Reservation;
				*(res[i]) = *(restaurant.res[i]);
			}
		}
		return *this;
	}

	Restaurant& Restaurant::operator = (Restaurant&& restaurant) {

		if (this != &restaurant) {
			delete[] res;

			num = restaurant.num;
			res = restaurant.res;
			restaurant.num = 0;
			restaurant.res = nullptr;
		}
		return *this;
	}


	size_t Restaurant::size() const {

		return num;
	}

	std::ostream& operator << (std::ostream& os, const Restaurant& restaurant) {
		if (restaurant.size() == 0) {
			os << "--------------------------\n";
			os << "Fancy Restaurant\n"
				<< "--------------------------\n";
			os << "The object is empty!\n";
			os << "--------------------------\n";

		}
		else {
			os << "--------------------------\n";
			os << "Fancy Restaurant\n";
			os << "--------------------------\n";

			for (size_t i = 0; i < restaurant.num; i++) {
				os << *restaurant.res[i];
			}

			os << "--------------------------" << std::endl;
		}
		return os;
	}

	Restaurant::~Restaurant() {
		for (size_t i = 0; i < num; i++)
			delete res[i];
		delete[] res;
	}



}