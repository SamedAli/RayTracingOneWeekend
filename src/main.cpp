#include <cmath>

#include "camera.h"
#include "hittableObjectsList.h"
#include "sphere.h"
#include "vec3utilities.h"

auto main() -> int
{
	// World
	HittableObjectsList world_;
	world_.add(std::make_shared<Sphere>(Point3{0, 0, -1}, 0.5));
	world_.add(std::make_shared<Sphere>(Point3{0, -100.5, -1}, 100));

	Camera camera_{};
	camera_.setAspectRatio(16.0 / 9.0);
	camera_.setImageWidth(1920);
	camera_.setSamplesPerPixel(3);
	camera_.setMaxDepthRay(10);

	camera_.render(world_);
}