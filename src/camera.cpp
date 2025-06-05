#include "camera.h"

#include "utilityFunctions.h"

#include <iostream>

auto Camera::setImageWidth(std::uint32_t width) -> void
{
	m_imageWidth = width;
}

auto Camera::setAspectRatio(double aspectRatio) -> void
{
	m_aspectRatio = aspectRatio;
}

auto Camera::render(const Hittable &world) -> void
{
	initialize();

	std::cout << "P3\n"
	          << m_imageWidth << ' ' << m_imageHeight << "\n255\n";

	for (std::uint32_t j = 0; j < m_imageHeight; j++)
	{
		for (std::uint32_t i = 0; i < m_imageWidth; i++)
		{
			auto       pixelCenter_  = m_pixel0 + (m_deltaX * i + m_deltaY * j);
			auto       rayDirection_ = pixelCenter_ - m_cameraCenter;
			const auto ray_          = Ray{m_cameraCenter, rayDirection_};

			auto pixelColor_ = rayColor(ray_, world);
			writeColor(std::cout, pixelColor_);
		}
	}
}

auto Camera::initialize() -> void
{
	auto tmpImHeight_ = static_cast<std::uint32_t>(m_imageWidth / m_aspectRatio);
	m_imageHeight     = tmpImHeight_ > 1 ? tmpImHeight_ : 1;

	m_cameraCenter = Point3{0, 0, 0};

	// Determine viewport dimensions.
	const auto focalLength_    = 1.0;
	const auto viewportHeight_ = 2.0;
	const auto viewportWidth_  = viewportHeight_ * (static_cast<double>(m_imageWidth) / m_imageHeight);

	// Calculate the vectors across the horizontal and down the vertical viewport edges.
	const auto viewportVectorX_ = Vec3{viewportWidth_, 0, 0};
	const auto viewportVectorY_ = Vec3{0, -viewportHeight_, 0};

	m_deltaX = viewportVectorX_ / m_imageWidth;
	m_deltaY = viewportVectorY_ / m_imageHeight;

	const auto viewportUpperLeft_ = m_cameraCenter - Vec3(0, 0, focalLength_) - (viewportVectorX_ / 2) - (viewportVectorY_ / 2);
	m_pixel0                      = viewportUpperLeft_ + (m_deltaX + m_deltaY) * 0.5;
}

auto Camera::rayColor(const Ray &ray, const Hittable &world) -> Color
{
	HitPoint hitpoint_;
	if (world.isHit(ray, Interval(0, INFINITY_C), hitpoint_))
	{
		return 0.5 * (hitpoint_.m_normal + Color(1, 1, 1));
	}

	const auto unitDirection_ = unit(ray.direction()); //[-1< y < 1]?
	const auto scalar_        = 0.5 * (unitDirection_.y() + 1.0);
	return (1.0 - scalar_) * Color(1.0, 1.0, 1.0) + scalar_ * Color(0.5, 0.7, 1.0);
}