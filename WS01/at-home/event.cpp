

//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "event.h"
#include <cstring>

unsigned long g_sysClock = 0;
using namespace std;

namespace sdds {

	Event::Event() {
		this->description = nullptr;
		noOfSeconds = 0;
	}
	
	Event::Event(const Event& toCopy)
	{
		this->setDescription(toCopy.description);
		this->noOfSeconds = toCopy.noOfSeconds;
	}

	void Event::display()const {
		static int count = 1;
		cout << right << setw(3) << setfill(' ') << count++ << ". ";

		if (this->description == nullptr)
			cout << "[ No Event ]" << endl;
		else {
			cout << setfill('0') << setw(2) << noOfSeconds / (60 * 60) << ":";
			cout << setfill('0') << setw(2) << noOfSeconds / 60 % 60 << ":";
			cout << setfill('0') << setw(2) << noOfSeconds % 60;
			cout << " -> " << this->description << endl;

		}
	}

	

	void Event::setDescription(const char* arrDes) {
		if (arrDes == nullptr)
			* this = Event();
		else {
			this->description = new char[strlen(arrDes)+1];
			strcpy(description, arrDes);
			noOfSeconds = g_sysClock;
		}


	}
	
	Event::~Event()
	{
		if (description != nullptr) {
			delete[] description;
		}
	}

	Event& Event::operator=(const Event& event)
	{
		if (event.description != nullptr) {
			this->setDescription(event.description);
		}
		else {
			this->description = nullptr;
		}
		this->noOfSeconds = event.noOfSeconds;

		return *this;
	}



};
