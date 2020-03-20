// Name:Krishna Patel
// Seneca Student ID:162406185
// Seneca email: kdpatel27@myseneca.ca	
// Date of completion:2020/03/11
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor


#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H

#include "Vehicle.h"

#include <iostream>
#include <vector>

namespace sdds {
	class Autoshop {
		std::vector<Vehicle*> m_vehicles;
	public:
		Autoshop& operator+=(Vehicle* theVehicle);
		~Autoshop();
		void display(std::ostream& out) const;
		friend std::ostream& operator<<(std::ostream& os, const Autoshop& obj);
	};
}

#endif
