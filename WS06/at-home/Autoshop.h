#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include <vector>
#include <list>
#include "Car.h"


namespace sdds {

	class Autoshop {

		std::vector<Vehicle*> m_vehicles;

	public:

		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
		~Autoshop();

		template <typename T>
		void select(T test, std::list<const Vehicle*>& vehicles) {
			for (auto& car : m_vehicles)
				if (test(car)) vehicles.push_back(car);
		}

	};

}


#endif
