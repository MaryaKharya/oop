#pragma once
#include "CPoint.h"
#include "ICanvas.h"
#include <string>
#include <vector>
#include <Windows.h>
#include <algorithm>
#undef min
#undef max
#include <SFML/Graphics.hpp>

class CCanvas: public ICanvas
{
public:
	CCanvas();
	void DrawLine(const CPoint& from, const CPoint& to, uint32_t lineColor) override;
	void FillPolygon(const std::vector<CPoint>& points, uint32_t fillColor) override;
	void DrawCircle(const CPoint& center, double radius, uint32_t lineColor) override;
	void FillCircle(const CPoint& center, double radius, uint32_t fillColor) override;
	sf::RenderWindow window;
private:
	sf::Color Color(uint32_t color);
};
