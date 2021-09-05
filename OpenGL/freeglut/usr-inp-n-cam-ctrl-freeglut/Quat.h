#ifndef Quat_h
#define Quat_h

#include "Vec3.h"
#include <cmath>

template<typename T> 
class Quat 
{ 
public: 
    Quat()                           : m_qx(T(0)),     m_qy(T(0)),     m_qz(T(0)),     m_qw(T(0)) {}

    Quat(Vec3<T> const& axis, T angle) {
        setRotation(axis, angle);
    }

    Quat(T qx, T qy, T qz, T qw)     : m_qx(qx),       m_qy(qy),       m_qz(qz),       m_qw(qw)   {} 
        
    T qw() const { return m_qw; }
    T qx() const { return m_qx; }
    T qy() const { return m_qy; }
    T qz() const { return m_qz; }

    T qw2() const { return m_qw * m_qw; }
    T qx2() const { return m_qx * m_qx; }
    T qy2() const { return m_qy * m_qy; }
    T qz2() const { return m_qz * m_qz; }

	/**@brief Return the length squared of the quaternion */
	T length2() const
	{
		return dot(*this);
	}

	/**@brief Return the dot product between this quaternion and another
   * @param q The other quaternion */
	T dot(const Quat<T>& q) const
	{
		return m_qx * q.qx() +
			   m_qy * q.qy() +
			   m_qz * q.qz() +
			   m_qw * q.qw();
	}

	/**@brief Set the rotation using axis angle notation
   * @param axis The axis around which to rotate
   * @param angle The magnitude of the rotation in Radians */
	void setRotation(Vec3<T> const& axis, T _angle)
	{
		T d = axis.length();
		assert(d != T(0.0));
		T s = sinf(_angle * T(0.5)) / d;
		setValue(axis.x() * s, axis.y() * s, axis.z() * s,
				 cosf(_angle * T(0.5)));
	}

	void setValue(T _x, T _y, T _z, T _w)
	{
		m_qx = _x;
		m_qy = _y;
		m_qz = _z;
		m_qw = _w;
	}

private:
    T m_qw,/* + i */m_qx,/* + j */m_qy,/* + k */m_qz; 
}; 
 
typedef Quat<float> Quatf; 

#endif