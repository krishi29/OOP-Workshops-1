//-------------------------------------------------------------------------------------------------------------
// Name: Krishna Patel
// Seneca Student ID:   162406185
// Seneca email:    kdpatel27@myseneca.ca
//
// I confirm that the content of this file is created by me, with the exception of the parts provided to me by my professor.
//-------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>

using namespace std;

#ifndef _SDDS_PAIR_HEADER_
#define _SDDS_PAIR_HEADER_


namespace sdds {
    template<class K, class V>
    class Pair {
        K m_key{};
        V m_value{};
    public:
        Pair() { }

        Pair(const K& key, const V& value) :m_key(key),
            m_value(value) {

        }

        const K& Key() const {
            return m_key;
        }

        const V& Value() const {
            return m_value;
        }

        virtual void display(ostream& os) const {
            os << m_key << " : " << m_value << endl;
        }
    };

    template<class K, class V>
    ostream& operator<<(ostream& os, const Pair<K, V>& pair)
    {
        pair.display(os);
        return os;
    }
}
#endif
