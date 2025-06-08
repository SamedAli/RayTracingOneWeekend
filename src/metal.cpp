#include "metal.h"

Metal::Metal(const Color &color, double fuzz) noexcept : m_albedo{color}, m_fuzz{fuzz < 1 ? fuzz : 1}
{
}

auto Metal::scatter(const Ray &rayIn, const Hitpoint &hitpoint, Color &attenuation, Ray &scattered) const -> bool
{
	auto reflected_ = reflect(rayIn.direction(), hitpoint.getNormal());
	reflected_      = unit(reflected_) + (m_fuzz * randomUnitVector());
	scattered       = Ray(hitpoint.getPoint(), reflected_);

	attenuation = m_albedo;
	return (dot(scattered.direction(), hitpoint.getNormal()) > 0);
}
