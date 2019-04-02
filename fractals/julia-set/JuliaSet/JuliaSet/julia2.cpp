#include "julia2.h"
#include <windows.h>

julia2::julia2()
{
}

julia2::~julia2()
{
}

void julia2::draw(std::complex<long double> k) {
	bmp.create(BMP_SIZE, BMP_SIZE);
	DWORD* bits = bmp.bits();
	int res, pos;
	std::complex<long double> c, factor(FCT / BMP_SIZE, FCT / BMP_SIZE);

	for (int y = 0; y < BMP_SIZE; y++) {
		pos = y * BMP_SIZE;

		c.imag((factor.imag() * y) + -hFCT);

		for (int x = 0; x < BMP_SIZE; x++) {
			c.real(factor.real() * x + -hFCT);
			res = inSet(c, k);
			if (res) {
				int n_res = res % 255;
				if (res < (ITERATIONS >> 1)) res = RGB(n_res << 2, n_res << 3, n_res << 4);
				else res = RGB(n_res << 4, n_res << 2, n_res << 5);
			}
			bits[pos++] = res;
		}
	}
	bmp.saveBitmap("./julia2.bmp");
}

int julia2::inSet(std::complex<long double> z, std::complex<long double> c) {
	long double dist;//, three = 3.0;
	for (int ec = 0; ec < ITERATIONS; ec++) {
		z = z * z; z = z + c;
		dist = (z.imag() * z.imag()) + (z.real() * z.real());
		if (dist > 3) return(ec);
	}
	return 0;
}
