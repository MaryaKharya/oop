#pragma once
#include <string>
#include <vector>
#include "IShape.h"
#include "CPoint.h"
#include "CCircle.h"
#include "CTriangle.h"
#include "CLineSegment.h"
#include "CRectangle.h"
#include <SFML/Graphics.hpp>

class CController
{
public:
	void AddShape(std::string& str);
	std::string GetInfoMaxArea() const;
	std::string GetInfoMinPerimeter() const;
	std::vector<std::shared_ptr<IShape>> GetShapes() const;
	void DrawAll(const std::vector<std::shared_ptr<IShape>>& shapes);
private:
	std::vector<std::shared_ptr<IShape>> m_shapes;
	std::shared_ptr<CLineSegment> AddLineSegment(std::stringstream& stream) const;
	std::shared_ptr<CTriangle> AddTriangle(std::stringstream& stream) const;
	std::shared_ptr<CRectangle> AddRectangle(std::stringstream& stream) const;
	std::shared_ptr<CCircle> AddCircle(std::stringstream& stream) const;
};