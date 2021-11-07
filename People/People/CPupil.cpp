#include "CPupil.h"

CPupil::CPupil(std::string const& firstName, std::string const& lastName, std::string const& patronymic, std::string const& address, std::string const& schoolName, std::string const& className)
	: m_schoolName(schoolName)
	, m_className(className)
	, CPersonImpl(firstName, lastName, patronymic, address)
{
}

std::string CPupil::GetSchoolName() const
{
	return m_schoolName;
}

std::string CPupil::GetClass() const
{
	return m_className;
}
