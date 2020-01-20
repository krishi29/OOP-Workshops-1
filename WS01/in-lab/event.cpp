

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
		description[0] = '\0';
		noOfSeconds = 0;
	}
	void Event::display()const {
		static int count = 1;
		cout << right << setw(3) << setfill(' ') << count++ << ". ";

		if (description[0] == '\0')
			cout << "[ No Event ]" << endl;
		else {
			cout << setfill('0') << setw(2) << noOfSeconds / (60 * 60) << ":";
			cout << setfill('0') << setw(2) << noOfSeconds / 60 % 60 << ":";
			cout << setfill('0') << setw(2) << noOfSeconds % 60;
			cout << " -> " << description << endl;

		}
	}
	void Event::setDescription(const char* arrDes) {
		if (arrDes == nullptr)
			* this = Event();
		else {
			strcpy(description, arrDes);
			noOfSeconds = g_sysClock;
		}


	}


};
