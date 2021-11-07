#pragma once

class CTVSet
{
public:
	bool GetTurnStatus() const;
	void TurnOn();
	void TurnOff();
	void SelectChannel(int channel);
	void SelectPreviousChannel();
	int GetChannel() const;
private:
	int m_selectedChannel = 1;
	int m_previousChannel = 1;
	int m_isTurnedOn = false;

};

