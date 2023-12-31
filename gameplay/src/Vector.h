#ifndef VECTOR_H_
#define VECTOR_H_

#include "Base.h"

namespace gameplay
{

class Vector
{
public:

    float x;
    float y;


    Vector();
    Vector(float x, float y);
    Vector(const float* array);
    Vector(const Vector& p1, const Vector& p2);
    Vector(const Vector& copy);
    ~Vector();

    virtual void slow();

    virtual float getx();
    virtual float gety();
    virtual float getz();
    virtual float getw();

    /**
     * Returns the zero vector.
     *
     * @return The 3-element vector of 0s.
     */
    static const Vector& zero();

    /**
     * Returns the one vector.
     *
     * @return The 3-element vector of 1s.
     */
    static const Vector& one();

    /**
     * Returns the unit x vector.
     *
     * @return The 4-element unit vector along the x axis.
     */
    static const Vector& unitX();

    /**
     * Returns the unit y vector.
     *
     * @return The 4-element unit vector along the y axis.
     */
    static const Vector& unitY();

    /**
     * Indicates whether this vector contains all zeros.
     *
     * @return true if this vector contains all zeros, false otherwise.
     */
    virtual bool isZero() const;

    /**
     * Indicates whether this vector contains all ones.
     *
     * @return true if this vector contains all ones, false otherwise.
     */
    virtual bool isOne() const;
    
    /**
     * Returns the angle (in radians) between the specified vectors.
     *
     * @param v1 The first vector.
     * @param v2 The second vector.
     * 
     * @return The angle between the two vectors (in radians).
     */
    static float angle(const Vector& v1, const Vector& v2);

    /**
     * Adds the elements of the specified vector to this one.
     *
     * @param v The vector to add.
     */
    virtual void add(const Vector& v);

    /**
     * Adds the specified vectors and stores the result in dst.
     *
     * @param v1 The first vector.
     * @param v2 The second vector.
     * @param dst A vector to store the result in.
     */
    static void add(const Vector& v1, const Vector& v2, Vector* dst);

    /**
     * Clamps this vector within the specified range.
     *
     * @param min The minimum value.
     * @param max The maximum value.
     */
    virtual void clamp(const Vector& min, const Vector& max);

    /**
     * Clamps the specified vector within the specified range and returns it in dst.
     *
     * @param v The vector to clamp.
     * @param min The minimum value.
     * @param max The maximum value.
     * @param dst A vector to store the result in.
     */
    static void clamp(const Vector& v, const Vector& min, const Vector& max, Vector* dst);

    /**
     * Returns the distance between this vector and v.
     *
     * @param v The other vector.
     * 
     * @return The distance between this vector and v.
     * 
     * @see distanceSquared
     */
    virtual float distance(const Vector& v) const;

    /**
     * Returns the squared distance between this vector and v.
     *
     * When it is not necessary to get the exact distance between
     * two vectors (for example, when simply comparing the
     * distance between different vectors), it is advised to use
     * this method instead of distance.
     *
     * @param v The other vector.
     * 
     * @return The squared distance between this vector and v.
     * 
     * @see distance
     */
    virtual float distanceSquared(const Vector& v) const;

    /**
     * Returns the dot product of this vector and the specified vector.
     *
     * @param v The vector to compute the dot product with.
     * 
     * @return The dot product.
     */
    virtual float dot(const Vector& v) const;

    /**
     * Returns the dot product between the specified vectors.
     *
     * @param v1 The first vector.
     * @param v2 The second vector.
     * 
     * @return The dot product between the vectors.
     */
    static float dot(const Vector& v1, const Vector& v2);

    /**
     * Computes the length of this vector.
     *
     * @return The length of the vector.
     * 
     * @see lengthSquared
     */
    virtual float length() const;

    /**
     * Returns the squared length of this vector.
     *
     * When it is not necessary to get the exact length of a
     * vector (for example, when simply comparing the lengths of
     * different vectors), it is advised to use this method
     * instead of length.
     *
     * @return The squared length of the vector.
     * 
     * @see length
     */
    virtual float lengthSquared() const;

    /**
     * Negates this vector.
     */

    virtual void negate();

    /**
     * Normalizes this vector.
     *
     * This method normalizes this Vector3 so that it is of
     * unit length (in other words, the length of the vector
     * after calling this method will be 1.0f). If the vector
     * already has unit length or if the length of the vector
     * is zero, this method does nothing.
     * 
     * @return This vector, after the normalization occurs.
     */
    virtual Vector& normalize();

