#pragma once
#define CATCH_CONFIG_MAIN
#include <iostream>
#include <sstream>
//#include "../../catch2/catch.hpp"
#pragma warning(push)
#pragma warning(disable : 4100)
#include "../../FakeIt-master/single_header/catch/fakeit.hpp"
#pragma warning(pop)
#include "../Shape/CRectangle.h"
#include "../Shape/CCircle.h"
#include "../Shape/Controller.h"
#include "../Shape/CLineSegment.h"
#include "../Shape/CTriangle.h"
#include "../Shape/IShape.h"
#include "../Shape/ICanvas.h"
#include "../Shape/CCanvas.h"
#include "../Shape/CPoint.h"

using namespace std;

SCENARIO("create line segment")
{
	CLineSegment line(0x000000, { 0, -1 }, { -2, 2.3 });
	CHECK(line.GetArea() == 0);
	CHECK(line.GetPerimeter() - 3.8587562763 < 0.00001);
	CHECK(line.ToString() == "Line\nStart point = {0, -1 }\nEndPoint = {-2, 2.3 }\nOutline color = #000000\n");
	CHECK(line.GetOutlineColor() == 0x000000);
	CHECK(line.GetStartPoint().x == 0);
	CHECK(line.GetStartPoint().y == -1);
	CHECK(line.GetEndPoint().x == -2);
	CHECK(line.GetEndPoint().y == 2.3);
}

SCENARIO("create triangle")
{
	CTriangle triangle(0xcc9900, 0x000000, { 3, 4 }, { 0, 7 }, { -3, -2 });
	CHECK(triangle.GetArea() == 18);
	CHECK((triangle.GetPerimeter() - 22.215) < 0.00001);
	CHECK(triangle.ToString() == "Triangle\nVertex 1 = {3, 4}\nVertex 2 = {0, 7}\nVertex 3 = {-3, -2}\nOutline color = #cc9900\nFill color = #000000\n");
	CHECK(triangle.GetOutlineColor() == 0xcc9900);
	CHECK(triangle.GetFillColor() == 0x000000);
	CHECK(triangle.GetVertex1().x == 3);
	CHECK(triangle.GetVertex1().y == 4);
	CHECK(triangle.GetVertex2().x == 0);
	CHECK(triangle.GetVertex2().y == 7);
	CHECK(triangle.GetVertex3().x == -3);
	CHECK(triangle.GetVertex3().y == -2);
}

SCENARIO("create rectangle")
{
	CRectangle rectangle(0xcc0066, 0xffffff, { -3, 4 }, 4.5, 7);
	CHECK(rectangle.GetArea() == 31.5);
	CHECK((rectangle.GetPerimeter() - 5.75) < 0.00001);
	CHECK(rectangle.ToString() == "Rectangle\nLeft top = {-3, 4}\nWidth = 4.5\nHeight = 7\nOutline color = #cc0066\nFill color = #ffffff\n");
	CHECK(rectangle.GetOutlineColor() == 0xcc0066);
	CHECK(rectangle.GetFillColor() == 0xffffff);
	CHECK(rectangle.GetLeftTop().x == -3);
	CHECK(rectangle.GetLeftTop().y == 4);
	CHECK(rectangle.GetWidth() == 4.5);
	CHECK(rectangle.GetHeight() == 7);
}

SCENARIO("create circle")
{
	CCircle circle(0xffffff, 0x993366, { 5, -3 }, 2);
	CHECK((circle.GetArea() - 12.566371) < 0.00001);
	CHECK((circle.GetPerimeter() - 12.566371) < 0.00001);
	CHECK(circle.ToString() == "Circle\nCenter = {5, -3}\nRadius = 2\nOutline color = #ffffff\nFill color = #993366\n");
	CHECK(circle.GetOutlineColor() == 0xffffff);
	CHECK(circle.GetFillColor() == 0x993366);
	CHECK(circle.GetCenter().x == 5);
	CHECK(circle.GetCenter().y == -3);
	CHECK(circle.GetRadius() == 2);
}

