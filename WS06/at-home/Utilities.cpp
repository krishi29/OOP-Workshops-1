#include "Utilities.h"
#include "Racecar.h"
#include "Vehicle.h"
#include <sstream>

using namespace std;

namespace sdds {

	Vehicle* createInstance(std::istream& in) {

		size_t pos;
		size_t end_pos;
		string line;

		Vehicle* temp = nullptr;

		getline(in, line);

		if (!line.empty()) {

			pos = line.find_first_not_of(' ');
			end_pos = line.find_last_not_of(' ');
			line = line.substr(pos, end_pos - pos + 1);

			stringstream record(line);

			//convert char into string
			string firstCharactor;
			firstCharactor += line.at(0);

			if (firstCharactor == "c" || firstCharactor == "C")
			{
				temp = new Car(record);
			}

			else if (firstCharactor == "r" || firstCharactor == "R")
			{
				temp = new Racecar(record);
			}

			else
			{
				throw string("Unrecognized record type: [" + firstCharactor + "]");
			}
		}
		return temp;

	}

}