#include <iostream>
#include "CTriangle.h"
#include <string>
#include <sstream>
#include <iomanip>

CTriangle::CTriangle(uint32_t outlineColor, uint32_t fillColor, const CPoint& vertex1, const CPoint& vertex2, const CPoint& vertex3)
	: m_outlineColor(outlineColor)
	, m_fillColor(fillColor)
	, m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
{
}

double CTriangle::GetArea() const
{
	return abs((m_vertex1.x - m_vertex3.x) * (m_vertex2.y - m_vertex3.y) - (m_vertex2.x - m_vertex3.x) * (m_vertex1.y - m_vertex3.y)) / 2;
}

double CTriangle::GetPerimeter() const
{
	double a = sqrt(pow(m_vertex2.x - m_vertex1.x, 2) + pow(m_vertex2.y - m_vertex1.y, 2));
	double b = sqrt(pow(m_vertex3.x - m_vertex2.x, 2) + pow(m_vertex3.y - m_vertex2.y, 2));
	double c = sqrt(pow(m_vertex1.x - m_vertex3.x, 2) + pow(m_vertex1.y - m_vertex3.y, 2));
	return (a + b + c) / 2;
}

std::string CTriangle::ToString() const
{
	std::ostringstream output;
	output << "Triangle\nVertex 1 = {" << m_vertex1.x << ", " << m_vertex1.y << "}\n";
	output << "Vertex 2 = {" << m_vertex2.x << ", " << m_vertex2.y << "}\n";
	output << "Vertex 3 = {" << m_vertex3.x << ", " << m_vertex3.y << "}\n";
	output << "Outline color = #" << std::setfill('0') << std::setw(6) << std::hex << m_outlineColor << "\n";
	output << "Fill color = #" << std::setfill('0') << std::setw(6) << std::hex << m_fillColor << "\n";
	return output.str();
}

uint32_t CTriangle::GetFillColor() const
{
	return m_fillColor;
}

uint32_t CTriangle::GetOutlineColor() const
{
	return m_outlineColor;
}

CPoint CTriangle::GetVertex1() const
{
	return m_vertex1;
}

CPoint CTriangle::GetVertex2() const
{
	return m_vertex2;
}

CPoint CTriangle::GetVertex3() const
{
	return m_vertex3;
}

void CTriangle::Draw(ICanvas& canvas)
{
	std::vector<CPoint> points = { m_vertex1, m_vertex2, m_vertex3, m_vertex1 };
	canvas.FillPolygon(points, m_fillColor);
	canvas.DrawLine(points[0], points[1], m_outlineColor);
	canvas.DrawLine(points[1], points[2], m_outlineColor);
	canvas.DrawLine(points[2], points[3], m_outlineColor);
}