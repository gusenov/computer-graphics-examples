#pragma once

#include <complex>
#include "myBitmap.h"

const int BMP_SIZE = 600, ITERATIONS = 512;
const long double FCT = 2.85, hFCT = FCT / 2.0;

class julia2
{
public:
	julia2();
	~julia2();

	void draw(std::complex<long double> k);

private:
	int inSet(std::complex<long double> z, std::complex<long double> c);

	myBitmap bmp;
};

