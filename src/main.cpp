#include <cmath>

#include "camera.h"
#include "dielectric.h"
#include "hittableObjectsList.h"
#include "lambertian.h"
#include "metal.h"
#include "sphere.h"
#include "vec3utilities.h"

auto main() -> int
{
	// World
	HittableObjectsList world_;

	const auto grounMat_  = std::make_shared<Lambertian>(Color(0.8, 0.8, 0.0));
	const auto centeMat_  = std::make_shared<Lambertian>(Color(0.1, 0.2, 0.5));
	const auto leftMat_   = std::make_shared<Dielectric>(1.50);
	const auto bubbleMat_ = std::make_shared<Dielectric>(1.00 / 1.50); // air / water
	const auto rightMat_  = std::make_shared<Metal>(Color(0.8, 0.6, 0.2), 0.7);

	world_.add(std::make_shared<Sphere>(Point3(0.0, -100.5, -1.0), 100.0, grounMat_));
	world_.add(std::make_shared<Sphere>(Point3(0.0, 0.0, -1.2), 0.5, centeMat_));
	world_.add(std::make_shared<Sphere>(Point3(-1.0, 0.0, -1.0), 0.5, leftMat_));
	world_.add(std::make_shared<Sphere>(Point3(-1.0, 0.0, -1.0), 0.4, bubbleMat_));
	world_.add(std::make_shared<Sphere>(Point3(1.0, 0.0, -1.0), 0.5, rightMat_));

	Camera camera_{};
	camera_.setAspectRatio(16.0 / 9.0);
	camera_.setImageWidth(854); // 480p
	camera_.setSamplesPerPixel(20);
	camera_.setMaxDepthRay(10);

	camera_.render(world_);
}