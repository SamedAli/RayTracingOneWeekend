#pragma once

#include "hitpoint.h"
#include "interval.h"
#include "ray.h"

class Hittable
{
  public:
	Hittable()          = default;
	virtual ~Hittable() = default;

	Hittable(const Hittable &) = default;
	Hittable(Hittable &&)      = default;

	auto operator=(const Hittable &) -> Hittable & = default;
	auto operator=(Hittable &&) -> Hittable &      = default;

	virtual auto isHit(const Ray &ray, Interval rayT, Hitpoint &hitpoint) const -> bool = 0;
};