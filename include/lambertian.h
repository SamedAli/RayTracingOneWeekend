#pragma once

#include "material.h"

class Lambertian : public Material
{
  public:
	explicit Lambertian(const Color &albedo) noexcept;

	[[nodiscard]] auto scatter(const Ray &rayIn, const Hitpoint &hitpoint, Color &attenuation, Ray &scattered) const -> bool override;

  private:
	Color m_albedo;
};