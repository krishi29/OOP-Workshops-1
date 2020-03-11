#include "ConfirmationSender.h"

namespace sdds {

	ConfirmationSender::ConfirmationSender() {
		m_res = nullptr;
		m_size = 0;

	}

	ConfirmationSender::~ConfirmationSender()
	{
		delete[] m_res;
	}

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {

		bool isSame = false;

		for (size_t i = 0; i < m_size; i++) {

			if (m_res[i] == &res) {
				isSame = true;
			}
		}

		if (isSame == false) {
			const sdds::Reservation** temp = nullptr;
			temp = new const Reservation * [m_size + 1];
			for (size_t i = 0; i < m_size; ++i)
				temp[i] = m_res[i];
			temp[m_size] = &res;

			++m_size;
			delete[] m_res;
			m_res = temp;
		}

		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {

		for (size_t i = 0; i < m_size; i++) {
			if (m_res[i] == &res) {
				m_res[i] = nullptr;
			}
		}
		return *this;
	}

	ConfirmationSender::ConfirmationSender(const ConfirmationSender& res) {

		m_res = nullptr;
		*this = res;
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender&& res) {
		*this = std::move(res);
	}

	ConfirmationSender& ConfirmationSender::operator = (const ConfirmationSender& conf) {

		if (this != &conf) {
			delete[] m_res;
			m_size = conf.m_size;
			m_res = new const Reservation * [m_size];
			for (size_t i = 0; i < m_size; i++) {
				m_res[i] = conf.m_res[i];
			}
		}
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator = (ConfirmationSender&& conf) {
		if (this != &conf) {
			delete[] m_res;
			m_res = conf.m_res;
			m_size = conf.m_size;
			conf.m_size = 0;
			conf.m_res = nullptr;
		}
		return *this;
	}

	std::ostream& operator << (std::ostream& os, const ConfirmationSender& confirm) {

		if (confirm.m_res == nullptr) {

			os << "--------------------------" << std::endl;
			os << "Confirmations to Send" << std::endl;
			os << "--------------------------" << std::endl;
			os << "The object is empty!" << std::endl;
			os << "--------------------------" << std::endl;

		}
		else {
			os << "--------------------------\n";
			os << "Confirmations to Send\n";
			os << "--------------------------" << std::endl;
			for (size_t i = 0; i < confirm.m_size; i++) {
				if (confirm.m_res[i] != nullptr) {
					os << *confirm.m_res[i];
				}
			}

			os << "--------------------------\n";

		}
		return  os;
	}



}