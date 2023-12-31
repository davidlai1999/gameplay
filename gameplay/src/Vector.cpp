#include "Base.h"
#include "Vector.h"

namespace gameplay
{

Vector::Vector()
    : x(0.0f), y(0.0f)
{
}

Vector::Vector(float x, float y)
    : x(x), y(y)
{
}

Vector::Vector(const float* src)
{
    set(src);
}

Vector::Vector(const Vector& p1, const Vector& p2)
{
    set(p1, p2);
}

Vector::Vector(const Vector& copy)
{
    set(copy);
}

Vector::~Vector()
{
}

void Vector::slow() {
    cout << x << endl ;
    cout << y << endl ;
}

float Vector::getx() {
    return x;
}
float Vector::gety() {
    return y;
}
float Vector::getz() {
    return 0;
}
float Vector::getw() {
    return 0;
}

const Vector& Vector::zero()
{
    static Vector value(0.0f, 0.0f);
    return value;
}

const Vector& Vector::one()
{
    static Vector value(1.0f, 1.0f);
    return value;
}

const Vector& Vector::unitX()
{
    static Vector value(1.0f, 0.0f);
    return value;
}

const Vector& Vector::unitY()
{
    static Vector value(0.0f, 1.0f);
    return value;
}

bool Vector::isZero() const
{
    return x == 0.0f && y == 0.0f;
}

bool Vector::isOne() const
{
    return x == 1.0f && y == 1.0f;
}

float Vector::angle(const Vector& v1, const Vector& v2)
{
    return 0;
}

void Vector::add(const Vector& v)
{
    x += v.x;
    y += v.y;
}

void Vector::add(const Vector& v1, const Vector& v2, Vector* dst)
{
    GP_ASSERT(dst);

    dst->x = v1.x + v2.x;
    dst->y = v1.y + v2.y;
}

void Vector::clamp(const Vector& min, const Vector& max)
{
    GP_ASSERT(!(min.x > max.x || min.y > max.y));

    // Clamp the x value.
    if (x < min.x)
        x = min.x;
    if (x > max.x)
        x = max.x;

    // Clamp the y value.
    if (y < min.y)
        y = min.y;
    if (y > max.y)
        y = max.y;
}

void Vector::clamp(const Vector& v, const Vector& min, const Vector& max, Vector* dst)
{
    GP_ASSERT(dst);
    GP_ASSERT(!(min.x > max.x || min.y > max.y));

    // Clamp the x value.
    dst->x = v.x;
    if (dst->x < min.x)
        dst->x = min.x;
    if (dst->x > max.x)
        dst->x = max.x;

    // Clamp the y value.
    dst->y = v.y;
    if (dst->y < min.y)
        dst->y = min.y;
    if (dst->y > max.y)
        dst->y = max.y;
}

float Vector::distance(const Vector& v) const
{
    float dx = v.x - x;
    float dy = v.y - y;

    return sqrt(dx * dx + dy * dy);
}

float Vector::distanceSquared(const Vector& v) const
{
    float dx = v.x - x;
    float dy = v.y - y;

    return (dx * dx + dy * dy);
}

float Vector::dot(const Vector& v) const
{
    return (x * v.x + y * v.y);
}

float Vector::dot(const Vector& v1, const Vector& v2)
{
    return (v1.x * v2.x + v1.y * v2.y);
}

float Vector::length() const
{
    return sqrt(x * x + y * y);
}


float Vector::lengthSquared() const
{
    return (x * x + y * y);
}

void Vector::negate()
{
    x = -x;
    y = -y;
}

Vector& Vector::normalize()
{
    normalize(this);
    return *this;
}

void Vector::normalize(Vector* dst) const
{
    GP_ASSERT(dst);

    if (dst != this)
    {
        dst->x = x;
        dst->y = y;
    }

    float n = x * x + y * y;
    // Already normalized.
    if (n == 1.0f)
        return;

    n = sqrt(n);
    // Too close to zero.
    if (n < MATH_TOLERANCE)
        return;

    n = 1.0f / n;
    dst->x *= n;
    dst->y *= n;
}

void Vector::scale(float scalar)
{
    x *= scalar;
    y *= scalar;
}

void Vector::set(float x, float y)
{
    this->x = x;
    this->y = y;
}

void Vector::set(float x, float y, float z, float w)
{
    set(x, y);
}

void Vector::set(float x, float y, float z)
{
    set(x, y);
}

void Vector::set(const float* array)
{
    GP_ASSERT(array);

    x = array[0];
    y = array[1];
}

void Vector::set(const Vector& v)
{
    this->x = v.x;
    this->y = v.y;
}

void Vector::set(const Vector& p1, const Vector& p2)
{
    x = p2.x - p1.x;
    y = p2.y - p1.y;
}

void Vector::subtract(const Vector& v)
{
    x -= v.x;
    y -= v.y;
}

void Vector::subtract(const Vector& v1, const Vector& v2, Vector* dst)
{
    GP_ASSERT(dst);

    dst->x = v1.x - v2.x;
    dst->y = v1.y - v2.y;
}

}