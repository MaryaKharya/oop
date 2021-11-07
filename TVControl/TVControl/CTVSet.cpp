#include "CTVSet.h"

#include <string>

bool CTVSet::GetTurnStatus()const
{
	return m_isTurnedOn;
}

int CTVSet::GetChannel()const
{
	if (!m_isTurnedOn)
	{
		return 0;
	}
	return m_selectedChannel;
}

void CTVSet::TurnOn()
{
	m_isTurnedOn = true;
}

void CTVSet::TurnOff()
{
	m_isTurnedOn = false;
}

void CTVSet::SelectChannel(int channel)
{

	if (((channel >= 1) && (channel <= 99)) && (m_isTurnedOn))
	{
		m_previousChannel = m_selectedChannel;
		m_selectedChannel = channel;
	}
}

void CTVSet::SelectPreviousChannel()
{
	if (m_isTurnedOn)
	{
		std::swap(m_previousChannel, m_selectedChannel);
	}
}
