#include <iostream>
#include "Solve4.h"
#include <Windows.h>
#include <string>
#include <limits>
#include "EquationRoot.h"
#undef max
#undef min

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double a, b, c, d, e;
	std::string str;
	std::cout << "Чтобы решить уравнение введите 5 коэффициентов вашего уравнения четвертой степени в следующем формате: a b c d e \nПредупреждение: коэффициент a не должен быть равен 0\n";
	while (!std::cin.eof())
	{
		std::cout << "Коэффициенты: ";
		try
		{
			std::cin >> a >> b >> c >> d >> e;
			if (std::cin.eof()) break;
			if (!std::cin)
			{
				throw std::invalid_argument("Data entered incorrectly");
			}
			EquationRoot4 roots = Solve4(a, b, c, d, e);
			for (size_t i = 0; i < roots.numRoots; i++)
			{
				std::cout << "x" << i+1 << " = " << roots.roots[i] << "\n";
			}
		}
		catch (std::invalid_argument const& e)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			std::cout << "Error: " << e.what() << "\n";
		}
		catch (std::domain_error const& e)
		{
			std::cout << "Error: " << e.what() << "\n";
		}
		catch (...)
		{
			std::cout << "Unknown error\n";
		}
	}
}