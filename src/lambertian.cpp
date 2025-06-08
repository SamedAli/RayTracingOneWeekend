#include "lambertian.h"

Lambertian::Lambertian(const Color &albedo) noexcept : m_albedo(albedo)
{
}

[[nodiscard]] auto Lambertian::scatter([[maybe_unused]] const Ray &rayIn, const Hitpoint &hitpoint, Color &attenuation, Ray &scattered) const -> bool
{
	auto scatterDirection_ = hitpoint.getNormal() + randomUnitVector();

	if (scatterDirection_.isNearZero())
	{
		scatterDirection_ = hitpoint.getNormal();
	}

	scattered   = Ray(hitpoint.getPoint(), scatterDirection_);
	attenuation = m_albedo;
	return true;
}
