#include "julia3.h"
#include "colors.h"
#include <cmath>

julia3::julia3()
{
}

julia3::~julia3()
{
}

cmplx julia3::add(cmplx a, cmplx b){
	cmplx c;
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return c;
}

cmplx julia3::sqr(cmplx a){
	cmplx c;
	c.x = a.x*a.x - a.y*a.y;
	c.y = 2 * a.x*a.y;
	return c;
}

double julia3::mod(cmplx a){
	return sqrt(a.x*a.x + a.y*a.y);
}

cmplx julia3::mapPoint(int width, int height, double radius, int x, int y){
	cmplx c;
	int l = (width<height) ? width : height;

	c.x = 2 * radius*(x - width / 2.0) / l;
	c.y = 2 * radius*(y - height / 2.0) / l;

	return c;
}

void julia3::juliaSet(int width, int height, cmplx c, double radius, int n){
	int x, y, i;
	cmplx z0, z1;

	bmp.create(width, height);
	DWORD* bits = bmp.bits();

	for (x = 0; x < width; x++)  // x <= width
	for (y = 0; y < height; y++){  // y <= height
		z0 = this->mapPoint(width, height, radius, x, y);
		for (i = 1; i <= n; i++){
			z1 = this->add(this->sqr(z0), c);
			if (this->mod(z1)>radius){
				bits[y * width + x] = COLORS[i % COLORS_COUNT];  // putpixel(x, y, i % 15 + 1);
				break;
			}
			z0 = z1;
		}
		if (i>n)
			bits[y * width + x] = 0xFF000000;  // putpixel(x, y, 0);
	}

	bmp.saveBitmap("julia3.bmp");
}
