#pragma once

#include "ray.h"
#include "vec3utilities.h"

class HitPoint
{
  public:
	Point3 m_point;
	Vec3   m_normal;
	double m_t;
	bool   m_frontFaced;

	auto setFaceNormal(const Ray &ray, const Vec3 &outwardsNormal) -> void;
};