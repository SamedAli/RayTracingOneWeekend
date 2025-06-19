#include "dielectric.h"

#include "utilityFunctions.h"

Dielectric::Dielectric(double refractionIndex) noexcept : m_refractionIndex(refractionIndex)
{}

auto Dielectric::scatter(const Ray &rayIn, const Hitpoint &hitpoint, Color &attenuation, Ray &scattered) const -> bool
{
	attenuation          = Color(1.0, 1.0, 1.0);
	const double refIdx_ = hitpoint.isFrontFaced() ? (1.0 / m_refractionIndex) : m_refractionIndex;

	const auto unitDirection_ = unit(rayIn.direction());

	const auto cosTheta_ = std::fmin(dot(-unitDirection_, hitpoint.getNormal()), 1.0);
	const auto sinTheta_ = std::sqrt(1 - (cosTheta_ * cosTheta_));

	const bool cannotRefract = (refIdx_ * sinTheta_ > 1.0);

	Vec3 directionRefractionOrReflection_;

	if (cannotRefract || reflectance(cosTheta_, refIdx_) > randomDouble())
	{
		directionRefractionOrReflection_ = reflect(unitDirection_, hitpoint.getNormal());
	}
	else
	{
		directionRefractionOrReflection_ = refract(unitDirection_, hitpoint.getNormal(), refIdx_);
	}

	scattered = Ray(hitpoint.getPoint(), directionRefractionOrReflection_);

	return true;
}

auto Dielectric::reflectance(double cos, double refractionIndex) -> double
{
	// Schlick's approximation for reflectance.
	auto r0_ = (1 - refractionIndex) / (1 + refractionIndex);
	r0_ *= r0_;
	return (r0_ + ((1 - r0_) * std::pow((1 - cos), 5)));
}
