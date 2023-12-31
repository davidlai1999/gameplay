#ifndef BOUNDING_H_
#define BOUNDING_H_

#include "Frustum.h"

namespace gameplay
{

class Bounding
{
public:
    virtual bool intersects(const BoundingSphere& sphere) const = 0;
    virtual bool intersects(const BoundingBox& box) const = 0;
    virtual bool intersects(const Frustum& frustum) const = 0;
    virtual float intersects(const Plane& plane) const = 0;
    virtual float intersects(const Ray& ray) const = 0;

    virtual bool isEmpty() const = 0;

    virtual void merge(const BoundingSphere& sphere) = 0;
    virtual void merge(const BoundingBox& box) = 0;

    virtual void set(const BoundingSphere& sphere) = 0;
    virtual void set(const BoundingBox& box) = 0;

    virtual void transform(const Matrix& matrix) = 0;
};
}
#endif