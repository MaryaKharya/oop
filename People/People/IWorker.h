#pragma once

#include "IPerson.h"

class IWorker : public IPerson
{
public:
	virtual ~IWorker() = default;

	virtual std::string GetSpecialisation() const = 0;
};