    /**
     * Normalizes this vector and stores the result in dst.
     *
     * If the vector already has unit length or if the length
     * of the vector is zero, this method simply copies the
     * current vector into dst.
     *
     * @param dst The destination vector.
     */
    virtual void normalize(Vector* dst) const;

    /**
     * Scales all elements of this vector by the specified value.
     *
     * @param scalar The scalar value.
     */
    virtual void scale(float scalar);

    /**
     * Sets the elements of this vector to the specified values.
     *
     * @param x The new x coordinate.
     * @param y The new y coordinate.
     */
    virtual void set(float x, float y);
    virtual void set(float x, float y, float z);
    virtual void set(float x, float y, float z, float w);

    /**
     * Sets the elements of this vector from the values in the specified array.
     *
     * @param array An array containing the elements of the vector in the order x, y, z, w.
     */
    virtual void set(const float* array);

    /**
     * Sets the elements of this vector to those in the specified vector.
     *
     * @param v The vector to copy.
     */
    virtual void set(const Vector& v);

    /**
     * Sets this vector to the directional vector between the specified points.
     * 
     * @param p1 The first point.
     * @param p2 The second point.
     */
    virtual void set(const Vector& p1, const Vector& p2);

    /**
     * Subtracts this vector and the specified vector as (this - v)
     * and stores the result in this vector.
     *
     * @param v The vector to subtract.
     */
    virtual void subtract(const Vector& v);

    /**
     * Subtracts the specified vectors and stores the result in dst.
     * The resulting vector is computed as (v1 - v2).
     *
     * @param v1 The first vector.
     * @param v2 The second vector.
     * @param dst The destination vector.
     */
    static void subtract(const Vector& v1, const Vector& v2, Vector* dst);

    /**
     * Calculates the sum of this vector with the given vector.
     * 
     * Note: this does not modify this vector.
     * 
     * @param v The vector to add.
     * @return The vector sum.
     */
    virtual inline const Vector operator+(const Vector& v) const;

    /**
     * Adds the given vector to this vector.
     * 
     * @param v The vector to add.
     * @return This vector, after the addition occurs.
     */
    inline Vector& operator+=(const Vector& v);

    /**
     * Calculates the difference of this vector with the given vector.
     * 
     * Note: this does not modify this vector.
     * 
     * @param v The vector to subtract.
     * @return The vector difference.
     */
    inline const Vector operator-(const Vector& v) const;

    /**
     * Subtracts the given vector from this vector.
     * 
     * @param v The vector to subtract.
     * @return This vector, after the subtraction occurs.
     */
    inline Vector& operator-=(const Vector& v);

    /**
     * Calculates the negation of this vector.
     * 
     * Note: this does not modify this vector.
     * 
     * @return The negation of this vector.
     */
    inline const Vector operator-() const;

    /**
     * Calculates the scalar product of this vector with the given value.
     * 
     * Note: this does not modify this vector.
     * 
     * @param x The value to scale by.
     * @return The scaled vector.
     */
    inline const Vector operator*(float x) const;

    /**
     * Scales this vector by the given value.
     * 
     * @param x The value to scale by.
     * @return This vector, after the scale occurs.
     */
    inline Vector& operator*=(float x);
    
    /**
     * Returns the components of this vector divided by the given constant
     *
     * Note: this does not modify this vector.
     *
     * @param x the constant to divide this vector with
     * @return a smaller vector
     */
    inline const Vector operator/(float x) const;

    /**
     * Determines if this vector is less than the given vector.
     * 
     * @param v The vector to compare against.
     * 
     * @return True if this vector is less than the given vector, false otherwise.
     */
    inline bool operator<(const Vector& v) const;

    /**
     * Determines if this vector is equal to the given vector.
     * 
     * @param v The vector to compare against.
     * 
     * @return True if this vector is equal to the given vector, false otherwise.
     */
    inline bool operator==(const Vector& v) const;

    /**
     * Determines if this vector is not equal to the given vector.
     * 
     * @param v The vector to compare against.
     * 
     * @return True if this vector is not equal to the given vector, false otherwise.
     */
    inline bool operator!=(const Vector& v) const;

};

/**
 * Calculates the scalar product of the given vector with the given value.
 * 
 * @param x The value to scale by.
 * @param v The vector to scale.
 * @return The scaled vector.
 */
inline const Vector operator*(float x, const Vector& v);

#include "Vector.inl"

}

#endif