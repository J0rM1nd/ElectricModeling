#pragma once
#include <Eigen\Core>
using namespace Eigen;

class RungeKutta
{
public:
	static Matrix<double, 2, Dynamic> DSolve(
		Vector<double, 2>(*func)(double, Vector<double, 2>), double x0, Vector<double, 2> y0, double dx, int stepsCount);
};