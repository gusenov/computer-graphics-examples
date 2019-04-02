#pragma once

#include "myBitmap.h"

class julia
{
public:
	julia();
	~julia();

	/* процедура формирования фрактала */
	void draw(int xx, int yy, int cx, int cy, double minx, double maxx, double miny, double maxy);

	/* определение цвета точки */
	int c(int index);

	/* функция подсчета количества итераций*/
	int iteration(double x, double y);

private:
	myBitmap bmp;
};

