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
	auto setSamplesPerPixel(std::uint32_t nofSamples) -> void;

  private:
	auto                      initialize() -> void;
	[[nodiscard]] auto        getRay(std::uint32_t xCoord, std::uint32_t yCoord) const -> Ray;
	[[nodiscard]] static auto sampleSquare() -> Vec3;
	[[nodiscard]] static auto rayColor(const Ray &ray, const Hittable &world) -> Color;

	Vec3          m_pixel0;
	Vec3          m_deltaX;
	Vec3          m_deltaY;
	Vec3          m_cameraCenter;
	double        m_aspectRatio        = 0;
	double        m_pixelSampleScale   = 0; // For averaging accumalated pixel colors.
	std::uint32_t m_imageWidth         = 0;
	std::uint32_t m_imageHeight        = 0;
	std::uint32_t m_nofSamplesPerPixel = 10;
};