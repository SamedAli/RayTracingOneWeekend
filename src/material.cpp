#include "material.h"

auto Material::scatter([[maybe_unused]] const Ray &ray, [[maybe_unused]] const Hitpoint &hitpoint, [[maybe_unused]] Color &attenuation, [[maybe_unused]] Ray &scattered) const -> bool
{
	return false;
}
