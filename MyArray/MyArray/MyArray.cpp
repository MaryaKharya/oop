// MyArray.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "MyArray.h"

int main()
{
	CMyArray<double> arr1;
	arr1.PushBack(5.67);
	arr1.PushBack(6.678978);
	arr1.PushBack(8.7);
	arr1.PushBack(89);
	arr1.Resize(8);
	for (auto i = arr1.begin(); i != arr1.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << "\n";
	for (auto i = arr1.rbegin(); i != arr1.rend(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << "\n";
	CMyArray<std::string> arr2;
	arr1.Resize(4);
	arr2.PushBack("Happy");
	arr2.PushBack("New");
	arr2.PushBack("Year");
	arr2.PushBack("!");
	for (auto i = arr2.begin(); i != arr2.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << "\n";
	for (auto i = arr2.rbegin(); i != arr2.rend(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << "\n";
}