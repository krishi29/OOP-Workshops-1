// Name: Krishna Patel
// Seneca Student ID:162406185
// Seneca email:kdpatel27@myseneca.ca
// Date of completion: 2020-01-23
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
        std::string* records{ nullptr };
        string* record{0};
        size_t recordNo;
    public:
        RecordSet();
        RecordSet(const RecordSet&);
        RecordSet(const char*);
        RecordSet& operator=(const RecordSet&);
        RecordSet(RecordSet&&);
        ~RecordSet();
        RecordSet& operator=(RecordSet&&);
        std::string getRecord(size_t);
        size_t  size() const;
    };
}
#endif// !NAMESPACE_RECORDSET_H
