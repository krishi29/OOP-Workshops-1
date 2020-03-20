// Name:Krishna Patel
// Seneca Student ID:162406185
// Seneca email: kdpatel27@myseneca.ca	
// Date of completion:2020/03/11
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor


#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include "Vehicle.h"
#include <iostream>
#include <string>
namespace sdds
{
	class Car : public Vehicle
	{
		std::string car_maker;
		std::string car_condition;
		double car_topSpeed;
	public:
		Car();
		Car(std::istream& is);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
		friend std::ostream& operator<<(std::ostream& os, const Car& obj);
	};
}

#endif
