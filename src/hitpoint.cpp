#include "hitpoint.h"

auto Hitpoint::setFaceNormal(const Ray &ray, const Vec3 &outwardsNormal) -> void
{
	// NOTE: OutwardsNormal should be a unit vector!
	m_frontFaced = dot(ray.direction(), outwardsNormal) < 0;
	m_normal     = m_frontFaced ? outwardsNormal : -outwardsNormal;
}

auto Hitpoint::getPoint() const -> const Point3 &
{
	return m_point;
};

auto Hitpoint::getNormal() const -> const Vec3 &
{
	return m_normal;
}

auto Hitpoint::getTValue() const -> double
{
	return m_t;
}

auto Hitpoint::isFrontFaced() const -> bool
{
	return m_frontFaced;
}

auto Hitpoint::setPoint(const Point3 &point) -> void
{
	m_point = point;
}
auto Hitpoint::setTVal(double tVal) -> void
{
	m_t = tVal;
}

auto Hitpoint::setMaterial(std::shared_ptr<Material> material) -> void
{
	m_material = std::move(material);
}

auto Hitpoint::getMaterial() const -> std::shared_ptr<Material>
{
	return m_material;
}