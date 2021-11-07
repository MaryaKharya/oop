#pragma once

#include "IPerson.h"
class IPupil : public IPerson
{
public:
	virtual ~IPupil() = default;
	virtual std::string GetClass() const = 0;
	virtual std::string GetSchoolName() const = 0;
};
