#include "RungeKutta.h"

Matrix<double, 2, Dynamic> RungeKutta::DSolve(Vector<double, 2>(*func)(double, Vector<double, 2>), double x0, Vector<double, 2> y0, double dx, int stepsCount)
{
	Matrix<double, 2, Dynamic> res;
	res.resize(2, stepsCount + 1);
	Vector<double, 2> y, k1, k2, k3, k4;
	double x = x0;
	double dx2 = 0.5 * dx;
	y = y0;
	for (int i = 0; i < stepsCount; i++)
	{
		res.col(i) = y;
		k1 = func(x, y);
		x += dx2;
		k2 = func(x, y + k1 * dx2);
		k3 = func(x, y + k2 * dx2);
		x += dx2;
		k4 = func(x, y + dx * k3);
		y += dx / 6 * ( k1 + 2*(k2 + k3) + k4 );
	}
	res.col(stepsCount) = y;
	return res;
}