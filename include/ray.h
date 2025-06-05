#pragma once

#include "vec3.h"
#include "vec3utilities.h"

class Ray
{
  public:
	explicit Ray();
	explicit Ray(const Point3 &origin, const Vec3 &direction);

	auto origin() const -> const Point3 &;
	auto direction() const -> const Vec3 &;

	auto at(double t) const -> Point3;

  private:
	Point3 m_origin;
	Vec3   m_direction;
};