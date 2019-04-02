#include <iostream>
#include <cstdlib>
#include "julia.h"
#include "julia2.h"
#include "julia3.h"
#include "myBitmap.h"

using namespace std;

void julia_draw(void);
void julia2_draw(void);
void julia3_draw(void);
void testMyBitmap(void);

int main()
{
	//cout << sizeof(int);  // 4
	//cout << 10.0 / 3 << endl;  // 3.33333

	//testMyBitmap();
	julia_draw();
	//julia2_draw();
	//julia3_draw();

	system("PAUSE");
	return EXIT_SUCCESS;
}

void julia_draw(void)
{
	julia j;

	/* формирование фрактала с разной степенью детализации */
	//j.draw(0, 0, 640, 480, -1, 1, -1.2, 1.2);  /* весь фрактал */
	/* увеличенные фрагменты фрактала */
	//j.draw(0, 0, 640, 480, -0.1, 0.1, -0.1, 0.1);
	//j.draw(0, 0, 640, 480, -1, 0, -1.2, 0);
	//j.draw(0, 0, 640, 480, -1, 0.5, -0.5, 0);
	//j.draw(0, 0, 640, 480, -0.75, -0.06, -0.5, -0.35);
	//j.draw(0, 0, 640, 480, -0.68, -0.65, -0.37, -0.36);

	j.draw(0, 0, 1000, 1000, -0.9, 0.9, -1.1, 1.0);
}

void julia2_draw(void)
{
	std::complex<long double> c;
	long double factor = FCT / BMP_SIZE;
	
	//c.imag((factor * 184) + -1.4);
	//c.real((factor * 307) + -2.0);

	c.real(0.36);
	c.imag(0.36);

	julia2 j;
	j.draw(c);

}

void julia3_draw(void)
{
	int width = 640, height = 480;
	cmplx c;
	c.x = 0.36;
	c.y = 0.36;

	julia3 j;
	j.juliaSet(width, height, c, 2, 512);
}

void testMyBitmap(void)
{
	myBitmap bmp;
	int width = 640, height = 480;
	bmp.create(width, height);
	DWORD* bits = bmp.bits();
	int pos;
	
	const int RED = 0xFF0000;
	const int GREEN = 0x00FF00;
	const int BLUE = 0x0000FF;

	// Этот цикл движется по изображению сверху вниз:
	for (int y = 0; y < height; ++y)  // y обозначает номер строки.
	{
		// Этот цикл движется по изображению слева направо:
		for (int x = 0; x < width; ++x)  // x обозначает номер столбца.
		{
			bits[y * width + x] = GREEN;
		}
	}
	bmp.saveBitmap("myBitmap.bmp");
}