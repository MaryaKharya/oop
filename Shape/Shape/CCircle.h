#pragma once
#include <string>
#include "ISolidShape.h"
#include "CPoint.h"

class CCircle : public ISolidShape
{
public:
	CCircle(uint32_t outlineColor, uint32_t fillColor, const CPoint& center, double radius);
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	uint32_t GetOutlineColor() const override;

	uint32_t GetFillColor() const override;

	CPoint GetCenter() const;
	double GetRadius() const;
	void Draw(ICanvas& canvas);

private:
	CPoint m_center;
	double m_radius;

	uint32_t m_outlineColor;
	uint32_t m_fillColor;
};