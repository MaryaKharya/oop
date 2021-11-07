#pragma once
#include "CPersonImpl.h"

template <typename Base>
class CStudentImpl: public CPersonImpl<Base>
{
public:
	CStudentImpl(std::string const& firstName, std::string const& lastName, std::string const& patronymic, std::string const& address, std::string const& studentId, std::string const& universityName)
		: CPersonImpl<Base>(firstName, lastName, patronymic, address)
		, m_universityName(universityName)
		, m_studentId(studentId)
	{
	};
	std::string GetUniversityName() const override
	{
		return m_universityName;
	}
	std::string GetStudentIdNumber() const override
	{
		return m_studentId;
	}

private:
	std::string m_universityName;
	std::string m_studentId;
};

