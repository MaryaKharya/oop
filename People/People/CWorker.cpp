#include "CWorker.h"

CWorker::CWorker(std::string const& firstName, std::string const& lastName, std::string const& patronymic, std::string const& address, std::string const& specialisation)
	: CPersonImpl(firstName, lastName, patronymic, address)
	, m_specialisation(specialisation)
{
}

std::string CWorker::GetSpecialisation() const
{
	return m_specialisation;
}
