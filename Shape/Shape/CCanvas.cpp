#include <iostream>
#include "CCanvas.h"
#include <string>
#include <sstream>
#include <iomanip>
#include <windows.h>

CCanvas::CCanvas()
{
	window.create(sf::VideoMode(400, 500), "SFML Works!");
}


void CCanvas::DrawLine(const CPoint& from, const CPoint& to, uint32_t lineColor)
{
	sf::VertexArray line(sf::Lines, 2);
	line[0].position = sf::Vector2f(static_cast<float>(from.x), static_cast<float>(from.y));
	line[0].color = Color(lineColor);
	line[1].position = sf::Vector2f(static_cast<float>(to.x), static_cast<float>(to.y));
	line[1].color = Color(lineColor);
	window.draw(line);
}

void CCanvas::FillPolygon(const std::vector<CPoint>& points, uint32_t fillColor)
{
	sf::ConvexShape convex;
	convex.setPointCount(points.size()-1);
	for (size_t i = 0; i < points.size() - 1; i++)
	{
		convex.setPoint(i, sf::Vector2f(static_cast<float>(points[i].x), static_cast<float>(points[i].y)));
	}
	convex.setFillColor(Color(fillColor));
	window.draw(convex);
}

void CCanvas::DrawCircle(const CPoint& center, double radius, uint32_t lineColor)
{
	sf::CircleShape circle(static_cast<float>(radius));
	circle.setPosition(static_cast<float>(center.x - radius), static_cast<float>(center.y - radius));
	circle.setOutlineThickness(2.f);
	circle.setOutlineColor(Color(lineColor));
	window.draw(circle);
}

void CCanvas::FillCircle(const CPoint& center, double radius, uint32_t fillColor)
{
	sf::CircleShape circle(static_cast<float>(radius));
	circle.setPosition(static_cast<float>(center.x - radius), static_cast<float>(center.y - radius));
	circle.setFillColor(Color(fillColor));
	window.draw(circle);
}

sf::Color CCanvas::Color(uint32_t color)
{
	return sf::Color((color >> 16) & 0xff, (color >> 8) & 0xff, (color >> 0) & 0xff);
}