#include "julia.h"
#include <cmath>
#include <iostream>
#include "colors.h"

#define mi 511

using namespace std;

julia::julia()
{
}

julia::~julia()
{
}

/* процедура формирования фрактала */
void julia::draw(int xx, int yy, int cx, int cy, double minx, double maxx, double miny, double maxy)
{
	bmp.create(cx, cy);
	DWORD* bits = bmp.bits();
	int pos;

	double stepx, stepy, x, y;
	int i, j, iter;

	stepx = (maxx - minx) / cx;
	stepy = (maxy - miny) / cy;

	y = miny;

	for (j = 0; j < cy; ++j)  // for j := 0 to cy
	{

		pos = j * cx;

		x = minx;
		for (i = 0; i < cx; ++i)  // for i := 0 to cx
		{
			iter = iteration(x, y);
			
			bits[pos++] = COLORS[iter % COLORS_COUNT];  // putpixel(xx + i, yy + j, c(iter));

			x += stepx;
		}
		y += stepy;
	}  // j

	bmp.saveBitmap("julia.bmp");
}

/* определение цвета точки */
int julia::c(int index)
{
	return 7 * (mi - index);
}

/* функция подсчета количества итераций */
int julia::iteration(double x, double y) 
{
	const double cx = 0.36;
	const double cy = 0.36;
	int i = 0;
	double xx = x, yy = y, xk, yk;

	while (pow(xx, 2.0) + pow(yy, 2.0) <= 4.0)
	{
		xk = pow(xx, 2.0) - pow(yy, 2.0) + cx;
		yk = 2 * xx * yy + cy;
		xx = xk;
		yy = yk;
		++i;
		if (i >= mi) break;
	}
	
	return i;
}
