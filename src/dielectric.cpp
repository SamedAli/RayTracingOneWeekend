#include "dielectric.h"

Dielectric::Dielectric(double refractionIndex) noexcept : m_refractionIndex(refractionIndex)
{}

auto Dielectric::scatter(const Ray &rayIn, const Hitpoint &hitpoint, Color &attenuation, Ray &scattered) const -> bool
{
	attenuation          = Color(1.0, 1.0, 1.0);
	const double refIdx_ = hitpoint.isFrontFaced() ? (1.0 / m_refractionIndex) : m_refractionIndex;

	const auto unitDirection_ = unit(rayIn.direction());
	const auto refracted_     = refract(unitDirection_, hitpoint.getNormal(), refIdx_);

	scattered = Ray(hitpoint.getPoint(), refracted_);

	return true;
}
