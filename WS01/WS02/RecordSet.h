// Name: Krishna Patel
// Seneca Student ID:162406185
// Seneca email:kdpatel27@myseneca.ca
// Date of completion: 2020-01-16
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef _SDDS_RecordSet_HEADER_
#define _SDDS_RecordSet_HEADER_

#include <iostream>
#include <string>
using namespace std;
namespace sdds {
    class RecordSet {
        size_t recordNo{};
        string* record{};
    public:
        RecordSet();
        RecordSet(const char*);
        RecordSet(const RecordSet&);
        RecordSet& operator=(const RecordSet&);
        RecordSet(RecordSet&&);
        RecordSet& operator=(RecordSet&&);
        ~RecordSet();

        string  getRecord(int) const;
        size_t  size() const;
    };
}
#endif