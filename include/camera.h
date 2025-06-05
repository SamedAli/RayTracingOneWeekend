#pragma once

#include "colorUtilities.h"
#include "hittable.h"

/*
Camera is responsible for two important jobs.
    1. Construct and dispatch rays into the world.
    2. Use the results of these rays to construct the rendered image.
*/
class Camera
{
  public:
	explicit Camera() = default;

	auto render(const Hittable &world) -> void;

	auto setImageWidth(std::uint32_t width) -> void;
	auto setAspectRatio(double aspectRatio) -> void;

  private:
	auto                      initialize() -> void;
	[[nodiscard]] static auto rayColor(const Ray &ray, const Hittable &world) -> Color;

	double        m_aspectRatio = 0;
	std::uint32_t m_imageWidth  = 0;

	std::uint32_t m_imageHeight = 0;
	Vec3          m_pixel0;
	Vec3          m_deltaX;
	Vec3          m_deltaY;
	Vec3          m_cameraCenter;
};