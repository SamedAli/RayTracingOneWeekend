#include "hitpoint.h"

auto HitPoint::setFaceNormal(const Ray &ray, const Vec3 &outwardsNormal) -> void
{
	// NOTE: OutwardsNormal should be a unit vector!
	m_frontFaced = dot(ray.direction(), outwardsNormal) < 0;
	m_normal     = m_frontFaced ? outwardsNormal : -outwardsNormal;
}

auto HitPoint::getPoint() const -> const Point3 &
{
	return m_point;
};

auto HitPoint::getNormal() const -> const Vec3 &
{
	return m_normal;
}

auto HitPoint::getTValue() const -> double
{
	return m_t;
}

auto HitPoint::isFrontFaced() const -> bool
{
	return m_frontFaced;
}

auto HitPoint::setPoint(const Point3 &point) -> void
{
	m_point = point;
}
auto HitPoint::setTVal(double tVal) -> void
{
	m_t = tVal;
}