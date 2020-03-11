//-------------------------------------------------------------------------------------------------------------
// Name: Krishna Patel
// Seneca Student ID:   162406185
// Seneca email:    kdpatel27@myseneca.ca
//
// I confirm that the content of this file is created by me, with the exception of the parts provided to me by my professor.
//-------------------------------------------------------------------------------------------------------------


#include <iostream>
#include <string>
#include "Set.h"

using namespace std;

#ifndef _SDDS_SETSUMMABLE_HEADER_
#define _SDDS_SETSUMMABLE_HEADER_


namespace sdds {
    template<class T, size_t N, class K, class V>
    class SetSummable :public Set<T, N> {

    public:
        SetSummable() :Set<T, N>() {

        }

        V accumulate(const K& key) const {
            V temp = Set<T, N>::operator[](0).getInitialValue();
            for (size_t i = 0; i < this->size(); i++) {
                temp = (this->operator[](i)).sum(key, temp);
            }

            return temp;
        }

    };
}
#endif
