#ifndef Matrix3x3_h
#define Matrix3x3_h

#include <cmath>
#include <utility>
#include "Quat.h"

template<typename T> 
class Matrix3x3 
{ 
public: 
    
    Matrix3x3(): m00(T(0)), m01(T(0)), m02(T(0)),
                 m10(T(0)), m11(T(0)), m12(T(0)),
                 m20(T(0)), m21(T(0)), m22(T(0))
    {} 

	Matrix3x3(T xx, T xy, T xz,
			  T yx, T yy, T yz,
			  T zx, T zy, T zz)
	{
		setValue(xx, xy, xz,
				 yx, yy, yz,
				 zx, zy, zz);
	}

    explicit Matrix3x3(Quat<T> const& q) {
        setRotation(q);
    }

    Matrix3x3<T> operator*(Matrix3x3<T> const& rhs) const
    {
        Matrix3x3<T> product;

        int r1=3, c1=3, r2=3, c2=3, i, j, k;
        for(i=0; i<r1; ++i)
        for(j=0; j<c2; ++j) {
           product.at(i, j) = 0;
        }
        for(i=0; i<r1; ++i)
        for(j=0; j<c2; ++j)
        for(k=0; k<c1; ++k) {
           product.at(i, j)+=at(i,k)*rhs.at(k,j);
        }

        return product;
    }

    Vec3<T> operator*(Vec3<T> const& rhs) const
    {
        Vec3<T> result;
        
        result.setValue(
            m00 * rhs.x() + m01 * rhs.y() + m02 * rhs.z(),
            m10 * rhs.x() + m11 * rhs.y() + m12 * rhs.z(),
            m20 * rhs.x() + m21 * rhs.y() + m22 * rhs.z()
        );
        
        return result;
    }
    
    const T& at(int r, int c) const {
        switch (r) {
            case 0: switch (c) { case 0: return m00; case 1: return m01; case 2: return m02; default: assert(false); } break;
            case 1: switch (c) { case 0: return m10; case 1: return m11; case 2: return m12; default: assert(false); } break;
            case 2: switch (c) { case 0: return m20; case 1: return m21; case 2: return m22; default: assert(false); } break;
            default: assert(false);
        }
    }
    
    T& at(int r, int c) {
        // Applying Scott Meyer's to-const-and-back-again pattern for avoiding
        // code duplication. Implement non-const version by forwarding to the
        // const version.
        return const_cast<T&>(std::as_const(*this).at(r, c)); 
    }

	void setValue(T xx, const T xy, T xz,
				  T yx, const T yy, T yz,
				  T zx, const T zy, T zz)
	{
        m00 = xx; m01 = xy; m02 = xz;
        m10 = yx; m11 = yy; m12 = yz;
        m20 = zx; m21 = zy; m22 = zz;
	}

	void setRotation(Quat<T> const& q)
	{
		T d = q.length2();
		assert(d != T(0.0));
		T s = T(2.0) / d;

		T xs = q.qx() * s, ys = q.qy() * s, zs = q.qz() * s;
		T wx = q.qw() * xs, wy = q.qw() * ys, wz = q.qw() * zs;
		T xx = q.qx() * xs, xy = q.qx() * ys, xz = q.qx() * zs;
		T yy = q.qy() * ys, yz = q.qy() * zs, zz = q.qz() * zs;
		setValue(
			T(1.0) - (yy + zz), xy - wz, xz + wy,
			xy + wz, T(1.0) - (xx + zz), yz - wx,
			xz - wy, yz + wx, T(1.0) - (xx + yy));
	}

private:
    T m00, m01, m02,
      m10, m11, m12,
      m20, m21, m22;
}; 
 
typedef Matrix3x3<float> Matrix3x3f; 

#endif