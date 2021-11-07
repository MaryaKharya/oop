#pragma once
#include "IPerson.h"
class ITeacher : public IPerson
{
public:
	virtual ~ITeacher() = default;
	virtual std::string GetLessonName() const = 0;
};