// Name: Krishna Patel
// Seneca Student ID:162406185
// Seneca email:kdpatel27@myseneca.ca
// Date of completion: 2020-01-23
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef _SDDS_TimedEvents_HEADER_
#define _SDDS_TimedEvents_HEADER_
#include <iostream>
#include <chrono>
#include "RecordSet.h"

namespace sdds {
    const int MAX_RECORDS = 7;
    class TimedEvents {
        int recordsNo{};
        std::chrono::steady_clock::time_point startTime{};
        std::chrono::steady_clock::time_point endTime{};

        struct {
            std::string eventName{};
            std::string timeUnit{};
            std::chrono::steady_clock::duration duration{};
        }
        events[MAX_RECORDS];


    public:
        void startClock();
        void stopClock();
        void recordEvent(const char*);

        friend std::ostream& operator<<(std::ostream& os, TimedEvents& TimeEvents);
    };

}
#endif
