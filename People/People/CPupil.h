#pragma once
#include "CPersonImpl.h"
#include "IPupil.h"

using namespace std;

class CPupil: public CPersonImpl<IPupil>
{
public:
	CPupil(string const& firstName, string const& lastName, string const& patronymic, string const& address, string const& schoolName, string const& className);

	string GetSchoolName() const override;
	string GetClass() const override;

private:
	string m_schoolName;
	string m_className;
};