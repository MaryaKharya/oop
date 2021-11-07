#pragma once
#include "CPersonImpl.h"

class IStudent : public IPerson
{
public:
	virtual ~IStudent() = default;

	virtual std::string GetUniversityName() const = 0;
	virtual std::string GetStudentIdNumber() const = 0;
};