#pragma once

#include "vec3.h"
#include "vec3utilities.h"

class Ray
{
  public:
	explicit Ray() = default;
	explicit Ray(const Point3 &origin, const Vec3 &direction);

	[[nodiscard]] auto origin() const -> const Point3 &;
	[[nodiscard]] auto direction() const -> const Vec3 &;

	[[nodiscard]] auto at(double tVal) const -> Point3;

  private:
	Point3 m_origin;
	Vec3   m_direction;
};