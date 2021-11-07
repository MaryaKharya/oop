#pragma once
#include "CStudentImpl.h"
#include "IAdvancedStudent.h"

class CAdvancedStudent : public CStudentImpl<IAdvancedStudent>
{
public:
	CAdvancedStudent(std::string const& firstName, std::string const& lastName, std::string const& patronymic, std::string const& address, std::string const& studentId, std::string const& universityName, std::string dissertationSubject);
	std::string GetDissertationTopic() const override;
private:
	std::string m_dissertationTopic;
};