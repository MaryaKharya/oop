// MyArray_tests.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define CATCH_CONFIG_MAIN
#include <iostream>
#include <sstream>
#include <string>
#include "../../catch2/catch.hpp"
#include "../MyArray/MyArray.h"
#include "float.h"

using namespace std;

SCENARIO("Create double array")
{
	CMyArray<double> array;
	CHECK(array.GetCapacity() == 0);
	CHECK(array.GetSize() == 0);
	CHECK_THROWS(array[0]);

	array.PushBack(0.678);

	CHECK(array.GetCapacity() == 1);
	CHECK(array.GetSize() == 1);
	CHECK(array[0] == 0.678);
	CHECK_THROWS_AS(array[1], std::out_of_range);

	array.PushBack(0.1);
	array.PushBack(1.23);
	array.PushBack(34.567);
	array.PushBack(789);
	array.PushBack(-1.789);

	CHECK(array.GetSize() == 6);

	array.Resize(8);

	CHECK(array.GetSize() == 8);
	CHECK(array[7] == 0);

	array.Resize(3);

	CHECK(array.GetSize() == 3);
	CHECK(array[2] == 1.23);
	CHECK_THROWS(array[3]);

	array.Clear();

	CHECK(array.GetCapacity() == 0);
	CHECK(array.GetSize() == 0);

}

SCENARIO("Create string array")
{
	CMyArray<string> array;
	CHECK(array.GetCapacity() == 0);
	CHECK(array.GetSize() == 0);
	REQUIRE_THROWS(array[0]);

	array.PushBack("My");
	array.PushBack("name");
	array.PushBack("is");
	array.PushBack("Masha");

	CHECK(array.GetSize() == 4);

	array.Resize(9);

	CHECK(array.GetSize() == 9);
	CHECK(array[8] == "");

	array.Resize(6);

	CHECK(array.GetSize() == 6);
	CHECK(array[5] == "");
	CHECK_THROWS(array[6]);

	array.Clear();

	CHECK(array.GetCapacity() == 0);
	CHECK(array.GetSize() == 0);
}


SCENARIO("Copy consructor and assigment operator")
{
	CMyArray<string> array;

	array.PushBack("My");
	array.PushBack("name");
	array.PushBack("is");
	array.PushBack("Lala");

	CMyArray<string> copyArray(array);

	CHECK(copyArray.GetSize() == 4);
	CHECK(array.GetSize() == 4);

	auto i = 0;
	for (auto it = copyArray.begin(); it != copyArray.end(); it++, i++)
	{
		CHECK(*it == array[i]);
	}

	array.Resize(6);
	CHECK(copyArray.GetSize() == 4);
	copyArray = array;
	CHECK(copyArray.GetSize() == 6);

	i = array.GetSize() - 1;
	for (auto it = copyArray.rbegin(); it != copyArray.rend(); it++, i--)
	{
		CHECK(*it == array[i]);
	}
}


SCENARIO("Move construct and move assigment operator")
{
	CMyArray<double> array;

	array.PushBack(1.2);
	array.PushBack(3.4);
	array.PushBack(5.6);

	CMyArray<double> array2(std::move(array));

	CHECK(array2.GetSize() == 3);
	CHECK(array.GetSize() == 0);

	auto i = 0;
	for (auto it = array2.begin(); it != array2.end(); it++, i++)
	{		
		REQUIRE(*it == array2[i]);
	}

	array.Resize(6);
	CHECK(array.GetSize() == 6);
	CHECK(array2.GetSize() == 3);

	array2 = std::move(array);

	CHECK(array2.GetSize() == 6);
	CHECK(array.GetSize() == 0);

	i = array2.GetSize() - 1;
	for (auto it = array2.rbegin(); it != array2.rend(); it++, i--)
	{
		REQUIRE(*it == array2[i]);
	}
}
