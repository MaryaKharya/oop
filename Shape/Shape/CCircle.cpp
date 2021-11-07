#include <iostream>
#include "CCircle.h"
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>
#define M_PI (3.141592653589793)

CCircle::CCircle(uint32_t outlineColor, uint32_t fillColor, const CPoint& center, double radius)
	: m_outlineColor(outlineColor)
	, m_fillColor(fillColor)
	, m_center(center)
	, m_radius(radius)
{
}

double CCircle::GetArea() const
{
	return M_PI * pow(m_radius, 2);
}

double CCircle::GetPerimeter() const
{
	return 2 * M_PI * m_radius;
}

std::string CCircle::ToString() const
{
	std::ostringstream output;
	output << "Circle\nCenter = {" << m_center.x << ", " << m_center.y << "}\n";
	output << "Radius = " << m_radius << "\n";
	output << "Outline color = #" << std::setfill('0') << std::setw(6) << std::hex << m_outlineColor << "\n";
	output << "Fill color = #" << std::setfill('0') << std::setw(6) << std::hex << m_fillColor << "\n";
	return output.str();
}

uint32_t CCircle::GetFillColor() const
{
	return m_fillColor;
}

uint32_t CCircle::GetOutlineColor() const
{
	return m_outlineColor;
}

CPoint CCircle::GetCenter() const
{
	return m_center;
}

double CCircle::GetRadius() const
{
	return m_radius;
}

void CCircle::Draw(ICanvas& canvas)
{
	canvas.DrawCircle(m_center, m_radius, m_outlineColor);
	canvas.FillCircle(m_center, m_radius, m_fillColor);
}