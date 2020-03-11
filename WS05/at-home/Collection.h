
// Name:Krishna Patel
// Seneca Student ID:162406185
// Seneca email:kdpatel27@myseneca.ca	
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor



#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include<iostream>
#include<string>
namespace sdds
{
	template<class T>
	class Collection
	{
		std::string c_name{};
		T* c_items;
		size_t c_size;
		void(*functor)(const Collection<T>&, const T&);
	public:
		Collection(std::string name)
		{
			c_name = name;
			functor = nullptr;
			c_items = nullptr;
			c_size = 0;

		}
		Collection(const T&) = delete;
		Collection& operator=(const Collection&) = delete;
		~Collection()
		{
			delete[] c_items;

		}
		const std::string& name() const
		{
			return c_name;
		}
		size_t size() const
		{
			return c_size;
		}
		void setObserver(void (*observer)(const Collection<T>&, const T&))
		{
			functor = observer;
		}
		Collection<T>& operator+=(const T& items)
		{
			bool check = true;

			for (size_t i = 0; i < c_size; i++)
			{
				if (c_items[i].title() == items.title())
				{
					check = false;
				}
			}
			if (check)
			{
				T* temp = new T[c_size + 1];

				for (auto i = 0u; i < c_size; i++)
				{
					temp[i] = c_items[i];
				}

				if (c_items != nullptr)
				{

					delete[] c_items;
					c_items = nullptr;
				}

				temp[c_size] = items;
				c_size++;
				c_items = temp;
				temp = nullptr;
				if (functor != nullptr)
				{
					functor(*this, items);
				}
			}
			return *this;
		}
		T& operator[](size_t idx) const
		{
			if (idx < 0 || idx >= c_size)
			{
				throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(c_size) + "] items.");
			}
			else
				return c_items[idx];

		}
		T* operator[](std::string title) const
		{
			bool check = false;
			size_t index;
			T* temp;
			for (auto i = 0u; i < c_size; i++) {
				if (c_items[i].title() == title) {
					index = i;
					check = true;
				}
			}
			if (check)
			{
				temp = &c_items[index];
			}

			else
			{
				temp = nullptr;
			}
			return temp;
		}
		friend std::ostream& operator<<(std::ostream& os, const Collection<T>& obj)
		{
			for (auto i = 0u; i < obj.c_size; i++)
			{
				os << obj[i];
			}
			return os;
		}
	};
}

#endif

