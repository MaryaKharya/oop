#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../Shape/IShape.h"
#include "Controller.h"
#include "CCanvas.h"
#include <SFML/Graphics.hpp>


using namespace sf;

int main(int argc, char *argv[])
{
	std::ifstream input;
	input.open("Shapes.txt");
	std::string str;
	CController contr;
	while (std::getline(input, str))
	{
		try
		{
			contr.AddShape(str);
		}
		catch (std::invalid_argument& e)
		{
			std::cout << e.what() << "\n";
		}
	}
	std::cout << contr.GetInfoMaxArea() << "\n";
	std::cout << contr.GetInfoMinPerimeter() << "\n";
	std::vector<std::shared_ptr<IShape>> shapes = contr.GetShapes();
	contr.DrawAll(shapes);
}