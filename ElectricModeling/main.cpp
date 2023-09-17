#include <iostream>
#include "RungeKutta.h"
#include <Eigen\Core>
#include <fstream>

using namespace Eigen;

Vector<double, 2> LinearA(double, Vector<double, 2> v)
{
	Vector<double, 2> res;
	res(0) = v(1);
	res(1) = -v(0);
	return res;
}

int main()
{
	std::ofstream fout;
	fout.open("file.txt");
	Matrix<double, 2, Dynamic> m;
	Vector<double, 2> y0;
	y0 << 0, -1;
	m = RungeKutta::DSolve(LinearA, 0, y0, 0.0001, 10000*100);
	Matrix<double, 6, 1000001> res;
	for (int i = 0; i < 1000001; i++)
		res.col(i)  <<	m(0, i),
						m(1, i),
						(m(0, i)* m(0, i) + m(1, i)* m(1, i)) / 2,
						m(0, i) + sin(i / 10000.),
						m(1, i) + cos(i / 10000.),
						(m(0, i)* m(0, i) + m(1, i) * m(1, i) - 1) / 2;
	fout << res.transpose();
	fout.close();
	return 0;
}