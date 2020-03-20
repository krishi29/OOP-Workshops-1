#include "Racecar.h"
#include <iomanip>
#include <sstream>
#include "Car.h"

using namespace std;
namespace sdds {

	Racecar::Racecar() :Car() {
		m_booster = 0.0;
	}

	Racecar::Racecar(std::istream& in) : Car(in) {

		string temp;
		getline(in, temp);

		if (!temp.empty()) m_booster = stod(temp);
		else m_booster = 0.0;

	}

	void Racecar::display(std::ostream& out) const {

		string temp;
		stringstream record;

		Car::display(record);
		temp = record.str().substr(0, 23);

		out << temp;
		out << " " << std::setw(6) << std::setprecision(2) << std::fixed << topSpeed();
		out << " |*";

	}

	double Racecar::topSpeed() const {
		return Car::topSpeed() + (Car::topSpeed() * m_booster);
	}


}