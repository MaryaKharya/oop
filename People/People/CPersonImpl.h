#pragma once
#include "IPerson.h"

template <typename Base>
class CPersonImpl : public Base
{
public:
	CPersonImpl(std::string const& firstName, std::string const& lastName, std::string const& patronymic, std::string const& address)
		: m_firstName(firstName)
		, m_lastName(lastName)
		, m_patronymic(patronymic)
		, m_address(address)
	{}

	std::string GetFirstName() const override
	{
		return m_firstName;
	}

	std::string GetLastName() const override
	{
		return m_lastName;
	}

	std::string GetPatronymic() const override
	{
		return m_patronymic;
	}

	std::string GetAddress() const override
	{
		return m_address;
	}

private:
	std::string m_firstName;
	std::string m_lastName;
	std::string m_patronymic;
	std::string m_address;
};

