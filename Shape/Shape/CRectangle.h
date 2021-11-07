#pragma once
#include <string>
#include "ISolidShape.h"
#include "CPoint.h"

class CRectangle : public ISolidShape
{
public:
	CRectangle(uint32_t outlineColor, uint32_t fillColor, const CPoint& leftTop, double width, double height);
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	uint32_t GetOutlineColor() const override;

	uint32_t GetFillColor() const override;

	CPoint GetLeftTop() const;
	double GetWidth() const;
	double GetHeight() const;
	void Draw(ICanvas& canvas);

private:
	CPoint m_leftTop;
	double m_width;
	double m_height;

	uint32_t m_outlineColor;
	uint32_t m_fillColor;
};