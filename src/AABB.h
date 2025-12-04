//
// Created by Arpad on 12/4/2025.
//

#ifndef ARAP_VISUALIZER_AABB_H
#define ARAP_VISUALIZER_AABB_H

#include <stdio.h>
#include "vector.h"

class AABB
{
public:
    Vector Min;
    Vector Max;
    AABB();
    AABB(const Vector& min, const Vector& max);
    AABB(float minX, float minY, float minZ, float maxX, float maxY, float maxZ);
    Vector size() const;
};


#endif //ARAP_VISUALIZER_AABB_H