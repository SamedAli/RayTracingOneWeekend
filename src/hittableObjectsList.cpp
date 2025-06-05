#include "hittableObjectsList.h"

HittableObjectsList::HittableObjectsList(const std::shared_ptr<Hittable> &obj)
{
	add(obj);
}

auto HittableObjectsList::clear() -> void
{
	m_objects.clear();
}

auto HittableObjectsList::add(const std::shared_ptr<Hittable> &obj) -> void
{
	m_objects.push_back(obj);
}

auto HittableObjectsList::isHit(const Ray &ray, Interval rayT, HitPoint &hitpoint) const -> bool
{
	HitPoint tmpHitPoint_;
	auto     anythingHit     = false;
	auto     closestHitSoFar = rayT.getMax();

	for (const auto &obj : m_objects)
	{
		if (obj->isHit(ray, Interval(rayT.getMin(), closestHitSoFar), tmpHitPoint_))
		{
			anythingHit     = true;
			closestHitSoFar = tmpHitPoint_.getTValue();
			hitpoint        = tmpHitPoint_;
		}
	}

	return anythingHit;
}