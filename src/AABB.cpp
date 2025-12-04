//
// Created by Arpad on 12/4/2025.
//

#include "Aabb.h"

AABB::AABB()
{

}
AABB::AABB(const Vector& min, const Vector& max) : Min(min), Max(max)
{

}
AABB::AABB(float minX, float minY, float minZ, float maxX, float maxY, float maxZ) : Min(minX, minY, minZ), Max(maxX, maxY, maxZ)
{

}

Vector AABB::size() const
{
    return Max-Min;
}