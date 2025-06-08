#pragma once

#include "colorUtilities.h"
#include "hittable.h"

class Material
{
  public:
	Material() noexcept                 = default;
	virtual ~Material() noexcept        = default;
	Material(const Material &) noexcept = default;
	Material(Material &&) noexcept      = default;

	auto operator=(const Material &) noexcept -> Material & = default;
	auto operator=(Material &&) noexcept -> Material &      = default;

	[[nodiscard]] virtual auto scatter(const Ray &rayIn, const Hitpoint &hitpoint, Color &attenuation, Ray &scattered) const -> bool;

  private:
};