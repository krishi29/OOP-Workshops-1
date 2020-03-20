#include <iomanip>
#include "Car.h"

namespace sdds {

	Car::Car() :m_maker{}, m_condition{ Condition::Empty }, m_topSpeed{ 0.0 }{}

	Car::Car(istream& file) {

		size_t pos;
		size_t end_pos;
		string temp;

		getline(file, temp, ',');
		//remove space
		pos = temp.find_first_not_of(' ');
		end_pos = temp.find_last_not_of(' ');
		temp = temp.substr(pos, end_pos - pos + 1);


		getline(file, temp, ',');
		pos = temp.find_first_not_of(' ');
		end_pos = temp.find_last_not_of(' ');
		m_maker = temp.substr(pos, end_pos - pos + 1);

		getline(file, temp, ',');
		if (temp.find_first_not_of(' ') != std::string::npos) {
			pos = temp.find_first_not_of(' ');
			end_pos = temp.find_last_not_of(' ');
			temp = temp.substr(pos, end_pos - pos + 1);
		}

		if (temp.find_first_not_of(' ') == std::string::npos) m_condition = Condition::New;

		else {
			if (temp.at(0) == 'n') m_condition = Condition::New;
			else if (temp.at(0) == 'u') m_condition = Condition::Used;
			else if (temp.at(0) == 'b') m_condition = Condition::Broken;
			else throw string("Invalid record!");
		}

		getline(file, temp, ',');
		pos = temp.find_first_not_of(' ');
		end_pos = temp.find_last_not_of(' ');
		temp = temp.substr(pos, end_pos - pos + 1);

		//check is speed digit number or not
		if (temp.find_first_of("0123456789.") == std::string::npos) throw string("Invalid record!");
		else m_topSpeed = stod(temp);
	}

	string Car::condition() const {

		string temp;

		if (m_condition == Condition::New) {
			temp = "new";
		}
		else if (m_condition == Condition::Used) {
			temp = "used";
		}
		else if (m_condition == Condition::Broken) {
			temp = "broken";
		}
		else temp = "empty";

		return temp;
	}

	double Car::topSpeed() const {
		return m_topSpeed;
	}

	void Car::display(std::ostream& out) const {

		out << "| ";
		out << std::right << std::setw(10) << m_maker;
		out << " | ";
		out << std::left << std::setw(6) << condition();
		out << " | ";
		out << std::setw(6) << std::setprecision(2) << std::fixed << m_topSpeed;
		out << " |";

	}


}