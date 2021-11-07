#include <iostream>
#include "CLineSegment.h"
#include <string>
#include <sstream>
#include <iomanip>

CLineSegment::CLineSegment(uint32_t outlineColor, const CPoint& startPoint, const CPoint& endPoint)
	: m_outlineColor(outlineColor)
	, m_startPoint(startPoint)
	, m_endPoint(endPoint)
{
}

double CLineSegment::GetArea() const
{
	return 0;
}

double CLineSegment::GetPerimeter() const
{
	return sqrt(pow(m_endPoint.x - m_startPoint.x, 2) + pow(m_endPoint.y - m_startPoint.y, 2));
}

std::string CLineSegment::ToString() const
{
	std::ostringstream output;
	output << "Line\nStart point = {" << m_startPoint.x << ", " << m_startPoint.y << " }\nEndPoint = {" << m_endPoint.x << ", " << m_endPoint.y << " }\n";
	output << "Outline color = #" << std::setfill('0') << std::setw(6) << std::hex << m_outlineColor << "\n";
	return output.str();
}

uint32_t CLineSegment::GetOutlineColor() const
{
	return m_outlineColor;
}

CPoint CLineSegment::GetStartPoint() const
{
	return m_startPoint;
}

CPoint CLineSegment::GetEndPoint() const
{
	return m_endPoint;
}

void CLineSegment::Draw(ICanvas& canvas)
{
	canvas.DrawLine(m_startPoint, m_endPoint, m_outlineColor);
}