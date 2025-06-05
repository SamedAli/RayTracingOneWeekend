#include "ray.h"

Ray::Ray(const Point3 &origin, const Vec3 &direction) : m_origin{origin}, m_direction{direction}
{}

auto Ray::origin() const -> const Point3 &
{
	return m_origin;
}

auto Ray::direction() const -> const Vec3 &
{
	return m_direction;
}

auto Ray::at(double tVal) const -> Point3
{
	return m_origin + m_direction * tVal;
}