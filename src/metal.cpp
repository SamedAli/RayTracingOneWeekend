#include "metal.h"

Metal::Metal(const Color &color) noexcept : m_albedo{color}
{
}

auto Metal::scatter(const Ray &rayIn, const Hitpoint &hitpoint, Color &attenuation, Ray &scattered) const -> bool
{
	const auto reflected_ = reflect(rayIn.direction(), hitpoint.getNormal());
	scattered             = Ray(hitpoint.getPoint(), reflected_);

	attenuation = m_albedo;
	return true;
}
