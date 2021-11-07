#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "CCircle.h"
#include "CLineSegment.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "Controller.h"
#include "CCanvas.h"
#include <SFML/Graphics.hpp>

void CController::AddShape(std::string& str)
{
	std::stringstream stream(str);
	stream >> str;
	if (str == "line")
	{
		m_shapes.push_back(AddLineSegment(stream));
	}
	else if (str == "triangle")
	{
		m_shapes.push_back(AddTriangle(stream));
	}
	else if (str == "rectangle")
	{
		m_shapes.push_back(AddRectangle(stream));
	}
	else if (str == "circle")
	{
		m_shapes.push_back(AddCircle(stream));
	}
	else
	{
		throw std::invalid_argument("there is no such figure");
	}
}

void CController::DrawAll(const std::vector<std::shared_ptr<IShape>>& shapes)
{
	CCanvas canvas;
	while (canvas.window.isOpen())
	{
		sf::Event event;
		while (canvas.window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				canvas.window.close();
			}
		}
		canvas.window.clear(sf::Color(0xffffffff));
		for (auto shape : shapes)
		{
			shape.get()->Draw(canvas);
		}
		canvas.window.display();
	}
}

std::string CController::GetInfoMaxArea() const
{
	double area = 0;
	std::string info;
	std::stringstream stream;
	for (auto shape : m_shapes)
	{
		if (shape->GetArea() > area)
		{
			area = shape->GetArea();
			info = shape->ToString();
		}
	}
	stream << info << "Max area = " << area << "\n";
	return stream.str();
}

std::string CController::GetInfoMinPerimeter() const
{
	double perimeter = m_shapes[0]->GetPerimeter();
	std::string info;
	std::stringstream stream;
	for (auto shape : m_shapes)
	{
		if (shape->GetPerimeter() <= perimeter)
		{
			perimeter = shape->GetPerimeter();
			info = shape->ToString();
		}
	}
	stream << info << "Min perimeter = " << perimeter << "\n";
	return stream.str();
}

std::shared_ptr<CLineSegment> CController::AddLineSegment(std::stringstream& stream) const
{
	double x1, y1, x2, y2;
	std::string strOutlineColor;
	uint32_t outlineColor;
	stream >> x1 >> y1 >> x2 >> y2 >> strOutlineColor;
	if ((!stream.eof()) || (stream.fail()))
	{
		throw std::invalid_argument("incorrect input");
	}
	try
	{
		outlineColor = stoi(strOutlineColor, nullptr, 16);
	}
	catch (...)
	{
		throw std::invalid_argument("incorrect input");
	}
	CLineSegment line(outlineColor, { x1, y1 }, { x2, y2 });
	return std::make_shared<CLineSegment>(line);
}

std::shared_ptr<CTriangle> CController::AddTriangle(std::stringstream& stream) const
{
	double x1, y1, x2, y2, x3, y3;
	std::string strOutlineColor, strFillColor;
	uint32_t outlineColor, fillColor;
	stream >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> strOutlineColor >> strFillColor;
	if ((!stream.eof()) || (stream.fail()))
	{
		throw std::invalid_argument("incorrect input");
	}
	try
	{
		outlineColor = stoi(strOutlineColor, nullptr, 16);
		fillColor = stoi(strFillColor, nullptr, 16);
	}
	catch (...)
	{
		throw std::invalid_argument("incorrect input");
	}
	CTriangle triangle(outlineColor, fillColor, { x1, y1 }, { x2, y2 }, { x3, y3 });
	return std::make_shared<CTriangle>(triangle);
}

std::shared_ptr<CRectangle> CController::AddRectangle(std::stringstream& stream) const
{
	double x, y, width, height;
	std::string strOutlineColor, strFillColor;
	uint32_t outlineColor, fillColor;
	stream >> x >> y >> width >> height >> strOutlineColor >> strFillColor;
	if ((!stream.eof()) || (stream.fail()))
	{
		throw std::invalid_argument("incorrect input");
	}
	try
	{
		outlineColor = stoi(strOutlineColor, nullptr, 16);
		fillColor = stoi(strFillColor, nullptr, 16);
	}
	catch (...)
	{
		throw std::invalid_argument("incorrect input");
	}
	CRectangle rectangle(outlineColor, fillColor, { x, y }, abs(width), abs(height));
	return std::make_shared<CRectangle>(rectangle);
}

std::shared_ptr<CCircle> CController::AddCircle(std::stringstream& stream) const
{
	double x, y, radius;
	std::string strOutlineColor, strFillColor;
	uint32_t outlineColor, fillColor;
	stream >> x >> y >> radius >> strOutlineColor >> strFillColor;
	if ((!stream.eof()) || (stream.fail()))
	{
		throw std::invalid_argument("incorrect input");
	}
	try
	{
		outlineColor = stoi(strOutlineColor, nullptr, 16);
		fillColor = stoi(strFillColor, nullptr, 16);
	}
	catch (...)
	{
		throw std::invalid_argument("incorrect input");
	}
	CCircle circle(outlineColor, fillColor, { x, y }, abs(radius));
	return std::make_shared<CCircle>(circle);
}

std::vector<std::shared_ptr<IShape>> CController::GetShapes() const
{
	return m_shapes;
}