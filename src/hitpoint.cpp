#include "hitpoint.h"

auto HitPoint::setFaceNormal(const Ray &ray, const Vec3 &outwardsNormal) -> void
{
	// NOTE: OutwardsNormal should be a unit vector!
	m_frontFaced = dot(ray.direction(), outwardsNormal) < 0;
	m_normal     = m_frontFaced ? outwardsNormal : -outwardsNormal;
}