#include <cmath>
#include <iostream>

#include "colorUtilities.h"
#include "hitpoint.h"
#include "hittable.h"
#include "hittableObjectsList.h"
#include "ray.h"
#include "sphere.h"
#include "utilityFunctions.h"
#include "vec3.h"
#include "vec3utilities.h"

auto rayColor(const Ray &ray, const Hittable &world) -> Color
{
	HitPoint hitpoint_;
	if (world.isHit(ray, Interval(0, INFINITY_C), hitpoint_))
		return 0.5 * (hitpoint_.m_normal + Color(1, 1, 1));

	const auto unitDirection_ = unit(ray.direction()); //[-1< y < 1]?
	const auto a_             = 0.5 * (unitDirection_.y() + 1.0);
	return (1.0 - a_) * Color(1.0, 1.0, 1.0) + a_ * Color(0.5, 0.7, 1.0);
}

auto render(const std::uint32_t        imageWidth,
            const std::uint32_t        imageHeight,
            const Vec3                &pixel0,
            const Vec3                &deltaX,
            const Vec3                &deltaY,
            const Vec3                &cameraCenter,
            const HittableObjectsList &world) -> void
{
	std::cout << "P3\n"
	          << imageWidth << ' ' << imageHeight << "\n255\n";

	for (size_t j = 0; j < imageHeight; j++)
	{
		for (size_t i = 0; i < imageWidth; i++)
		{
			auto       pixelCenter_  = pixel0 + (deltaX * i + deltaY * j);
			auto       rayDirection_ = pixelCenter_ - cameraCenter;
			const auto ray_          = Ray{cameraCenter, rayDirection_};

			auto pixelColor_ = rayColor(ray_, world);
			writeColor(std::cout, pixelColor_);
		}
	}
}

int main()
{
	// Image
	constexpr auto          aspectRatio_ = 16.0 / 9.0;
	constexpr std::uint32_t imageWidth_  = 1920;
	constexpr std::uint32_t tmpImHeight_ = static_cast<std::uint32_t>(imageWidth_ / aspectRatio_);
	constexpr std::uint32_t imageHeight_ = tmpImHeight_ > 1 ? tmpImHeight_ : 1;

	// World
	HittableObjectsList world_;
	world_.add(std::make_shared<Sphere>(Point3{0, 0, -1}, 0.5));
	world_.add(std::make_shared<Sphere>(Point3{0, -100.5, -1}, 100));

	// Camera
	constexpr auto focalLength_    = 1.0;
	constexpr auto viewportHeight_ = 2.0;
	constexpr auto viewportWidth_  = viewportHeight_ * (static_cast<double>(imageWidth_) / imageHeight_);
	const auto     cameraCenter_   = Point3{0, 0, 0};

	const auto viewportVectorX_ = Vec3{viewportWidth_, 0, 0};
	const auto viewportVectorY_ = Vec3{0, -viewportHeight_, 0};

	const auto pixelDeltaX_ = viewportVectorX_ / imageWidth_;
	const auto pixelDeltaY_ = viewportVectorY_ / imageHeight_;

	const auto viewportUpperLeft_ = cameraCenter_ - Vec3(0, 0, focalLength_) - (viewportVectorX_ / 2) - (viewportVectorY_ / 2);
	const auto viewportPixel00_   = viewportUpperLeft_ + (pixelDeltaX_ + pixelDeltaY_) * 0.5;

	render(imageWidth_, imageHeight_, viewportPixel00_, pixelDeltaX_, pixelDeltaY_, cameraCenter_, world_);
}