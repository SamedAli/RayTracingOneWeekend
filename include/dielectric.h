#pragma once

#include "material.h"

class Dielectric : public Material
{
  public:
	explicit Dielectric(double refractionIndex) noexcept;

	[[nodiscard]] auto scatter(const Ray &rayIn, const Hitpoint &hitpoint, Color &attenuation, Ray &scattered) const -> bool override;

  private:
	double m_refractionIndex;
};