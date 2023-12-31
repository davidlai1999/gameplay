#include "Base.h"
#include "Vector4.h"
namespace gameplay
{
Vector4::Vector4()
{
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
    w = 0.0f;
}

Vector4::Vector4(float x, float y, float z, float w)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

Vector4::Vector4(const float* src)
{
    set(src);
}

Vector4::Vector4(const Vector4& p1, const Vector4& p2)
{
    set(p1, p2);
}

Vector4::Vector4(const Vector4& copy)
{
    set(copy);
}

Vector4 Vector4::fromColor(unsigned int color)
{
    float components[4];
    int componentIndex = 0;
    for (int i = 3; i >= 0; --i)
    {
        int component = (color >> i*8) & 0x000000ff;

        components[componentIndex++] = static_cast<float>(component) / 255.0f;
    }

    Vector4 value(components);
    return value;
}

Vector4::~Vector4()
{
}

void Vector4::slow() {
    cout << x << endl ;
    cout << y << endl ;
    cout << z << endl ;
    cout << w << endl ;
}

float Vector4::getx() {
    return x;
}
float Vector4::gety() {
    return y;
}
float Vector4::getz() {
    return z;
}
float Vector4::getw() {
    return w;
}

const Vector4& Vector4::zero()
{
    static Vector4 value(0.0f, 0.0f, 0.0f, 0.0f);
    return value;
}

const Vector4& Vector4::one()
{
    static Vector4 value(1.0f, 1.0f, 1.0f, 1.0f);
    return value;
}

const Vector4& Vector4::unitX()
{
    static Vector4 value(1.0f, 0.0f, 0.0f, 0.0f);
    return value;
}

const Vector4& Vector4::unitY()
{
    static Vector4 value(0.0f, 1.0f, 0.0f, 0.0f);
    return value;
}

const Vector4& Vector4::unitZ()
{
    static Vector4 value(0.0f, 0.0f, 1.0f, 0.0f);
    return value;
}

const Vector4& Vector4::unitW()
{
    static Vector4 value(0.0f, 0.0f, 0.0f, 1.0f);
    return value;
}

bool Vector4::isZero() const
{
    return x == 0.0f && y == 0.0f && z == 0.0f && w == 0.0f;
}

bool Vector4::isOne() const
{
    return x == 1.0f && y == 1.0f && z == 1.0f && w == 1.0f;
}

float Vector4::angle(const Vector4& v1, const Vector4& v2)
{
    float dx = v1.w * v2.x - v1.x * v2.w - v1.y * v2.z + v1.z * v2.y;
    float dy = v1.w * v2.y - v1.y * v2.w - v1.z * v2.x + v1.x * v2.z;
    float dz = v1.w * v2.z - v1.z * v2.w - v1.x * v2.y + v1.y * v2.x;

    return atan2f(sqrt(dx * dx + dy * dy + dz * dz) + MATH_FLOAT_SMALL, dot(v1, v2));
}

void Vector4::add(const Vector& v)
{
    Vector4* v1 = (Vector4*)&v;
    x += v1->x;
    y += v1->y;
    z += v1->z;
    w += v1->w;
}

void Vector4::add(const Vector& v1, const Vector& v2, Vector* dst)
{
    GP_ASSERT(dst);
    Vector4* nv1 = (Vector4*)&v1;
    Vector4* nv2 = (Vector4*)&v2;
    Vector4* temp = (Vector4*)dst;

    temp->x = nv1->x + nv2->x;
    temp->y = nv1->y + nv2->y;
    temp->z = nv1->z + nv2->z;
    temp->w = nv1->w + nv2->w;

    dst = temp;
}

void Vector4::clamp(const Vector& min, const Vector& max)
{
    Vector4* tmin = (Vector4*)&min;
    Vector4* tmax = (Vector4*)&max;
    GP_ASSERT(!(tmin->x > tmax->x || tmin->y > tmax->y || tmin->z > tmax->z || tmin->w > tmax->w));

    // Clamp the x value.
    if (x < tmin->x)
        x = tmin->x;
    if (x > tmax->x)
        x = tmax->x;

    // Clamp the y value.
    if (y < tmin->y)
        y = tmin->y;
    if (y > tmax->y)
        y = tmax->y;

    // Clamp the z value.
    if (z < tmin->z)
        z = tmin->z;
    if (z > tmax->z)
        z = tmax->z;

    // Clamp the z value.
    if (w < tmin->w)
        w = tmin->w;
    if (w > tmax->w)
        w = tmax->w;
}

void Vector4::clamp(const Vector& v, const Vector& min, const Vector& max, Vector* dst)
{
    Vector4* tmin = (Vector4*)&min;
    Vector4* tmax = (Vector4*)&max;
    Vector4* v1 = (Vector4*)&v;
    Vector4* temp = (Vector4*)dst;

    GP_ASSERT(temp);
    GP_ASSERT(!(tmin->x > tmax->x || tmin->y > tmax->y || tmin->z > tmax->z || tmin->w > tmax->w));

    // Clamp the x value.
    temp->x = v1->x;
    if (temp->x < tmin->x)
        temp->x = tmin->x;
    if (temp->x > tmax->x)
        temp->x = tmax->x;

    // Clamp the y value.
    temp->y = v1->y;
    if (temp->y < tmin->y)
        temp->y = tmin->y;
    if (temp->y > tmax->y)
        temp->y = tmax->y;

    // Clamp the z value.
    temp->z = v1->z;
    if (temp->z < tmin->z)
        temp->z = tmin->z;
    if (temp->z > tmax->z)
        temp->z = tmax->z;

    // Clamp the w value.
    temp->w = v1->w;
    if (temp->w < tmin->w)
        temp->w = tmin->w;
    if (temp->w > tmax->w)
        temp->w = tmax->w;

    dst = temp;
}

float Vector4::distance(const Vector& v) const
{
    Vector4 *v1 = (Vector4*)&v;
    float dx = v1->x - x;
    float dy = v1->y - y;
    float dz = v1->z - z;
    float dw = v1->w - w;

    return sqrt(dx * dx + dy * dy + dz * dz + dw * dw);
}

float Vector4::distanceSquared(const Vector& v) const
{
    Vector4 *v1 = (Vector4*)&v;
    float dx = v1->x - x;
    float dy = v1->y - y;
    float dz = v1->z - z;
    float dw = v1->w - w;

    return (dx * dx + dy * dy + dz * dz + dw * dw);
}

float Vector4::dot(const Vector& v) const
{
    Vector4 *v1 = (Vector4*)&v; 
    return (x * v1->x + y * v1->y + z * v1->z + w * v1->w);
}

float Vector4::dot(const Vector& v1, const Vector& v2)
{
    Vector4 *nv1 = (Vector4*)&v1; 
    Vector4 *nv2 = (Vector4*)&v2; 
    return (nv1->x * nv2->x + nv1->y * nv2->y + nv1->z * nv2->z + nv1->w * nv2->w);
}

float Vector4::length() const
{
    return sqrt(x * x + y * y + z * z + w * w);
}


float Vector4::lengthSquared() const
{
    return (x * x + y * y + z * z + w * w);
}

void Vector4::negate()
{
    x = -x;
    y = -y;
    z = -z;
    w = -w;
}

Vector& Vector4::normalize()
{
    cout << "Vector4::normalize" << endl;
    normalize(this);
    return *this;
}

void Vector4::normalize(Vector* dst) const
{
    Vector4 *temp = (Vector4*)dst;
    GP_ASSERT(temp);

    if (temp != this)
    {
        temp->x = x;
        temp->y = y;
        temp->z = z;
        temp->w = w;
    }

    float n = x * x + y * y + z * z + w * w;
    // Already normalized.
    if (n == 1.0f)
        return;

    n = sqrt(n);
    // Too close to zero.
    if (n < MATH_TOLERANCE)
        return;

    n = 1.0f / n;
    temp->x *= n;
    temp->y *= n;
    temp->z *= n;
    temp->w *= n;
}

void Vector4::scale(float scalar)
{
    x *= scalar;
    y *= scalar;
    z *= scalar;
    w *= scalar;
}

void Vector4::set(float x, float y, float z, float w)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

void Vector4::set(const float* array)
{
    GP_ASSERT(array);

    x = array[0];
    y = array[1];
    z = array[2];
    w = array[3];
}

void Vector4::set(const Vector& v)
{
    Vector4 *v1 = (Vector4*)&v; 
    this->x = v1->x;
    this->y = v1->y;
    this->z = v1->z;
    this->w = v1->w;
}

void Vector4::set(const Vector& p1, const Vector& p2)
{
    Vector4 *v1 = (Vector4*)&p1; 
    Vector4 *v2 = (Vector4*)&p2; 
    x = v2->x - v1->x;
    y = v2->y - v1->y;
    z = v2->z - v1->z;
    w = v2->w - v1->w;
}

void Vector4::subtract(const Vector& v)
{
    Vector4 *v1 = (Vector4*)&v; 
    x -= v1->x;
    y -= v1->y;
    z -= v1->z;
    w -= v1->w;
}

void Vector4::subtract(const Vector& v1, const Vector& v2, Vector* dst)
{
    Vector4 *nv1 = (Vector4*)&v1; 
    Vector4 *nv2 = (Vector4*)&v2; 
    Vector4 *tmp = (Vector4*)dst; 
    GP_ASSERT(tmp);

    tmp->x = nv1->x - nv2->x;
    tmp->y = nv1->y - nv2->y;
    tmp->z = nv1->z - nv2->z;
    tmp->w = nv1->w - nv2->w;

    dst = tmp;
}

}
