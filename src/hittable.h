#pragma once

#include "hitpoint.h"
#include "interval.h"
#include "ray.h"

class Hittable
{
  public:
	virtual ~Hittable() = default;

	virtual auto isHit(const Ray &ray, Interval rayT, HitPoint &hitpoint) const -> bool = 0;
};