SCENARIO("add shapes")
{
	std::string str = "line 5.3 -2 4.8 -7.1 ffffff";
	CController controller;
	controller.AddShape(str);
	str = "triangle -3 -2.6 4.8 7 0 -5.3 000000 808080";
	controller.AddShape(str);
	str = "rectangle -3 6 4.889 -10 000000 ffffff";
	controller.AddShape(str);
	str = "circle 89 -3 14 000000 ffffff";
	controller.AddShape(str);
	std::vector<std::shared_ptr<IShape>> shape = controller.GetShapes();
	CHECK(shape[0]->ToString() == "Line\nStart point = {5.3, -2 }\nEndPoint = {4.8, -7.1 }\nOutline color = #ffffff\n");
	CHECK(shape[1]->ToString() == "Triangle\nVertex 1 = {-3, -2.6}\nVertex 2 = {4.8, 7}\nVertex 3 = {0, -5.3}\nOutline color = #000000\nFill color = #808080\n");
	CHECK(shape[2]->ToString() == "Rectangle\nLeft top = {-3, 6}\nWidth = 4.889\nHeight = 10\nOutline color = #000000\nFill color = #ffffff\n");
	CHECK(shape[3]->ToString() == "Circle\nCenter = {89, -3}\nRadius = 14\nOutline color = #000000\nFill color = #ffffff\n");
	CHECK(controller.GetInfoMaxArea() == "Circle\nCenter = {89, -3}\nRadius = 14\nOutline color = #000000\nFill color = #ffffff\nMax area = 615.752\n");
	CHECK(controller.GetInfoMinPerimeter() == "Line\nStart point = {5.3, -2 }\nEndPoint = {4.8, -7.1 }\nOutline color = #ffffff\nMin perimeter = 5.12445\n");
}

SCENARIO("incorrect arguments")
{
	std::vector<IShape*> shape;
	CController controller;
	WHEN("incorrect figure name (rectagle) entered")
	{
		std::string str = "rectagle -3 6 4.889 -10 000000 ffffff";
		THEN("throw invalid argument")
		{
			CHECK_THROWS_AS(controller.AddShape(str), std::invalid_argument);
		}
	}
	WHEN("number entered incorrectly")
	{
		std::string str = "line -3 6j 4.889 -10 000000";
		THEN("throw invalid argument")
		{
			CHECK_THROWS_AS(controller.AddShape(str), std::invalid_argument);
		}
	}
	WHEN("more argunents than needed")
	{
		std::string str = "triangle -3 6 4.889 10  9 8 9 000000 ffffff";
		THEN("throw invalid argument")
		{
			CHECK_THROWS_AS(controller.AddShape(str), std::invalid_argument);
		}
	}
	WHEN("fewer argunents than needed")
	{
		std::string str = "circle -3 6 000000 ffffff";
		THEN("throw invalid argument")
		{
			CHECK_THROWS_AS(controller.AddShape(str), std::invalid_argument);
		}
	}
	WHEN("color entered incorrectly")
	{
		std::string str = "circle -3 6 7 kkkkkk ffffff";
		THEN("throw invalid argument")
		{
			CHECK_THROWS_AS(controller.AddShape(str), std::invalid_argument);
		}
	}
}

SCENARIO("draw line")
{
	fakeit::Mock<ICanvas> canvas;
	const CPoint a{ 10.5, 40.6 };
	const CPoint b{ 30.6, 78 };
	const uint32_t color = 0xffffff;
	CLineSegment line(color, a, b);
	CHECK(line.GetOutlineColor() == 0xffffff);
	fakeit::Fake(Method(canvas, DrawLine));
	ICanvas& i = canvas.get();
	line.Draw(i);
	fakeit::Verify(Method(canvas, DrawLine)).Once();
}

SCENARIO("draw circle")
{
	fakeit::Mock<ICanvas> canvas;
	CCircle circle(0xffffff, 0x000000, { 10, 40 }, 50);
	fakeit::Fake(Method(canvas, DrawCircle));
	fakeit::Fake(Method(canvas, FillCircle));
	ICanvas& i = canvas.get();
	circle.Draw(i);
	fakeit::Verify(Method(canvas, DrawCircle) + Method(canvas, FillCircle)).Once();
}

SCENARIO("draw rectangle")
{
	fakeit::Mock<ICanvas> canvas;
	CRectangle rectangle(0xffffff, 0x000000, { 10, 40 }, 50, 60.5);
	fakeit::Fake(Method(canvas, DrawLine));
	fakeit::Fake(Method(canvas, FillPolygon));
	ICanvas& i = canvas.get();
	rectangle.Draw(i);
	fakeit::Verify(Method(canvas, FillPolygon) + Method(canvas, DrawLine) + Method(canvas, DrawLine) + Method(canvas, DrawLine) + Method(canvas, DrawLine)).Once();
}

SCENARIO("draw triangle")
{
	fakeit::Mock<ICanvas> canvas;
	CTriangle triangle(0xffffff, 0x000000, { 10, 40 }, { 50, 60.5 }, {89, 50});
	fakeit::Fake(Method(canvas, DrawLine));
	fakeit::Fake(Method(canvas, FillPolygon));
	ICanvas& i = canvas.get();
	triangle.Draw(i);
	fakeit::Verify(Method(canvas, FillPolygon) + Method(canvas, DrawLine) + Method(canvas, DrawLine) + Method(canvas, DrawLine)).Once();
}