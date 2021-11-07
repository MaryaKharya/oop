#include <iostream>
#include "CRectangle.h"
#include <string>
#include <sstream>
#include <iomanip>

CRectangle::CRectangle(uint32_t outlineColor, uint32_t fillColor, const CPoint& leftTop, double width, double height)
	: m_outlineColor(outlineColor)
	, m_fillColor(fillColor)
	, m_leftTop(leftTop)
	, m_width(width)
	, m_height(height)
{
}

double CRectangle::GetArea() const
{
	return m_width * m_height;
}

double CRectangle::GetPerimeter() const
{
	return (m_width + m_height) / 2;
}

std::string CRectangle::ToString() const
{
	std::ostringstream output;
	output << "Rectangle\nLeft top = {" << m_leftTop.x << ", " << m_leftTop.y << "}\n";
	output << "Width = " << m_width << "\n";
	output << "Height = " << m_height << "\n";
	output << "Outline color = #" << std::setfill('0') << std::setw(6) << std::hex << m_outlineColor << "\n";
	output << "Fill color = #" << std::setfill('0') << std::setw(6) << std::hex << m_fillColor << "\n";
	return output.str();
}

uint32_t CRectangle::GetFillColor() const
{
	return m_fillColor;
}

uint32_t CRectangle::GetOutlineColor() const
{
	return m_outlineColor;
}

CPoint CRectangle::GetLeftTop() const
{
	return m_leftTop;
}

double CRectangle::GetWidth() const
{
	return m_width;
}

double CRectangle::GetHeight() const
{
	return m_height;
}

void CRectangle::Draw(ICanvas& canvas)
{
	std::vector<CPoint> points = { m_leftTop, {m_leftTop.x + m_width, m_leftTop.y}, {m_leftTop.x + m_width, m_leftTop.y + m_height}, {m_leftTop.x, m_leftTop.y + m_height}, m_leftTop };
	canvas.FillPolygon(points, m_fillColor);
	canvas.DrawLine(points[0], points[1], m_outlineColor);
	canvas.DrawLine(points[1], points[2], m_outlineColor);
	canvas.DrawLine(points[2], points[3], m_outlineColor);
	canvas.DrawLine(points[3], points[4], m_outlineColor);
}