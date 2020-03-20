#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include <string>
#include <istream>
#include "Vehicle.h"

using namespace std;

namespace sdds {

	enum class Condition : char { New, Used, Broken, Empty };

	class Car : public Vehicle {

		string m_maker;
		Condition m_condition;
		double m_topSpeed;

	public:

		Car();
		Car(istream&);
		string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;

	};


}


#endif
