#pragma once

#include "hittable.h"

class Sphere : public Hittable
{
  public:
	Sphere(const Point3 &center, double radius);

	auto isHit(const Ray &ray, double rayTmin, double rayTmax, HitPoint &hitpoint) const -> bool override;

  private:
	Point3 m_center;
	double m_radius;
};