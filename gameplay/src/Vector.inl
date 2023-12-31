#include "Vector.h"

namespace gameplay
{

inline const Vector Vector::operator+(const Vector& v) const
{
    Vector result(*this);
    result.add(v);
    return result;
}

inline Vector& Vector::operator+=(const Vector& v)
{
    add(v);
    return *this;
}

inline const Vector Vector::operator-(const Vector& v) const
{
    Vector result(*this);
    result.subtract(v);
    return result;
}

inline Vector& Vector::operator-=(const Vector& v)
{
    subtract(v);
    return *this;
}

inline const Vector Vector::operator-() const
{
    Vector result(*this);
    result.negate();
    return result;
}

inline const Vector Vector::operator*(float x) const
{
    Vector result(*this);
    result.scale(x);
    return result;
}

inline Vector& Vector::operator*=(float x)
{
    scale(x);
    return *this;
}

inline const Vector Vector::operator/(const float x) const
{
    return Vector(this->x / x, this->y / x);
}

inline bool Vector::operator<(const Vector& v) const
{
    if (x == v.x)
    {
        return y < v.y;
    }
    return x < v.x;
}

inline bool Vector::operator==(const Vector& v) const
{
    return x==v.x && y==v.y;
}

inline bool Vector::operator!=(const Vector& v) const
{
    return x!=v.x || y!=v.y;
}

inline const Vector operator*(float x, const Vector& v)
{
    Vector result(v);
    result.scale(x);
    return result;
}

}
