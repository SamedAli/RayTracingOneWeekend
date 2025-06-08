#include "sphere.h"

#include <cmath>

Sphere::Sphere(const Point3 &center, double radius, std::shared_ptr<Material> material) : m_material(std::move(material)), m_center(center), m_radius(std::fmax(0, radius))
{
}

auto Sphere::isHit(const Ray &ray, Interval rayT, Hitpoint &hitpoint) const -> bool
{
	const auto oc_ = m_center - ray.origin();

	const auto a_ = ray.direction().lengthSquared();
	const auto h_ = dot(ray.direction(), oc_);
	const auto c_ = oc_.lengthSquared() - (m_radius * m_radius);

	const auto discriminant_ = (h_ * h_) - (a_ * c_);

	if (discriminant_ < 0)
	{
		return false;
	}

	const auto sqrtd_ = std::sqrt(discriminant_);

	// Find nearest root in acceptable range.
	auto root_ = (h_ - sqrtd_) / a_;
	if (!rayT.surrounds(root_))
	{
		root_ = (h_ + sqrtd_) / a_;
		if (!rayT.surrounds(root_))
		{
			return false;
		}
	}

	hitpoint.setTVal(root_);
	hitpoint.setPoint(ray.at(hitpoint.getTValue()));
	const auto outwardsNormal_ = (hitpoint.getPoint() - m_center) / m_radius;
	hitpoint.setFaceNormal(ray, outwardsNormal_);
	hitpoint.setMaterial(m_material);

	return true;
}
