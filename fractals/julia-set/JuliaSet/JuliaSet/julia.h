#pragma once

#include "myBitmap.h"

class julia
{
public:
	julia();
	~julia();

	/* ��������� ������������ �������� */
	void draw(int xx, int yy, int cx, int cy, double minx, double maxx, double miny, double maxy);

	/* ����������� ����� ����� */
	int c(int index);

	/* ������� �������� ���������� ��������*/
	int iteration(double x, double y);

private:
	myBitmap bmp;
};

