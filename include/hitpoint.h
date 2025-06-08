#pragma once

#include "ray.h"
#include "vec3utilities.h"

#include <memory>

class Material;

class Hitpoint
{
  public:
	auto setFaceNormal(const Ray &ray, const Vec3 &outwardsNormal) -> void;

	[[nodiscard]] auto getPoint() const -> const Point3 &;
	[[nodiscard]] auto getNormal() const -> const Vec3 &;
	[[nodiscard]] auto getTValue() const -> double;
	[[nodiscard]] auto isFrontFaced() const -> bool;
	[[nodiscard]] auto getMaterial() const -> std::shared_ptr<Material>; // return by value is safe, unless you know caller won't store. For now safe option altough it doesnt get stored.

	auto setPoint(const Point3 &point) -> void;
	auto setTVal(double tVal) -> void;
	auto setMaterial(std::shared_ptr<Material> material) -> void;

  private:
	std::shared_ptr<Material> m_material;
	Point3                    m_point;
	Vec3                      m_normal;
	double                    m_t;
	bool                      m_frontFaced;
};