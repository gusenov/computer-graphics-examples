#ifndef Vec3_h
#define Vec3_h

#include <cmath>
#include <cassert>

template<typename T> 
class Vec3 
{ 
public: 
    Vec3()              : m_x(T(0)), m_y(T(0)), m_z(T(0)) {} 
    Vec3(T const& val)  : m_x(val),  m_y(val),  m_z(val)  {} 
    Vec3(T x, T y, T z) : m_x(x),    m_y(y),    m_z(z)    {} 
    
    T getX() const { return m_x; }
    T getY() const { return m_y; }
    T getZ() const { return m_z; }
    
    T x() const { return m_x; }
    T y() const { return m_y; }
    T z() const { return m_z; }
    
    void setValue(T x, T y, T z) {
        m_x = x;
        m_y = y;
        m_z = z;
    }
    
    T length() const {
        return sqrt(length2());
    }
    
    /** Return the length of the vector squared */
	T length2() const {
        return (m_x * m_x) + (m_y * m_y) + (m_z * m_z);
    }

    void normalize() {
        auto len = length();
        m_x /= len;
        m_y /= len;
        m_z /= len;
    }
    
    Vec3<T> cross(Vec3<T> const& other) {
        return Vec3<T>(m_y * other.z() - m_z * other.y(),
                       m_z * other.x() - m_x * other.z(),
                       m_x * other.y() - m_y * other.x());
    }

    Vec3<T> operator+(Vec3<T> const& rhs) const
    {
        return Vec3<T>(m_x + rhs.x(), m_y + rhs.y(), m_z + rhs.z());
    }

    Vec3<T>& operator+=(Vec3<T> const& rhs) {
          m_x += rhs.x();
          m_y += rhs.y();
          m_z += rhs.z();
          return *this;
    }

    Vec3<T> operator-(Vec3<T> const& rhs) const
    {
        return Vec3<T>(m_x - rhs.x(), m_y - rhs.y(), m_z - rhs.z());
    }
    
    T& operator[](int idx) {
        switch (idx) {
            case 0: return m_x;
            case 1: return m_y;
            case 2: return m_z;
        }
        assert(false);
    }
    
private:
    T m_x, m_y, m_z; 
}; 
 
typedef Vec3<float> Vec3f; 

#endif