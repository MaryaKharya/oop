#pragma once
class CTVSet;

class TVControl
{
public:
	TVControl(std::istream& input, std::ostream& output, CTVSet& tv);
	void ProcessCommand();
private:
	void TurnOn();
	void TurnOff();
	void GetInfo();
	void SelectPreviousChannel();
	void SelectChannel(std::string& command);
	int IntToString(const std::string& command);
	CTVSet & m_tv;
	std::istream& m_input;
	std::ostream& m_output;

};
//std::string ControlTV(const std::string& command, CTVSet& tv);

//std::string TurnOnTv(CTVSet& tv);

//std::string TurnOffTv(CTVSet& tv);

//std::string GetInfoTv(CTVSet& tv);

//std::string SelectPreviousChannelOnTv(CTVSet& tv);

//std::string SelectChannelOnTv(const std::string& command, CTVSet& tv);

//int IntToString(const std::string& str);
