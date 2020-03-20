#include <iostream>
#include <string>
#include <iomanip>
#include "Car.h"

namespace sdds
{
	Car::Car() : car_maker{}, car_condition{}, car_topSpeed{ 0.0 }  //intializing
	{

	}

	Car::Car(std::istream& is)
	{
		size_t indexStart = 0;
		std::string temp = "";
		std::getline(is, temp);

		while (temp.find(" ") != std::string::npos)  // done with the help of my friend
		{
			indexStart = temp.find(" ");
			temp.erase(indexStart, 1);
		}

		indexStart = temp.find(",");
		temp.erase(0, indexStart + 1);

		indexStart = temp.find(",");
		car_maker = temp.substr(0, indexStart);
		temp.erase(0, indexStart + 1);

		indexStart = temp.find(",");
		car_condition = temp.substr(0, indexStart);
		temp.erase(0, indexStart + 1);


		car_topSpeed = stoi(temp);
	}

	std::string Car::condition() const
	{
		std::string condition;

		if (car_condition == "n")
		{
			condition = "new";
		}

		else if (car_condition == "b")
		{
			condition = "broken";
		}

		else if (car_condition == "u")
		{
			condition = "used";
		}

		else {
			condition = "Invalid result";
		}

		return condition;
	}

	double Car::topSpeed() const
	{
		return car_topSpeed;
	}

	void Car::display(std::ostream& out) const
	{
		out << "| " << std::right << std::setw(10) << car_maker << " | " << std::left << std::setw(6)
			<< condition() << " | " << std::setw(6) << std::fixed << std::setprecision(2)
			<< topSpeed() << " |";
	}

	std::ostream& operator<<(std::ostream& os, const Car& obj)
	{
		obj.display(os);
		return os;
	}
}