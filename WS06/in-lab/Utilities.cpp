#include "Utilities.h"
#include "Car.h"
#include <sstream>

namespace sdds {
	Vehicle* createInstance(std::istream& in) {
		size_t pos;
		size_t end_pos;
		std::string line;

		Vehicle* temp = nullptr;

		getline(in, line);

		if (!line.empty()) {

			pos = line.find_first_not_of(' ');
			end_pos = line.find_last_not_of(' ');
			line = line.substr(pos, end_pos - pos + 1);

			if (line.at(0) == 'c' || line.at(0) == 'C') {
				std::stringstream record(line);
				temp = new Car(record);
			}
		}
		return temp;
	}
}