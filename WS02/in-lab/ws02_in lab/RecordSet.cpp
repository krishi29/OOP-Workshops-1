
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <fstream>
#include "RecordSet.h"

using namespace std;

namespace sdds {
    RecordSet::RecordSet() 
    {
        recordNo = 0;
        record = nullptr; 

    }

    RecordSet::RecordSet(const char* file_name)
    {
        string str;
        string str1;
        ifstream f_obj;
        size_t i = 0;
        recordNo = 0;

        f_obj.open(file_name);
        if (f_obj.is_open())
        {
            while (getline(f_obj, str, ' '))
            {
                recordNo++;
            }
        }

        f_obj.close();
        record = new string[recordNo];
        f_obj.open(file_name);
        while (getline(f_obj, str1, ' '))
        {
            record[i] = str1;
            i++;
        }
        f_obj.close();
    }

  
    RecordSet& RecordSet::operator=(const RecordSet& recordSet) {
        if (this != &recordSet) {
            if (recordSet.record != nullptr) {
                recordNo = recordSet.recordNo;
                record = new string[recordNo]{};
                for (size_t i = 0; i < recordNo; i++)
                    record[i] = recordSet.record[i];
            }
            else {
                record = nullptr;
                recordNo = 0;
            }
        }
        return *this;
    }
    RecordSet::RecordSet(const RecordSet& recordSet) {
        if (recordSet.record != nullptr) {
            recordNo = recordSet.recordNo;
            record = new string[recordNo]{};
            for (size_t i = 0; i < recordNo; i++)
                record[i] = recordSet.record[i];
        }
        else {
            record = nullptr;
            recordNo = 0;
        }

    }

    RecordSet::RecordSet(RecordSet&& recordSet) {
        *this = std::move(recordSet);
    }

    RecordSet& RecordSet::operator=(RecordSet&& recordSet) {
        if (this != &recordSet) {
            delete[] record;
            record = recordSet.record;
            recordNo = recordSet.recordNo;
            recordSet.record = nullptr;
            recordSet.recordNo = 0;
        }
        return *this;
    }

    RecordSet::~RecordSet() {
        delete[] record;
    }

    string RecordSet::getRecord(size_t i)
    {
        string temp{};
        if (i >= 0 && i < recordNo) {
            temp = record[i];

        }
        else {
            temp = "";

        }
        return temp;
    }

    size_t RecordSet::size() const
    {
        return recordNo;
    }

}