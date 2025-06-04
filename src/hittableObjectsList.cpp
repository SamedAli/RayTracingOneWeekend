#include "hittableObjectsList.h"

HittableObjectsList::HittableObjectsList(std::shared_ptr<Hittable> obj)
{
	add(obj);
}

auto HittableObjectsList::clear() -> void
{
	m_objects.clear();
}

auto HittableObjectsList::add(std::shared_ptr<Hittable> obj) -> void
{
	m_objects.push_back(obj);
}

auto HittableObjectsList::isHit(const Ray &ray, double rayTmin, double rayTmax, HitPoint &hitpoint) const -> bool
{
	HitPoint tmpHitPoint_;
	auto     anythingHit     = false;
	auto     closestHitSoFar = rayTmax;

	for (const auto &obj : m_objects)
	{
		if (obj->isHit(ray, rayTmin, closestHitSoFar, tmpHitPoint_))
		{
			anythingHit     = true;
			closestHitSoFar = tmpHitPoint_.m_t;
			hitpoint        = tmpHitPoint_;
		}
	}

	return anythingHit;
}