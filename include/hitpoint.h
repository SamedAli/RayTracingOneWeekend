#pragma once

#include "ray.h"
#include "vec3utilities.h"

class HitPoint
{
  public:
	auto setFaceNormal(const Ray &ray, const Vec3 &outwardsNormal) -> void;

	[[nodiscard]] auto getPoint() const -> const Point3 &;
	[[nodiscard]] auto getNormal() const -> const Vec3 &;
	[[nodiscard]] auto getTValue() const -> double;
	[[nodiscard]] auto isFrontFaced() const -> bool;

	auto setPoint(const Point3 &point) -> void;
	auto setTVal(double tVal) -> void;

  private:
	Point3 m_point;
	Vec3   m_normal;
	double m_t;
	bool   m_frontFaced;
};