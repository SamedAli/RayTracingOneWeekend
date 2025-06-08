#pragma once

#include "hittable.h"

class Sphere : public Hittable
{
  public:
	Sphere(const Point3 &center, double radius, std::shared_ptr<Material> material);

	auto isHit(const Ray &ray, Interval rayT, Hitpoint &hitpoint) const -> bool override;

  private:
	std::shared_ptr<Material> m_material;
	Point3                    m_center;
	double                    m_radius;
};