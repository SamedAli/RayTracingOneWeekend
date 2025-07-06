#include <cmath>

#include "camera.h"
#include "dielectric.h"
#include "hittableObjectsList.h"
#include "lambertian.h"
#include "metal.h"
#include "sphere.h"
#include "utilityFunctions.h"
#include "vec3utilities.h"

auto main() -> int
{
	// World
	HittableObjectsList world_;

	const auto groundMaterial_ = std::make_shared<Lambertian>(Color(0.5, 0.5, 0.5));
	world_.add(std::make_shared<Sphere>(Point3(0, -1000, 0), 1000, groundMaterial_));

	for (int a = -11; a < 11; ++a)
	{
		for (int b = -11; b < 11; b++)
		{
			const auto   chooseMaterial_ = randomDouble();
			const Point3 center_(a + (0.9 * randomDouble()), 0.2, b + (0.9 * randomDouble()));

			if ((center_ - Point3(4, 0.2, 0)).length() > 0.9)
			{
				std::shared_ptr<Material> sphereMaterial_;

				if (chooseMaterial_ < 0.8)
				{
					// Diffuse
					const auto albedo_ = Color::random() * Color::random();
					sphereMaterial_    = std::make_shared<Lambertian>(albedo_);
					world_.add(std::make_shared<Sphere>(center_, 0.2, sphereMaterial_));
				}
				else if (chooseMaterial_ < 0.95)
				{
					// metal
					const auto albedo_ = Color::random(0.5, 1);
					const auto fuzz_   = randomDouble(0, 0.5);
					sphereMaterial_    = std::make_shared<Metal>(albedo_, fuzz_);
					world_.add(std::make_shared<Sphere>(center_, 0.2, sphereMaterial_));
				}
				else
				{
					// glass
					sphereMaterial_ = std::make_shared<Dielectric>(1.5);
					world_.add(std::make_shared<Sphere>(center_, 0.2, sphereMaterial_));
				}
			}
		}
	}

	const auto material1_ = std::make_shared<Dielectric>(1.5);
	world_.add(std::make_shared<Sphere>(Point3(0, 1, 0), 1.0, material1_));

	const auto material2_ = std::make_shared<Lambertian>(Color(.4, .2, .1));
	world_.add(std::make_shared<Sphere>(Point3(-4, 1, 0), 1.0, material2_));

	const auto material3_ = std::make_shared<Metal>(Color(.7, .6, .5), 0.0);
	world_.add(std::make_shared<Sphere>(Point3(4, 1, 0), 1.0, material3_));

	Camera camera_{};
	camera_.setAspectRatio(16.0 / 9.0);
	camera_.setImageWidth(1440);
	camera_.setSamplesPerPixel(10);
	camera_.setMaxDepthRay(5);

	camera_.setVerticalFOV(20);
	camera_.setLookFrom(Point3(13, 2, 3));
	camera_.setLookAt(Point3(0, 0, 0));
	camera_.setVUp(Vec3(0, 1, 0));

	camera_.setFocusAngle(0.6);
	camera_.setFocusDistance(10.0);

	camera_.render(world_);
}