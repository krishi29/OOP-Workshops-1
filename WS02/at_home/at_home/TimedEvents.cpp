

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "TimedEvents.h"

using namespace std;
using namespace std::chrono;

namespace sdds {
    void TimedEvents::startClock() {
        startTime = std::chrono::steady_clock::now();
    }

    void TimedEvents::stopClock() {
        endTime = steady_clock::now();
    }

    void TimedEvents::recordEvent(const char* str) {
        if (recordsNo < MAX_RECORDS)
        {
            events[recordsNo].eventName = str;
            events[recordsNo].timeUnit = "nanoseconds";
            events[recordsNo].duration = duration_cast<nanoseconds>(endTime - startTime);;

            recordsNo++;
        }
    }

    ostream& operator<<(ostream& out, TimedEvents& events) {
        out << "--------------------------\n"
            << "Execution Times:\n"
            << "--------------------------\n";

        for (int i = 0; i < events.recordsNo; i++)
            out << setw(20) << std::left << events.events[i].eventName << ' '
            << setw(12) << right << events.events[i].duration.count() << ' '
            << events.events[i].timeUnit << '\n';

        out << "--------------------------" << endl;

        return out;
    }

}