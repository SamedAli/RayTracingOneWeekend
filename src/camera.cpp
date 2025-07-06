#include "camera.h"

#include "material.h"
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
			Color pixelColor_{0, 0, 0};
			for (size_t sample = 0; sample < m_nofSamplesPerPixel; ++sample)
			{
				const Ray ray_ = getRay(i, j);
				pixelColor_ += rayColor(ray_, m_maxDepth, world);
			}
			writeColor(std::cout, m_pixelSampleScale * pixelColor_);
		}
	}
}

auto Camera::initialize() -> void
{
	const auto tmpImHeight_ = static_cast<std::uint32_t>(m_imageWidth / m_aspectRatio);
	m_imageHeight           = tmpImHeight_ > 1 ? tmpImHeight_ : 1;

	m_pixelSampleScale = 1.0 / m_nofSamplesPerPixel;
	m_cameraCenter     = m_lookFrom;

	// Determine viewport dimensions.
	// const auto focalLength_    = (m_lookFrom - m_lookAt).length();
	const auto theta_          = degreesToRadians(m_vfov);
	const auto h_              = std::tan(theta_ / 2);
	const auto viewportHeight_ = 2.0 * h_ * m_focusDistance;
	const auto viewportWidth_  = viewportHeight_ * (static_cast<double>(m_imageWidth) / m_imageHeight);

	// Calculate the u,v,w unit basis vectors for the camera coordinate frame.
	m_w = unit(m_lookFrom - m_lookAt);
	m_u = unit(cross(m_vUp, m_w));
	m_v = cross(m_w, m_u);

	// Calculate the vectors across the horizontal and down the vertical viewport edges.
	const auto viewportVectorX_ = viewportWidth_ * m_u;
	const auto viewportVectorY_ = viewportHeight_ * -m_v;

	m_deltaX = viewportVectorX_ / m_imageWidth;
	m_deltaY = viewportVectorY_ / m_imageHeight;

	const auto viewportUpperLeft_ = m_cameraCenter - (m_focusDistance * m_w) - (viewportVectorX_ / 2) - (viewportVectorY_ / 2);
	m_pixel0                      = viewportUpperLeft_ + (m_deltaX + m_deltaY) * 0.5;

	const auto defocusRadius_ = m_focusDistance * std::tan(degreesToRadians(m_defocusAngle / 2));
	m_defocusDiskU            = m_u * defocusRadius_;
	m_defocusDiskV            = m_v * defocusRadius_;
}

auto Camera::rayColor(const Ray &ray, std::uint32_t depth, const Hittable &world) -> Color
{
	if (depth <= 0)
	{
		return Color{0, 0, 0};
	}

	Hitpoint hitpoint_;
	if (world.isHit(ray, Interval(0.001, INFINITY_C), hitpoint_))
	{
		Ray   scattered_;
		Color attenuation_;

		if (hitpoint_.getMaterial()->scatter(ray, hitpoint_, attenuation_, scattered_))
		{
			return attenuation_ * rayColor(scattered_, depth - 1, world);
		}
		return Color(0, 0, 0);
	}

	const auto unitDirection_ = unit(ray.direction()); //[-1< y < 1]?
	const auto scalar_        = 0.5 * (unitDirection_.y() + 1.0);
	return (1.0 - scalar_) * Color(1.0, 1.0, 1.0) + scalar_ * Color(0.5, 0.7, 1.0);
}

auto Camera::defocusDiskSample() const -> Vec3
{
	const auto p_ = randomUnitDisk();
	return (m_cameraCenter + (p_[0] * m_defocusDiskU) + (p_[1] * m_defocusDiskV));
}

auto Camera::getRay(std::uint32_t xCoord, std::uint32_t yCoord) const -> Ray
{
	const auto offset_      = sampleSquare();
	const auto pixelSample_ = m_pixel0 + ((xCoord + offset_.x()) * m_deltaX) + ((yCoord + offset_.y()) * m_deltaY);

	const auto rOrigin_ = (m_defocusAngle <= 0) ? m_cameraCenter : defocusDiskSample();
	const auto rDir_    = pixelSample_ - rOrigin_;

	return Ray{rOrigin_, rDir_};
}

auto Camera::sampleSquare() -> Vec3
{
	// Returns the vector to a random point in the [-.5,-.5]-[+.5,+.5] unit square.
	return Vec3(randomDouble() - 0.5, randomDouble() - 0.5, 0);
}

auto Camera::setSamplesPerPixel(std::uint32_t nofSamples) -> void
{
	m_nofSamplesPerPixel = nofSamples;
}

auto Camera::setMaxDepthRay(std::uint32_t maxDepth) -> void
{
	m_maxDepth = maxDepth;
}

auto Camera::setVerticalFOV(double vfov) -> void
{
	m_vfov = vfov;
}

auto Camera::setLookFrom(const Point3 &lookFrom) -> void
{
	m_lookFrom = lookFrom;
}
auto Camera::setLookAt(const Point3 &lookAt) -> void
{
	m_lookAt = lookAt;
}
auto Camera::setVUp(const Vec3 &vUp) -> void
{
	m_vUp = vUp;
}

auto Camera::setFocusAngle(double angle) -> void
{
	m_defocusAngle = angle;
}
auto Camera::setFocusDistance(double distance) -> void
{
	m_focusDistance = distance;
}