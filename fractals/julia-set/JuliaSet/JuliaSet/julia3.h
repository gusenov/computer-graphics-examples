#pragma once

#include "myBitmap.h"

typedef struct{
	double x, y;
}cmplx;

class julia3
{
public:
	julia3();
	~julia3();

	void juliaSet(int width, int height, cmplx c, double radius, int n);

private:
	
	cmplx add(cmplx a, cmplx b);
	cmplx sqr(cmplx a);
	double mod(cmplx a);
	cmplx mapPoint(int width, int height, double radius, int x, int y);

	myBitmap bmp;
};

