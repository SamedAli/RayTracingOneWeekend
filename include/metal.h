#pragma once

#include "material.h"

class Metal : public Material
{
  public:
	explicit Metal(const Color &color, double fuzz) noexcept;

	[[nodiscard]] auto scatter(const Ray &rayIn, const Hitpoint &hitpoint, Color &attenuation, Ray &scattered) const -> bool override;

  private:
	Color  m_albedo;
	double m_fuzz;
};