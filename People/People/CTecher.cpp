#include "CTeacher.h"

CTeacher::CTeacher(std::string const& firstName, std::string const& lastName, std::string const& patronymic, std::string const& address, std::string const& lessonName)
	: CPersonImpl(firstName, lastName, patronymic, address)
	, m_lessonName(lessonName)
{
}

std::string CTeacher::GetLessonName() const
{
	return m_lessonName;
}
