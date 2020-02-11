


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <fstream>
#include "RecordSet.h"

using namespace std;

namespace sdds {
    RecordSet::RecordSet() :recordNo(0), record(nullptr) {

    }

    RecordSet::RecordSet(const char* str) {
        char buffer[50]{};
        recordNo = 0;
        ifstream in(str);
        if (!in.is_open()) {
            std::cout << "failed to open " << str << '\n';
        }
        else {
            while (!in.fail() && !in.eof()) {
                in.get(buffer[0]);
                if (buffer[0] == ' ') recordNo++;
            }
            record = new string[recordNo + 1]{};
            in.clear();
            in.seekg(0);
            recordNo = 0;
            while (!in.fail() && !in.eof()) {
                in.getline(buffer, 49, ' ');
                record[recordNo] = buffer;
                recordNo++;
            }
        }
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

    std::string  RecordSet::getRecord(int index) const {
        return record != nullptr ? record[index] : "";
    }

    size_t RecordSet::size() const {
        return recordNo;
    }

}