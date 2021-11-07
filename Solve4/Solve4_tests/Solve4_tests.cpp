#pragma once
#define CATCH_CONFIG_MAIN
#include <iostream>
#include <sstream>
#include <map>
#include "../../catch2/catch.hpp"
#include "../Solve4/Solve4.h"
#include "float.h"

using namespace std;

SCENARIO("coefficients: 0 0 0 0 0")
{
	CHECK_THROWS_AS(Solve4(0, 0, 0, 0, 0), std::invalid_argument);
}

SCENARIO("coefficients: 1 0 0 0 0")
{
	EquationRoot4 EquationRoot = Solve4(1, 0, 0, 0, 0);
	CHECK(EquationRoot.roots[0] - 0 < 0.00001);
	CHECK(EquationRoot.roots[0] - 0 < 0.00001);
	CHECK(EquationRoot.numRoots == 2);
}

SCENARIO("coefficients: 1 0 -1 0 0")
{
	EquationRoot4 EquationRoot = Solve4(1, 0, -1, 0, 0);
	CHECK(EquationRoot.roots[0] - 0 < 0.00001);
	CHECK(EquationRoot.roots[1] - 1 < 0.00001);
	CHECK(EquationRoot.roots[2] - (-1) < 0.00001);
	CHECK(EquationRoot.numRoots == 3);
}

SCENARIO("coefficients: 0 1 2 3 4")
{
	CHECK_THROWS_AS(Solve4(0, 1, 2, 3, 4), std::invalid_argument);
}

SCENARIO("coefficients: 1 2 3 4 5")
{
	CHECK_THROWS_AS(Solve4(1, 2, 3, 4, 5), std::domain_error);
}

SCENARIO("coefficients: 1 4 -10.5 -45.25 -57")
{
	EquationRoot4 EquationRoot = Solve4(1, 4, -10.5, -45.25, -57);
	CHECK(EquationRoot.roots[0] - 3.6062814044835436 < 0.00001);
	CHECK(EquationRoot.roots[1] - (-4.736243263529858) < 0.00001);
	CHECK(EquationRoot.numRoots == 2);
}

SCENARIO("coefficients: 1 34 -56 98 -10")
{
	EquationRoot4 EquationRoot = Solve4(1, 34, -56, 98, -10);
	CHECK(EquationRoot.roots[0] - 0.10830105837254322 < 0.00001);
	CHECK(EquationRoot.roots[1] - (-35.6482426169362) < 0.00001);
	CHECK(EquationRoot.numRoots == 2);
}

SCENARIO("coefficients: 3 6 -123 -126 1080")
{
	EquationRoot4 EquationRoot = Solve4(3, 6, -123, -126, 1080);
	CHECK(EquationRoot.roots[2] - 5 < 0.00001);
	CHECK(EquationRoot.roots[3] - 3 < 0.00001);
	CHECK(EquationRoot.roots[0] - (-4) < 0.00001);
	CHECK(EquationRoot.roots[1] - (-6) < 0.00001);
	CHECK(EquationRoot.numRoots == 4);
}