// Name: Krishna Patel
// Seneca Student ID:162406185
// Seneca email:kdpatel27@myseneca.ca
// Date of completion: 2020-01-16
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.



#ifndef NAMESPACE_EVENT_H
#define NAMESPACE_EVENT_H

extern unsigned long g_sysClock;

namespace sdds {
	class Event {
		char* description{ nullptr };
		long int noOfSeconds{ 0 };
	public:
		Event();
		Event(const Event& event);
		void setDescription(const char* arr);
		void display()const;
		~Event();
		Event& operator=(const Event& event);
	};
}


#endif // !NAMESPACE_EVENT_H
