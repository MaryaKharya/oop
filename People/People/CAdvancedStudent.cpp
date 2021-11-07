#include "CAdvancedStudent.h"

CAdvancedStudent::CAdvancedStudent(std::string const& firstName, std::string const& lastName, std::string const& patronymic, std::string const& address, std::string const& studentId, std::string const& universityName, std::string dissertationTopic)
	: CStudentImpl(firstName, lastName, patronymic, address, studentId, universityName)
	, m_dissertationTopic(dissertationTopic)
{
}

std::string CAdvancedStudent::GetDissertationTopic() const
{
	return m_dissertationTopic;
}
